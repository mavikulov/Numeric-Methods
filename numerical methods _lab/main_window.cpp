#include "main_window.h"
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

//bool validate_textboxes(System::Windows::Forms::TextBox txt_1, System::Windows::Forms::TextBox txt_2, System::Windows::Forms::TextBox txt_3);

System::Void numericalmethodslab::main_window::main_window_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();

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
	/*if (!validate_textboxes(numericalmethodslab::main_window::initial_step_tb, numericalmethodslab::main_window::max_stp_tb,
		numericalmethodslab::main_window::local_err_tb));
		MessageBox::Show("incorrect values in textboxes");*/

	//method::task* tt = new method::test_task();
	method::test_task t_t;
	x_min = 0; x_max = 1; x = x_min;
	h = System::Convert::ToDouble(this->initial_step_tb->Text);

	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();

	std::vector<double> sol_tr = t_t.find_true_solution();
	for (const auto& val : sol_tr) {
		y_true = val;
		this->chart1->Series[0]->Points->AddXY(x, y_true);
		x += h;
	}
	t_t.clear_data();
	x = x_min;
	std::vector<double> sol_num = t_t.find_solution();
	for (const auto& val : sol_num) {
		y_numerical = val;
		this->chart1->Series[1]->Points->AddXY(x, y_numerical);
		x += h;
	}

	//while (x <= x_max) {
	//	y_true = sol_tr[x * 10];
	////	y_numerical = sol_num[x * 10];
	//	this->chart1->Series[0]->Points->AddXY(x, y_true);
	//	//this->chart1->Series[1]->Points->AddXY(x, y_numerical);
	//	x += h;
	//}

	/*while (x <= x_max) {
		y_true = Math::Cos(x);
		y_numerical = Math::Sin(x);
		this->chart1->Series[0]->Points->AddXY(x, y_true);
		this->chart1->Series[1]->Points->AddXY(x, y_numerical);
		x += h;
	}*/


	return System::Void();
}

//bool validate_textboxes(System::Windows::Forms::TextBox txt_1, System::Windows::Forms::TextBox txt_2, System::Windows::Forms::TextBox txt_3) {
//	if (System::String::IsNullOrEmpty(txt_1.Text) || System::String::IsNullOrEmpty(txt_3.Text)
//		|| System::String::IsNullOrEmpty(txt_2.Text))
//		return false;
//	if (txt_1.Text->Contains(".") || txt_2.Text->Contains(".")
//		|| txt_3.Text->Contains("."))
//		return false;
//	return true;
//}
