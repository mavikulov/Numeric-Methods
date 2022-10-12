#include "method.h"

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
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();

	return System::Void();
}

System::Void numericalmethodslab::main_window::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}

System::Void numericalmethodslab::main_window::method_clear_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();

	return System::Void();
}

System::Void numericalmethodslab::main_window::method_start_Click(System::Object^ sender, System::EventArgs^ e)
{
	//method::task* tt = new method::test_task();

	double x_min = System::Convert::ToDouble(this->x_min_tb->Text);
	double x_max = System::Convert::ToDouble(this->x_max_tb->Text);
	double h = System::Convert::ToDouble(this->initial_step_tb->Text);

	method::first_task t_t(h, x_min, x_max);

	x_current = x_min;

	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();

	/*std::vector<double> sol_tr = t_t.find_true_solution();
	for (const auto& val : sol_tr) {
		y_true = val;
		this->chart1->Series[0]->Points->AddXY(x_current, y_true);
		x_current += h;
	}
	x_current = x_min;

	t_t.clear_data();*/
	std::vector<double> sol_num = t_t.find_solution();
	sol_num.pop_back();
	for (const auto& val : sol_num) {
		y_numerical = val;
		this->chart1->Series[1]->Points->AddXY(x_current, y_numerical);
		x_current += h;
	}

	return System::Void();
}

System::Void numericalmethodslab::main_window::control_step_cb_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	//control_local_step = true;
	//eps = System::Convert::ToDouble(local_err_tb->Text);
	return System::Void();
}


