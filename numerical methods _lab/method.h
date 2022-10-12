#pragma once

#include <vector>
#include <cmath>

#include "main_window.h"

namespace method {
	class task {
	public:
		task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: h(h_), x_min(x_min_), x_max(x_max_) {}

		virtual ~task() {}

		void clear_data() {
			dots.clear();
			dots.resize(0);
		};

		virtual double problem(double, double) = 0;

		std::vector<double> find_solution() {
			double e_u = problem(0,0), e_v = 1, e_x = problem(0,0);
			dots.push_back(e_v);
			size_t counter = 0;
			double k_1, k_2, k_3, k_4;

			for (double x_curr = x_min; x_curr <= x_max; x_curr += h) {
				k_1 = problem(dots[counter], 0);
				k_2 = problem(dots[counter] + h / 2 * k_1, 0);
				k_3 = problem(dots[counter] + h / 2 * k_2, 0);
				k_4 = problem(dots[counter] + h * k_3, 0);
				++counter;
				dots.push_back(dots[counter - 1] + h / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4));
			}
			return dots;
		}

	protected:
		std::vector<double> dots;
		double h;
		double x_min;
		double x_max;
	};

	class test_task : public task {
	public:

		test_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}

		double problem(double u, double x) override {
			return (-1) * 5 / 2 * u;
		}

		std::vector<double> find_true_solution() {
			double x_curr = x_min;
			double u = 0;
			while (x_curr <= x_max) {
				u = std::pow(std::exp(1.0), -5 / 2 * x_curr);
				true_dots.push_back(u);
				x_curr += h;
			}
			return true_dots;
		};

	private:
		std::vector<double> true_dots;
	};

	class first_task : public task {
	public:

		first_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}

		double problem(double u, double x) override {
			return log(x + 1) / (std::pow(x, 2) + 1) * std::pow(u, 2) + u - std::pow(u, 3) * sin(10 * x);
		}
	};

	class second_task : public task {

		second_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}

		double problem(double u, double x) override {
		}
	};
}