#pragma once

#include <vector>
#include <cmath>

namespace method {

	struct initial_conditions {
		 double e_u;
		 double epsilon;
		 double h;
		 double x_min;
		 double x_max;
		 int	   max_steps;
		 bool   control_local_err;
	} in_cond;

	class task {
	public:
		/*task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: h(h_), x_min(x_min_), x_max(x_max_) {}*/

		task() = default;

		virtual ~task() {}

		void clear_data() {
			dots.clear();
			dots.resize(0);
			true_dots.clear();
			true_dots.resize(0);
		};

		void initialize(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1) {
			h = h_;
			x_min = x_min_;
			x_max = x_max_;
		}

		virtual double problem(double, double) = 0;

		std::vector<double> find_solution() {
			double e_u = in_cond.e_u, e_v = e_u, e_x = e_u;
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

		std::vector<double> find_true_solution() {
			double x_curr = x_min;
			double u = 0;
			double c = in_cond.e_u;
			while (x_curr <= x_max) {
				u = c / std::pow(std::exp(1.0), 5 / 2 * x_curr);
				true_dots.push_back(u);
				x_curr += h;
			}
			return true_dots;
		};

	protected:
		std::vector<double> dots;
		double h;
		double x_min;
		double x_max;
	private:
		std::vector<double> true_dots;
	};

	class test_task : public task {
	public:

		/*test_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}*/

		test_task() = default;

		double problem(double u, double x) override {
			return (-1) * 5 / 2 * u;
		}

		/*std::vector<double> find_true_solution() {
			double x_curr = x_min;
			double u = 0;
			while (x_curr <= x_max) {
				u = std::pow(std::exp(1.0), -5 / 2 * x_curr);
				true_dots.push_back(u);
				x_curr += h;
			}
			return true_dots;
		};*/

		~test_task(){}

	/*private:
		std::vector<double> true_dots;*/
	};

	class first_task : public task {
	public:

		/*first_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}*/

		first_task() = default;

		double problem(double u, double x) override {
			return log(x + 1) / (std::pow(x, 2) + 1) * std::pow(u, 2) + u - std::pow(u, 3) * sin(10 * x);
		}

		std::vector<double> find_true_solution() = delete;

		~first_task(){}
	};

	class second_task : public task {
		public:

		/*second_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}*/

		second_task() = default;

		double problem(double u, double x) override {
			return 0;
		}

		std::vector<double> find_true_solution() = delete;

		~second_task(){}
	};
}