#pragma once

#include <vector>
#include <cmath>
namespace method {
	class task {
	public:
		task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: h(h_), x_min(x_min_), x_max(x_max_) {}

		virtual ~task() {}

		void clear_data() {
			h = 0;
			dots.clear();
			dots.resize(0);
		};
		virtual double problem(double) = 0;
		virtual std::vector<double> find_true_solution() = 0;
		virtual std::vector<double> find_solution() = 0;

	private:
		std::vector<double> dots;
		double h;
		double x_min;
		double x_max;
	};

	class test_task : public task {
	public:

		test_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: h(h_), x_min(x_min_), x_max(x_max_) {}

		double problem(double u) override {
			return (-1) * 5 / 2 * u;
		}

		std::vector<double> find_true_solution() override {
			double x_curr = x_min;
			dots.reserve(10);
			double u = 0;
			while (x_curr <= x_max) {
				u = std::pow(std::exp(1.0), -5 / 2 * x_curr);
				dots.push_back(u);
				x_curr += h;
			}
			return dots;
		};

		std::vector<double> find_solution() override { 
			double e_u = problem(0), e_v = 1, e_x = problem(0);
			double x_curr = x_min;
			clear_data();
			dots.resize(12);
			dots[0] = e_v;
			size_t counter = 0;
			double k_1, k_2, k_3, k_4;
			while (x_curr <= x_max) {
				k_1 = problem(dots[counter]);
				k_2 = problem(dots[counter] + h / 2 * k_1);
				k_3 = problem(dots[counter] + h / 2 * k_2);
				k_4 = problem(dots[counter] + h * k_3);
				++counter;
				dots[counter] = dots[counter - 1] + h / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4);
				x_curr += h;
			}

			return dots; 
		};

	private:
		std::vector<double> dots;
		double h;
		double x_min;
		double x_max;
	};

	class first_task : public task {
		std::vector<double> find_solution() override { return std::vector<double>(10, 0); };
	};

	class second_task : public task {
		std::vector<double> find_solution() override { return std::vector<double>(10, 0); };
	};

	/*void task::clear_data() {
		h = 0;
		dots.clear();
		dots.resize(0);
	}*/
}