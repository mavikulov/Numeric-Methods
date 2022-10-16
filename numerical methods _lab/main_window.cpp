#include "main_window.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	numericalmethodslab::main_window form;
	Application::Run(% form);
}

System::Void numericalmethodslab::main_window::main_window_Load(System::Object^ sender, System::EventArgs^ e)
{
	clear_chart();

	return System::Void();
}

System::Void numericalmethodslab::main_window::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}

System::Void numericalmethodslab::main_window::method_clear_Click(System::Object^ sender, System::EventArgs^ e)
{
	clear_chart();
	clear_table();

	return System::Void();
}

System::Void numericalmethodslab::main_window::method_start_Click(System::Object^ sender, System::EventArgs^ e) try
{
	clear_table();
	clear_chart();
	current_task->clear_data();

	initialize_vars();
	current_task->initialize(method::in_cond.h, method::in_cond.x_min, method::in_cond.x_max);

	h_ = method::in_cond.h;
	x_min = method::in_cond.x_min;
	x_max = method::in_cond.x_max;

	chart1->ChartAreas[0]->AxisX->Minimum = 0;
	chart1->ChartAreas[0]->AxisX->Maximum = 1;
	chart1->ChartAreas[0]->AxisX->Interval = 0.05;

	//this->chart1->Series[0]; // true positive
	//this->chart1->Series[1]; // true negative 
	//this->chart1->Series[2]; // numerical positive
	//this->chart1->Series[3]; // numerical negative

	if (dynamic_cast<method::test_task*>(current_task))
		draw_test_t();
	else if (dynamic_cast<method::first_task*>(current_task))
		draw_first_t();

	return System::Void();
}
catch (...) { MessageBox::Show("Please select test/first/second task"); };

System::Void numericalmethodslab::main_window::clear_all() {

	clear_chart();
	clear_table();

	delete current_task;

	return System::Void();
}

method::initial_conditions numericalmethodslab::main_window::initialize_vars() {

	//double e_u = entry_v_positive->Checked ? 1 : 0;
	//double e_u_neg = entry_v_negative->Checked ? (-1) : 0;
	//double epsilon = System::Convert::ToDouble(local_err_tb->Text);
	//double h = System::Convert::ToDouble(initial_step_tb->Text);
	//double x_min = System::Convert::ToDouble(x_min_tb->Text);
	//double x_max = System::Convert::ToDouble(x_max_tb->Text);
	//int max_steps = System::Convert::ToInt32(max_stp_tb->Text);
	//bool control_local_err = control_step_cb->Checked ? 1 : 0;

	method::in_cond.e_u = entry_v_positive->Checked ? 1 : 0;
	method::in_cond.e_u_neg = entry_v_negative->Checked ? (-1) : 0;
	method::in_cond.epsilon = System::Convert::ToDouble(local_err_tb->Text);
	method::in_cond.h = System::Convert::ToDouble(initial_step_tb->Text);
	method::in_cond.x_min = System::Convert::ToDouble(x_min_tb->Text);
	method::in_cond.x_max = System::Convert::ToDouble(x_max_tb->Text);
	method::in_cond.max_steps = System::Convert::ToInt32(max_stp_tb->Text);
	method::in_cond.control_local_err = control_step_cb->Checked ? 1 : 0;

	return method::in_cond;

}

System::Void numericalmethodslab::main_window::clear_chart()
{
	chart1->Series[0]->Points->Clear(); 
	chart1->Series[1]->Points->Clear(); 
	chart1->Series[2]->Points->Clear(); 
	chart1->Series[3]->Points->Clear();

	return System::Void();
}

System::Void numericalmethodslab::main_window::clear_table()
{
	data_table->Rows->Clear();
	data_table->Refresh();

	data_table_neg->Rows->Clear();
	data_table_neg->Refresh();

	return System::Void();
}

