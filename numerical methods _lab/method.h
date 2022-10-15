#pragma once

#include <vector>
#include <cmath>

namespace method {

	struct initial_conditions {
		 double e_u;
		 double e_u_neg;
		 double epsilon;
		 double h;
		 double x_min;
		 double x_max;
		 int	max_steps;
		 bool   control_local_err;
	} in_cond;

	struct method_vars {
		size_t divisions;
		size_t doublings;
		std::vector<double> local_err;
		std::vector<double> v_upd;
		std::vector<double> difference;
		std::vector<double> current_h;
	} m_vars;

	class task {
	public:
		/*task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: h(h_), x_min(x_min_), x_max(x_max_) {}*/

		task() = default;
		virtual ~task() {}

		virtual double problem(double, double) = 0;

		void clear_data() {
			dots.clear();
			dots.resize(0);
			true_dots.clear();
			true_dots.resize(0);
		};

		//void initialize(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1) {
		//	//h = h_;
		//	x_min = x_min_;
		//	x_max = x_max_;
		//}

		void half_step(double e_u, double h_) {
			double e_v = e_u, e_x = e_u;
			//std::vector<double> half_step_d;

			half_step_d.push_back(e_v);
			dots.push_back(e_v);
			m_vars.v_upd.push_back(e_v);
			m_vars.difference.push_back(0);
			m_vars.current_h.push_back(h_);

			size_t counter = 0, counter_h = 0;

			double k_1, k_2, k_3, k_4;
			double k_1_h, k_2_h, k_3_h, k_4_h;

			m_vars.local_err.push_back(0);
			double s;

			for (double x_curr = /*x_min*/in_cond.x_min, x_curr_h = /*x_min*/in_cond.x_min; x_curr <= /*x_max*/in_cond.x_max && x_curr_h <= /*x_max*/in_cond.x_max; /*x_curr += h*/x_curr += in_cond.h, x_curr_h += h_) {
				if (counter_h % 2 == 0) {
					k_1 = problem(dots[counter],0);
					k_2 = problem(dots[counter] + h_ / 2 * k_1, 0);
					k_3 = problem(dots[counter] + h_ / 2 * k_2, 0);
					k_4 = problem(dots[counter] + h_ * k_3, 0);
					++counter;
					dots.push_back(dots[counter - 1] + h_ / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4));
				}

				k_1_h = problem(half_step_d[counter_h], 0);
				k_2_h = problem(half_step_d[counter_h] + h_ / 4 * k_1_h, 0);
				k_3_h = problem(half_step_d[counter_h] + h_ / 4 * k_2_h, 0);
				k_4_h = problem(half_step_d[counter_h] + h_ / 2 * k_3_h, 0);
				++counter_h;
				half_step_d.push_back(half_step_d[counter_h - 1] + h_ / 12 * (k_1_h + 2 * k_2_h + 2 * k_3_h + k_4_h));

				if (counter_h == counter * 2) {
					s = (half_step_d[counter_h] - dots[counter]) / (std::pow(2, 4) - 1);
					if (std::abs(s) >= (in_cond.epsilon / std::pow(2, 5))
						&& std::abs(s) <= in_cond.epsilon) {
						m_vars.local_err.push_back(s * std::pow(2, 4));
						m_vars.difference.push_back(dots[counter] - half_step_d[counter_h]);
						m_vars.v_upd.push_back(dots[counter] + m_vars.local_err[counter]);
						m_vars.current_h.push_back(h_);
					}
					if (std::abs(s) < (in_cond.epsilon / std::pow(2, 5))) {
						h_ *= 2;
						m_vars.doublings += 1;
						m_vars.local_err.push_back(s * std::pow(2, 4));
						m_vars.difference.push_back(dots[counter] - half_step_d[counter_h]);
						m_vars.v_upd.push_back(dots[counter] + m_vars.local_err[counter]);
						m_vars.current_h.push_back(h_);
					}
					if (std::abs(s) > in_cond.epsilon) {
						h_ /= 2;
						m_vars.current_h.push_back(h_);
						m_vars.divisions += 1;
						counter = 0;
						counter_h = 0;
						x_curr = /*x_min*/in_cond.x_min;
						x_curr_h = /*x_min*/in_cond.x_min;
						dots.clear();
						half_step_d.clear();
						half_step_d.push_back(e_v);
						dots.push_back(e_v);
					}
				}

			}
			//return dots;
		}

		std::vector<double> find_solution(double e_u, double h_, bool control) {

			if (control)
				half_step(e_u, h_);
			else {
				double e_v = e_u, e_x = e_u;
				dots.push_back(e_v);
				size_t counter = 0;
				double k_1, k_2, k_3, k_4;

				for (double x_curr = /*x_min*/in_cond.x_min; x_curr <= /*x_max*/in_cond.x_max; /*x_curr += h*/x_curr += in_cond.h) {
					k_1 = problem(dots[counter], 0);
					k_2 = problem(dots[counter] + h_ / 2 * k_1, 0);
					k_3 = problem(dots[counter] + h_ / 2 * k_2, 0);
					k_4 = problem(dots[counter] + h_ * k_3, 0);
					++counter;
					dots.push_back(dots[counter - 1] + h_ / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4));
				}
			}
			return dots;
		}

		std::vector<double> find_true_solution(double c_) {
			double x_curr = /*x_min*/in_cond.x_min;
			double u = 0;
			double c = c_;
			while (x_curr <= /*x_max*/in_cond.x_max) {
				u = c / std::pow(std::exp(1.0), 5 / 2 * x_curr);
				true_dots.push_back(u);
				//x_curr += h;
				x_curr += in_cond.h;
			}
			return true_dots;
		};

	protected:
		std::vector<double> dots;
		//double h;
		//double x_min;
		//double x_max;
	private:
		std::vector<double> true_dots;
		std::vector<double> half_step_d;
	};

	class test_task : public task {
	public:

		/*test_task(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1)
			: task(h_, x_min_, x_max_) {}*/

		test_task() = default;

		double problem(double u, double x = 0) override {
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