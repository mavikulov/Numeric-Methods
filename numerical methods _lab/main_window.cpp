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

extern method::initial_conditions in_cond;
extern method::out out_data;

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

	doub_c_tb->Text = "";
	div_c_tb->Text = "";
	max_err_tb->Text = "";
	max_step_tb->Text = "";
	min_step_tb->Text = "";
	
	return System::Void();
}

System::Void numericalmethodslab::main_window::method_start_Click(System::Object^ sender, System::EventArgs^ e) try
{
	clear_table();
	clear_chart();
	current_task->clear_data();

	initialize_vars();
	current_task->initialize(in_cond.h, in_cond.x_min, in_cond.x_max);

	chart1->ChartAreas[0]->AxisX->Minimum = in_cond.x_min;
	chart1->ChartAreas[0]->AxisX->Maximum = in_cond.x_max;
	chart1->ChartAreas[0]->AxisX->Interval = 0.05;

	if (dynamic_cast<method::test_task*>(current_task))
		draw_test_t();
	else if (dynamic_cast<method::first_task*>(current_task))
		draw_first_t();

	fill_datagrid();

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

	in_cond.e_u = entry_v_positive->Checked ? 1 : 0;
	in_cond.e_u_neg = entry_v_negative->Checked ? (-1) : 0;
	in_cond.epsilon = System::Convert::ToDouble(local_err_tb->Text);
	in_cond.h = System::Convert::ToDouble(initial_step_tb->Text);
	in_cond.x_min = System::Convert::ToDouble(x_min_tb->Text);
	in_cond.x_max = System::Convert::ToDouble(x_max_tb->Text);
	in_cond.border_control = System::Convert::ToDouble(border_control_tb->Text);
	in_cond.max_steps = System::Convert::ToInt32(max_stp_tb->Text);
	in_cond.control_local_err = control_step_cb->Checked ? 1 : 0;

	return in_cond;

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

void numericalmethodslab::main_window::fill_datagrid()
{
	//out_data.logs.push_back(std::make_tuple(x_curr, h_curr, y_num, y_num_h, diff_curr, l_err_curr, y_upd, div_count, doub_count, abs_diff));
	data_table->RowCount = out_data.logs.size();
	data_table_neg->RowCount = out_data.logs.size();
	for (size_t i = 0; i < out_data.logs.size(); ++i) {
		if (entry_v_positive->Checked) {
			data_table->Rows[i]->Cells[0]->Value = i;
			data_table->Rows[i]->Cells[1]->Value = std::get<0>(out_data.logs[i]);
			data_table->Rows[i]->Cells[2]->Value = std::get<1>(out_data.logs[i]);
			data_table->Rows[i]->Cells[3]->Value = std::get<2>(out_data.logs[i]);
			data_table->Rows[i]->Cells[4]->Value = std::get<3>(out_data.logs[i]);
			data_table->Rows[i]->Cells[5]->Value = std::get<4>(out_data.logs[i]);
			data_table->Rows[i]->Cells[6]->Value = std::get<5>(out_data.logs[i]);
			data_table->Rows[i]->Cells[7]->Value = std::get<6>(out_data.logs[i]);
			data_table->Rows[i]->Cells[8]->Value = std::get<7>(out_data.logs[i]);
			data_table->Rows[i]->Cells[9]->Value = std::get<8>(out_data.logs[i]);
			if (!dynamic_cast<method::test_task*>(current_task))
				data_table->Rows[i]->Cells[10]->Value = 0;
			else data_table->Rows[i]->Cells[10]->Value = std::get<9>(out_data.logs[i]);

			Int32 doub_c = 0, div_c = 0;
			Double max = System::Convert::ToDouble(data_table->Rows[0]->Cells[10]->Value);
			Double max_step = System::Convert::ToDouble(data_table->Rows[0]->Cells[2]->Value);
			Double min_step = System::Convert::ToDouble(data_table->Rows[0]->Cells[2]->Value);

			for (size_t i = 0; i < data_table->Rows->Count; ++i) {
				doub_c += System::Convert::ToInt32(data_table->Rows[i]->Cells[9]->Value);
				div_c += System::Convert::ToInt32(data_table->Rows[i]->Cells[8]->Value);

				if (System::Convert::ToDouble(data_table->Rows[i]->Cells[10]->Value) > max)
					max = System::Convert::ToDouble(data_table->Rows[i]->Cells[10]->Value);

				if (System::Convert::ToDouble(data_table->Rows[i]->Cells[2]->Value) > max_step)
					max_step = System::Convert::ToDouble(data_table->Rows[i]->Cells[2]->Value);
				if (System::Convert::ToDouble(data_table->Rows[i]->Cells[2]->Value) < min_step)
					min_step = System::Convert::ToDouble(data_table->Rows[i]->Cells[2]->Value);

			}
			doub_c_tb->Text = System::Convert::ToString(doub_c);
			div_c_tb->Text = System::Convert::ToString(div_c);
			max_err_tb->Text = System::Convert::ToString(max);
			max_step_tb->Text = System::Convert::ToString(max_step);
			min_step_tb->Text = System::Convert::ToString(min_step);
		}

		if (entry_v_negative->Checked) {
			data_table_neg->Rows[i]->Cells[0]->Value = i;
			data_table_neg->Rows[i]->Cells[1]->Value = std::get<0>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[2]->Value = std::get<1>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[3]->Value = std::get<2>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[4]->Value = std::get<3>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[5]->Value = std::get<4>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[6]->Value = std::get<5>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[7]->Value = std::get<6>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[8]->Value = std::get<7>(out_data.logs[i]);
			data_table_neg->Rows[i]->Cells[9]->Value = std::get<8>(out_data.logs[i]);
			if (!dynamic_cast<method::test_task*>(current_task))
				data_table_neg->Rows[i]->Cells[10]->Value = 0;
			else data_table_neg->Rows[i]->Cells[10]->Value = std::get<9>(out_data.logs[i]);

			Int32 doub_c = 0, div_c = 0;
			Double max = System::Convert::ToDouble(data_table_neg->Rows[0]->Cells[10]->Value);
			Double max_step = System::Convert::ToDouble(data_table_neg->Rows[0]->Cells[2]->Value);
			Double min_step = System::Convert::ToDouble(data_table_neg->Rows[0]->Cells[2]->Value);

			for (size_t i = 0; i < data_table_neg->Rows->Count; ++i) {
				doub_c += System::Convert::ToInt32(data_table_neg->Rows[i]->Cells[9]->Value);
				div_c += System::Convert::ToInt32(data_table_neg->Rows[i]->Cells[8]->Value);

				if (System::Convert::ToDouble(data_table_neg->Rows[i]->Cells[10]->Value) > max)
					max = System::Convert::ToDouble(data_table_neg->Rows[i]->Cells[10]->Value);

				if (System::Convert::ToDouble(data_table_neg->Rows[i]->Cells[2]->Value) > max_step)
					max_step = System::Convert::ToDouble(data_table_neg->Rows[i]->Cells[2]->Value);
				if (System::Convert::ToDouble(data_table_neg->Rows[i]->Cells[2]->Value) < min_step)
					min_step = System::Convert::ToDouble(data_table_neg->Rows[i]->Cells[2]->Value);

			}
			doub_c_tb->Text = System::Convert::ToString(doub_c);
			div_c_tb->Text = System::Convert::ToString(div_c);
			max_err_tb->Text = System::Convert::ToString(max);
			max_step_tb->Text = System::Convert::ToString(max_step);
			min_step_tb->Text = System::Convert::ToString(min_step);
		}
	}
}

System::Void numericalmethodslab::main_window::draw_true_s()
{
	std::map<double, double> sol_true;
	
	if (entry_v_positive->Checked && !entry_v_negative->Checked)
		sol_true = current_task->find_true_solution(in_cond.e_u);

	if (!entry_v_positive->Checked && entry_v_negative->Checked)
		sol_true = current_task->find_true_solution(in_cond.e_u_neg);

	for (const auto& kv : sol_true) {
		if (entry_v_positive->Checked && !entry_v_negative->Checked)
			chart1->Series[0]->Points->AddXY(kv.first, kv.second);
		if (!entry_v_positive->Checked && entry_v_negative->Checked)
			chart1->Series[1]->Points->AddXY(kv.first, kv.second);
	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_numerical_s()
{
	std::map<double, double> sol_num;

	if (entry_v_positive->Checked && !entry_v_negative->Checked)
		sol_num = in_cond.control_local_err ? current_task->find_solution(in_cond.e_u, 1)
			: current_task->find_solution(in_cond.e_u, 0);

	if (!entry_v_positive->Checked && entry_v_negative->Checked)
		sol_num = in_cond.control_local_err ? current_task->find_solution(in_cond.e_u_neg, 1)
			: current_task->find_solution(in_cond.e_u_neg, 0);

	for (const auto& kv : sol_num) {
		if (entry_v_positive->Checked && !entry_v_negative->Checked) 
			chart1->Series[2]->Points->AddXY(kv.first, kv.second);

		if (!entry_v_positive->Checked && entry_v_negative->Checked)
			chart1->Series[3]->Points->AddXY(kv.first, kv.second);
	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_test_t()
{
	draw_true_s();
	draw_numerical_s();

	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_first_t()
{
	draw_numerical_s();
	return System::Void();
}

System::Void numericalmethodslab::main_window::draw_second_t()
{
	//draw_numerical_s();
	return System::Void();
}

System::Void numericalmethodslab::main_window::test_task_Click(System::Object^ sender, System::EventArgs^ e)
{
	current_task = new method::test_task;

	test_task->ForeColor = Color::FromArgb(144, 144, 144);
	first_task->ForeColor = Color::FromArgb(255, 255, 255);
	//second_task->ForeColor = Color::FromArgb(255, 255, 255);

	return System::Void();
}

System::Void numericalmethodslab::main_window::first_task_Click(System::Object^ sender, System::EventArgs^ e)
{
	current_task = new method::first_task;

	test_task->ForeColor = Color::FromArgb(255, 255, 255);
	first_task->ForeColor = Color::FromArgb(144, 144, 144);
	//second_task->ForeColor = Color::FromArgb(255, 255, 255);

	return System::Void();
}

System::Void numericalmethodslab::main_window::second_task_Click(System::Object^ sender, System::EventArgs^ e)
{
	current_task = new method::second_task;

	test_task->ForeColor = Color::FromArgb(255, 255, 255);
	first_task->ForeColor = Color::FromArgb(255, 255, 255);
	//second_task->ForeColor = Color::FromArgb(144, 144, 144);

	return System::Void();
}





