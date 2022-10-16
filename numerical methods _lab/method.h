#pragma once

#include <vector>
#include <cmath>
#include <map>


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
		std::vector<size_t> divisions;
		std::vector<size_t> doublings;
		std::vector<double> local_err;
		std::vector<double> v_upd;
		std::vector<double> difference;
		std::vector<double> current_h;
	} m_vars;

	class task {
	public:
		task() = default;

		virtual ~task() {}

		virtual double problem(double, double) = 0;

		void clear_data() {
			dots.clear();

			true_dots.clear();

			if (in_cond.control_local_err)
				half_step_d.clear();

			solution.clear();
		};

		void initialize(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1) {
			step = in_cond.h;
			x_min = in_cond.x_min;
			x_max = in_cond.x_max;
		}

		void half_step(double e_u) {
			double e_v = e_u;

			half_step_d.push_back(e_v);
			dots.push_back(e_v);

			m_vars.v_upd.push_back(e_v);
			m_vars.difference.push_back(0);
			m_vars.current_h.push_back(step);
			m_vars.doublings.push_back(0);
			m_vars.divisions.push_back(0);

			size_t counter = 0, counter_h = 0;
			size_t div = 0, doub = 0;

			double k_1, k_2, k_3, k_4;
			double k_1_h, k_2_h, k_3_h, k_4_h;

			m_vars.local_err.push_back(0);
			double s;

			double x_curr = x_min;
			double x_curr_h = x_min;

			solution[x_curr] = e_v;

			while (x_curr <= x_max) {

				if (counter_h % 2 == 0) {
					x_curr += step;
					k_1 = problem(dots[counter], 0);
					k_2 = problem(dots[counter] + step / 2 * k_1, 0);
					k_3 = problem(dots[counter] + step / 2 * k_2, 0);
					k_4 = problem(dots[counter] + step * k_3, 0);
					++counter;
					dots.push_back(dots[counter - 1] + step / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4));
				}

				x_curr_h += step / 2;
				k_1_h = problem(half_step_d[counter_h], 0);
				k_2_h = problem(half_step_d[counter_h] + step / 4 * k_1_h, 0);
				k_3_h = problem(half_step_d[counter_h] + step / 4 * k_2_h, 0);
				k_4_h = problem(half_step_d[counter_h] + step / 2 * k_3_h, 0);
				++counter_h;
				half_step_d.push_back(half_step_d[counter_h - 1] + step / 12 * (k_1_h + 2 * k_2_h + 2 * k_3_h + k_4_h));

				if (half_step_d.size() % 2 != 0 && half_step_d.size() != 1) {
					s = (half_step_d[counter_h] - dots[counter]) / 15;
					if (std::abs(s) >= in_cond.epsilon / 15 && std::abs(s) <= in_cond.epsilon) {

						m_vars.local_err.push_back(s * 16);
						m_vars.difference.push_back(dots[counter] - half_step_d[counter_h]);
						m_vars.v_upd.push_back(dots[counter] + m_vars.local_err[counter]);
						m_vars.current_h.push_back(step);

						counter_h = 0;
						half_step_d.clear();
						half_step_d.push_back(dots[counter]);
						solution[x_curr] = dots[counter];
					}
					if (std::abs(s) < (in_cond.epsilon / 32)) {
						step *= 2;

						m_vars.doublings.push_back(++doub);
						m_vars.local_err.push_back(s * 16);
						m_vars.difference.push_back(dots[counter] - half_step_d[counter_h]);
						m_vars.v_upd.push_back(dots[counter] + m_vars.local_err[counter]);
						m_vars.current_h.push_back(step);

						counter_h = 0;
						half_step_d.clear();
						half_step_d.push_back(dots[counter]);
						solution[x_curr] = dots[counter];
					}
					if (std::abs(s) > in_cond.epsilon) {
						x_curr -= step;
						x_curr_h -= step/2;
						step /= 2;

						m_vars.current_h.push_back(step);
						m_vars.divisions.push_back(++div);

						--counter;
						dots.pop_back();
						half_step_d.clear();
						half_step_d.push_back(dots[counter]);
						counter_h = 0;
					}
				}

			}
		}

		std::map<double,double> find_solution(double e_u, bool control) {

			if (control)
				half_step(e_u);
			else {
				double e_v = e_u;
				dots.push_back(e_v);
				size_t counter = 0;
				double k_1, k_2, k_3, k_4;

				for (double x_curr = x_min; x_curr <= x_max; x_curr += step) {
					solution[x_curr] = dots[counter];
					k_1 = problem(dots[counter], 0);
					k_2 = problem(dots[counter] + step / 2 * k_1, 0);
					k_3 = problem(dots[counter] + step / 2 * k_2, 0);
					k_4 = problem(dots[counter] + step * k_3, 0);
					++counter;
					dots.push_back(dots[counter - 1] + step / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4));
				}
			}
			return solution;
		}

		std::map<double, double> find_true_solution(double c_) {
			double x_curr = x_min;
			double u = 0;
			double c = c_;
			m_vars.current_h.push_back(in_cond.h);
			size_t index = 0;
			while (x_curr <= x_max) {
				u = c / std::pow(std::exp(1.0), 5 / 2 * x_curr);
				true_dots.push_back(u);
				true_solution[x_curr] = true_dots[index];
				x_curr += step;
				m_vars.current_h.push_back(x_curr);
				++index;
			}
			return true_solution;
		};

	private:
		std::vector<double> true_dots;
		std::vector<double> half_step_d;
		std::map<double, double> solution;
		std::map<double, double> true_solution;
		std::vector<double> dots;
		double step;
		double x_min;
		double x_max;
	};

	class test_task : public task {
	public:
		test_task() = default;

		double problem(double u, double x = 0) override {
			return (-1) * 5 / 2 * u;
		}

		~test_task(){}
	};

	class first_task : public task {
	public:
		first_task() = default;

		double problem(double u, double x) override {
			return log(x + 1) / (std::pow(x, 2) + 1) * std::pow(u, 2) + u - std::pow(u, 3) * sin(10 * x);
		}

		std::vector<double> find_true_solution() = delete;

		~first_task(){}
	};

	class second_task : public task {
		public:

		second_task() = default;

		double problem(double u, double x) override {
			return 0;
		}

		std::vector<double> find_true_solution() = delete;

		~second_task(){}
	};
}