System::Void numericalmethodslab::main_window::fill_datagrid(size_t index)
{
	if (entry_v_positive->Checked) {
		data_table->Rows[index]->Cells[0]->Value = index;
		data_table->Rows[index]->Cells[1]->Value = x_current;
		data_table->Rows[index]->Cells[2]->Value = h_current;
		data_table->Rows[index]->Cells[3]->Value = y_numerical;
		data_table->Rows[index]->Cells[4]->Value = /*y_half*/0;
		data_table->Rows[index]->Cells[5]->Value = diff_current;
		data_table->Rows[index]->Cells[6]->Value = local_err_current;
		data_table->Rows[index]->Cells[7]->Value = y_upd;
		data_table->Rows[index]->Cells[8]->Value = div_current;
		data_table->Rows[index]->Cells[9]->Value = doub_current;
		data_table->Rows[index]->Cells[10]->Value = abs_diff;
	}
	if (entry_v_negative->Checked) {
		data_table_neg->Rows[index]->Cells[0]->Value = index;
		data_table_neg->Rows[index]->Cells[1]->Value = x_current;
		data_table_neg->Rows[index]->Cells[2]->Value = h_;
		data_table_neg->Rows[index]->Cells[3]->Value = y_numerical_neg;
		data_table_neg->Rows[index]->Cells[4]->Value = /*y_half*/0;
		data_table_neg->Rows[index]->Cells[5]->Value = /*diff_current_neg*/0;
		data_table_neg->Rows[index]->Cells[6]->Value = /*local_err_current*/0;
		data_table_neg->Rows[index]->Cells[7]->Value = /*y_upd_neg*/0;
		data_table_neg->Rows[index]->Cells[8]->Value = /*div_current_neg*/0;
		data_table_neg->Rows[index]->Cells[9]->Value = /*doub_current_neg*/0;
		data_table_neg->Rows[index]->Cells[10]->Value = /*abs_current_neg*/0;

	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_true_s()
{
	size_t index = 0;
	x_current = x_min;

	std::vector<double> sol_true = current_task->find_true_solution(method::in_cond.e_u);

	while (x_current <= x_max) {
		y_true = sol_true[index];
		chart1->Series[0]->Points->AddXY(x_current, y_true);
		x_current += method::in_cond.h;
		++index;
	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_numerical_s()
{
	size_t index = 0;
	x_current = x_min;

	std::vector<double> sol_num = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u, h_, 1)
		: current_task->find_solution(method::in_cond.e_u, h_, 0);

	while (x_current <= x_max) {
		y_numerical = sol_num[index];

		//abs_diff = std::abs(sol_true[index] - sol_num[index]);
		//h_current = method::m_vars.current_h[index];
		//diff_current = method::m_vars.difference[index];
		//local_err_current = method::m_vars.local_err[index];
		//y_upd = method::m_vars.v_upd[index];
		//div_current = method::m_vars.divisions[index];
		//doub_current = method::m_vars.doublings[index];

		chart1->Series[2]->Points->AddXY(x_current, y_numerical);
		x_current += method::in_cond.control_local_err ? method::m_vars.current_h[index] : method::in_cond.h;
		++index;
	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_test_t()
{
	if (entry_v_positive->Checked && !entry_v_negative->Checked) {

		draw_true_s();
		draw_numerical_s();

		/*std::vector<double> sol_num = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u,h_,1) 
			: current_task->find_solution(method::in_cond.e_u, h_, 0);
		data_table->RowCount = sol_num.size();*/

		/*while (x_current <= x_max && index != sol_num.size()) {
			y_numerical = sol_num[index];
			abs_diff = std::abs(sol_true[index] - sol_num[index]);
			h_current = method::m_vars.current_h[index];
			h_current = method::m_vars.current_h[index];
			diff_current = method::m_vars.difference[index];
			local_err_current = method::m_vars.local_err[index];
			y_upd = method::m_vars.v_upd[index];
			div_current = method::m_vars.divisions[index];
			doub_current = method::m_vars.doublings[index];
			chart1->Series[2]->Points->AddXY(x_current, y_numerical);
			x_current = method::m_vars.current_h[index];
			fill_datagrid(index);
			++index;
		}*/
	} 

	//if (!entry_v_positive->Checked && entry_v_negative->Checked) {

	//	std::vector<double> sol_num_neg = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u_neg, h_, 1)
	//		: current_task->find_solution(method::in_cond.e_u_neg, h_, 0);
	//	std::vector<double> sol_true_neg = current_task->find_true_solution(method::in_cond.e_u_neg);
	//	//sol_num_neg.pop_back();
	//	data_table_neg->RowCount = sol_num_neg.size();

	//	while (x_current <= x_max && index != sol_num_neg.size() /*- 1*/) {
	//		y_numerical_neg = sol_num_neg[index];
	//		y_true_neg = sol_true_neg[index];
	//		chart1->Series[1]->Points->AddXY(x_current, y_true_neg);
	//		chart1->Series[3]->Points->AddXY(x_current, y_numerical_neg);

	//		x_current += h_;

	//		fill_datagrid(index);

	//		++index;
	//	}
	//}

	//if (entry_v_positive->Checked && entry_v_negative->Checked) {
	//	std::vector<double> sol_num = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u, h_, 1)
	//		: current_task->find_solution(method::in_cond.e_u, h_, 0);
	//	std::vector<double> sol_true = current_task->find_true_solution(method::in_cond.e_u);
	//	//sol_num.pop_back();

	//	current_task->clear_data();
	//	std::vector<double> sol_num_neg = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u_neg, h_, 1)
	//		: current_task->find_solution(method::in_cond.e_u_neg, h_, 0);
	//	std::vector<double> sol_true_neg = current_task->find_true_solution(method::in_cond.e_u_neg);
	//	//sol_num_neg.pop_back();

	//	data_table->RowCount = sol_num.size();
	//	data_table_neg->RowCount = sol_num_neg.size();

	//	while (x_current <= x_max && index < sol_num.size() /*- 1*/) {
	//		y_numerical = sol_num[index];
	//		y_true = sol_true[index];
	//		y_numerical_neg = sol_num_neg[index];
	//		y_true_neg = sol_true_neg[index];
	//		chart1->Series[0]->Points->AddXY(x_current, y_true);
	//		chart1->Series[1]->Points->AddXY(x_current, y_true_neg);
	//		chart1->Series[2]->Points->AddXY(x_current, y_numerical);
	//		chart1->Series[3]->Points->AddXY(x_current, y_numerical_neg);
	//		x_current += h_;

	//		fill_datagrid(index);

	//		++index;
	//	}
	//}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_first_t()
{
	size_t index = 0;
	x_current = x_min;

	if (entry_v_positive->Checked && !entry_v_negative->Checked) {

		std::vector<double> sol_num = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u, h_, 1)
			: current_task->find_solution(method::in_cond.e_u, h_, 0);
		//sol_num.pop_back();
		data_table->RowCount = sol_num.size();

		while (x_current < x_max && index < sol_num.size() /*- 1*/) {
			y_numerical = sol_num[index];
			//h_current = method::m_vars.current_h[index];
			//diff_current = method::m_vars.difference[index];
			//local_err_current = method::m_vars.local_err[index];
			//y_upd = method::m_vars.v_upd[index];
			//div_current = method::m_vars.divisions[index];
			//doub_current = method::m_vars.doublings[index];
			chart1->Series[2]->Points->AddXY(x_current, y_numerical);
			x_current += h_;

			fill_datagrid(index);

			++index;
		}
	}

	if (!entry_v_positive->Checked && entry_v_negative->Checked) {

		std::vector<double> sol_num_neg = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u_neg, h_, 1)
			: current_task->find_solution(method::in_cond.e_u_neg, h_, 0);
		//sol_num_neg.pop_back();
		data_table_neg->RowCount = sol_num_neg.size();

		while (x_current <= x_max && index < sol_num_neg.size() /*- 1*/) {
			y_numerical_neg = sol_num_neg[index];
			chart1->Series[1]->Points->AddXY(x_current, y_true_neg);
			chart1->Series[3]->Points->AddXY(x_current, y_numerical_neg);
			x_current += h_;

			fill_datagrid(index);

			++index;
		}
	}

	if (entry_v_positive->Checked && entry_v_negative->Checked) {
		std::vector<double> sol_num = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u, h_, 1)
			: current_task->find_solution(method::in_cond.e_u, h_, 0);
		//sol_num.pop_back();

		current_task->clear_data();
		std::vector<double> sol_num_neg = method::in_cond.control_local_err ? current_task->find_solution(method::in_cond.e_u_neg, h_, 1)
			: current_task->find_solution(method::in_cond.e_u_neg, h_, 0);
		//sol_num_neg.pop_back();

		data_table->RowCount = sol_num.size();
		data_table_neg->RowCount = sol_num_neg.size();

		while (x_current <= x_max && index < sol_num.size() /*- 1*/) {
			y_numerical = sol_num[index];
			y_numerical_neg = sol_num_neg[index];
			chart1->Series[2]->Points->AddXY(x_current, y_numerical);
			chart1->Series[3]->Points->AddXY(x_current, y_numerical_neg);
			x_current += h_;

			fill_datagrid(index);

			++index;
		}
	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_second_t()
{
	return System::Void();
}

System::Void numericalmethodslab::main_window::test_task_Click(System::Object^ sender, System::EventArgs^ e)
{
	current_task = new method::test_task;

	test_task->ForeColor = Color::FromArgb(144, 144, 144);
	first_task->ForeColor = Color::FromArgb(255, 255, 255);
	second_task->ForeColor = Color::FromArgb(255, 255, 255);

	return System::Void();
}

System::Void numericalmethodslab::main_window::first_task_Click(System::Object^ sender, System::EventArgs^ e)
{
	current_task = new method::first_task;

	test_task->ForeColor = Color::FromArgb(255, 255, 255);
	first_task->ForeColor = Color::FromArgb(144, 144, 144);
	second_task->ForeColor = Color::FromArgb(255, 255, 255);

	return System::Void();
}

System::Void numericalmethodslab::main_window::second_task_Click(System::Object^ sender, System::EventArgs^ e)
{
	current_task = new method::second_task;

	test_task->ForeColor = Color::FromArgb(255, 255, 255);
	first_task->ForeColor = Color::FromArgb(255, 255, 255);
	second_task->ForeColor = Color::FromArgb(144, 144, 144);

	return System::Void();
}




