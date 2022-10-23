#pragma once

#include <vector>
#include <cmath>
#include <map>
#include <fstream>

namespace method {

	struct initial_conditions {
		 double e_u;
		 double e_u_neg;
		 double epsilon;
		 double h;
		 double x_min;
		 double x_max;
		 double border_control;
		 int	max_steps;
		 bool   control_local_err;
	};

	class task {
	public:
		task() = default;

		virtual ~task() {}

		virtual double problem(double, double) = 0;

		void clear_data();

		void initialize(double h_ = 0.1, double x_min_ = 0, double x_max_ = 1);

		void half_step(double e_u);

		void log_data(size_t index, double x_curr, double h_curr, double y_num,
			double y_num_h, double diff_curr, double l_err_curr, double y_upd,
			size_t div_count, size_t doub_count, double abs_diff);

		std::map<double, double> find_solution(double e_u, bool control);

		std::map<double, double> find_true_solution(double c_);

	private:
		std::vector<double> true_dots;
		std::vector<double> half_step_d;
		std::vector<double> dots;
	private:
		std::map<double, double> solution;
		std::map<double, double> true_solution;
	private:
		double step;
		double x_min;
		double x_max;
	};

	class test_task : public task {
	public:
		test_task() = default;

		double problem(double u, double x = 0) override;

		~test_task(){}
	};

	class first_task : public task {
	public:
		first_task() = default;

		double problem(double u, double x) override;

		std::vector<double> find_true_solution() = delete;

		~first_task(){}
	};

	class second_task : public task {
	public:
		second_task() = default;

		double problem(double u, double x) override;

		std::vector<double> find_true_solution() = delete;

		~second_task(){}
	};
}