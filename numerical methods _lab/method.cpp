#include "main_window.h"

method::initial_conditions in_cond;
method::out out_data;

void method::task::clear_data() {
	dots.clear();
	dots.resize(0);

	true_dots.clear();
	true_dots.resize(0);

	if (in_cond.control_local_err) {
		half_step_d.clear();
		half_step_d.resize(0);
	}

	solution.clear();
	true_solution.clear();
	out_data.logs.clear();

}

void method::task::initialize(double h_, double x_min_, double x_max_) {
	step = in_cond.h;
	x_min = in_cond.x_min;
	x_max = in_cond.x_max;
}

void method::task::log_data(double x_curr, double h_curr, double y_num,
		double y_num_h, double diff_curr, double l_err_curr, double y_upd,
		size_t div_count, size_t doub_count, double abs_diff) {
	out_data.logs.push_back(std::make_tuple(x_curr, h_curr, y_num, y_num_h, diff_curr, l_err_curr, y_upd, div_count, doub_count, abs_diff));
}

void method::task::half_step(double e_u) {

	double e_v = e_u;

	half_step_d.push_back(e_v);
	dots.push_back(e_v);

	size_t counter = 0, counter_h = 0;
	size_t index = 0;

	double k_1, k_2, k_3, k_4;
	double k_1_h, k_2_h, k_3_h, k_4_h;

	double s = 0;

	double x_curr = x_min;
	double x_curr_h = x_min;
	double curr_step = 0;

	solution[x_curr] = e_v;

	while (x_curr <= x_max + in_cond.border_control) {
		size_t div = 0, doub = 0;
		curr_step = step;
		if (counter_h % 2 == 0) {
			//x_curr += step;
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
			if (std::fabs(s) >= in_cond.epsilon / 32 && std::abs(s) <= in_cond.epsilon) {
				x_curr += step; // 
				counter_h = 0;
				//half_step_d.clear();
				//half_step_d.push_back(dots[counter]);
				solution[x_curr] = dots[counter];

				log_data(
					//index,
					x_curr,
					curr_step,
					solution[x_curr],
					half_step_d.back(),
					solution[x_curr] - half_step_d.back(),
					16 * s,
					solution[x_curr] + 16 * s,
					div,
					doub,
					std::fabs(true_solution[index] - solution[x_curr])
				);
				++index;

				half_step_d.clear();
				half_step_d.push_back(dots[counter]);	
			}
			if (std::fabs(s) < (in_cond.epsilon / 32)) {
				x_curr += step; // 
				step *= 2;
				doub = 1;

				counter_h = 0;
				//half_step_d.clear();
				//half_step_d.push_back(dots[counter]);
				solution[x_curr] = dots[counter];

				log_data(
					//index,
					x_curr,
					curr_step,
					solution[x_curr],
					half_step_d.back(),
					solution[x_curr] - half_step_d.back(),
					16 * s,
					solution[x_curr] + 16 * s,
					div,
					doub,
					std::fabs(true_solution[index] - solution[x_curr])
				);
				++index;

				half_step_d.clear(); // 
				half_step_d.push_back(dots[counter]); //
			}
			if (std::fabs(s) > in_cond.epsilon) {
				//x_curr -= step; // 
				x_curr_h -= step / 2;
				step /= 2;
				div = 1;

				--counter;
				dots.pop_back();
				half_step_d.clear();
				half_step_d.push_back(dots[counter]);
				counter_h = 0;
			}
		}
	}
}

std::map<double, double> method::task::find_solution(double e_u, bool control){
	if (control)
		half_step(e_u);
	else {
		double e_v = e_u;
		dots.push_back(e_v);
		size_t counter = 0;
		size_t index = 0;
		double k_1, k_2, k_3, k_4;

		for (double x_curr = x_min; x_curr <= x_max + in_cond.border_control; x_curr += step) {
			solution[x_curr] = dots[counter];
			k_1 = problem(dots[counter], 0);
			k_2 = problem(dots[counter] + step / 2 * k_1, 0);
			k_3 = problem(dots[counter] + step / 2 * k_2, 0);
			k_4 = problem(dots[counter] + step * k_3, 0);
			++counter;
			dots.push_back(dots[counter - 1] + step / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4));

			log_data(
				//index,
				x_curr,
				step,
				solution[x_curr],
				0,
				0,
				0,
				0,
				0,
				0,
				std::fabs(true_solution[index] - solution[x_curr])
			);
			++index;
		}
	}

	return solution;
}

std::map<double, double> method::task::find_true_solution(double c_) {
	double x_curr = x_min;
	double u = 0;
	double c = c_;
	size_t index = 0;

	while (x_curr <= x_max + in_cond.border_control) {
		u = c / std::pow(std::exp(1.0), 5 / 2 * x_curr);
		true_dots.push_back(u);
		true_solution[x_curr] = true_dots[index];
		x_curr += step;
		++index;
	}

	return true_solution;
}

double method::test_task::problem(double u, double x) {
	return (-1) * 5 / 2 * u;
}

double method::first_task::problem(double u, double x) {
	return log(x + 1) / (std::pow(x, 2) + 1) * std::pow(u, 2) + u - std::pow(u, 3) * sin(10 * x);
}

double method::second_task::problem(double u, double x) {
	return 0;
}

