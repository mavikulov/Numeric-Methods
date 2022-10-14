#pragma once

#include "method.h"

namespace numericalmethodslab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ main_window
	/// </summary>
	public ref class main_window : public System::Windows::Forms::Form
	{
	public:
		main_window(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~main_window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ test_task;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::GroupBox^ menu_gropbox;
	private: System::Windows::Forms::Button^ second_task;
	private: System::Windows::Forms::Button^ first_task;
	private: System::Windows::Forms::GroupBox^ parameters_gb;
	private: System::Windows::Forms::GroupBox^ help_gb;
	private: System::Windows::Forms::Button^ exit_button;

	private: System::Windows::Forms::TextBox^ max_stp_tb;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ local_err_tb;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ initial_step_tb;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ method_start;
	private: System::Windows::Forms::Button^ method_clear;
	private: System::Windows::Forms::CheckBox^ control_step_cb;


	private: System::Windows::Forms::TextBox^ x_max_tb;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ x_min_tb;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ data_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ index;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ x_index;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ h_index;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v_index;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v_index_corr;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v_diff;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ loc_err_est;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ v_index_updated;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ division;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ doubling;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ abs_difference;
	private: System::Windows::Forms::CheckBox^ entry_v_negative;
	private: System::Windows::Forms::CheckBox^ entry_v_positive;





	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_window::typeid));
			this->test_task = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menu_gropbox = (gcnew System::Windows::Forms::GroupBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->second_task = (gcnew System::Windows::Forms::Button());
			this->first_task = (gcnew System::Windows::Forms::Button());
			this->parameters_gb = (gcnew System::Windows::Forms::GroupBox());
			this->entry_v_negative = (gcnew System::Windows::Forms::CheckBox());
			this->entry_v_positive = (gcnew System::Windows::Forms::CheckBox());
			this->x_max_tb = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->x_min_tb = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->control_step_cb = (gcnew System::Windows::Forms::CheckBox());
			this->max_stp_tb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->local_err_tb = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->initial_step_tb = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->help_gb = (gcnew System::Windows::Forms::GroupBox());
			this->method_start = (gcnew System::Windows::Forms::Button());
			this->method_clear = (gcnew System::Windows::Forms::Button());
			this->data_table = (gcnew System::Windows::Forms::DataGridView());
			this->index = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->x_index = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->h_index = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v_index = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v_index_corr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v_diff = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->loc_err_est = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v_index_updated = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->division = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->doubling = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->abs_difference = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menu_gropbox->SuspendLayout();
			this->parameters_gb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_table))->BeginInit();
			this->SuspendLayout();
			// 
			// test_task
			// 
			this->test_task->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->test_task->FlatAppearance->BorderSize = 0;
			this->test_task->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->test_task->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->test_task->Location = System::Drawing::Point(6, 182);
			this->test_task->Name = L"test_task";
			this->test_task->Size = System::Drawing::Size(211, 50);
			this->test_task->TabIndex = 0;
			this->test_task->Text = L"test";
			this->test_task->UseVisualStyleBackColor = true;
			this->test_task->Click += gcnew System::EventHandler(this, &main_window::test_task_Click);
			// 
			// chart1
			// 
			chartArea1->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->BorderWidth = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Alignment = System::Drawing::StringAlignment::Center;
			legend1->Name = L"chart_legend";
			legend1->Title = L"chart";
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::ThickGradientLine;
			legend1->TitleSeparatorColor = System::Drawing::Color::LightSkyBlue;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(482, 12);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			series1->BorderColor = System::Drawing::Color::Transparent;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::DarkOrchid;
			series1->Legend = L"chart_legend";
			series1->LegendText = L"true solution, u0 = 1";
			series1->Name = L"true_solution_positive";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"chart_legend";
			series2->LegendText = L"true solution, u0 = -1";
			series2->Name = L"true_solution_negative";
			series3->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Red;
			series3->Legend = L"chart_legend";
			series3->LegendText = L"numerical solution, u0 = 1";
			series3->Name = L"numerical_solution_positive";
			series4->BorderColor = System::Drawing::Color::Transparent;
			series4->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			series4->BorderWidth = 3;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Legend = L"chart_legend";
			series4->LegendText = L"numerical solution, u0 = -1";
			series4->Name = L"numerical_solution_negative";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(696, 369);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// menu_gropbox
			// 
			this->menu_gropbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->menu_gropbox->Controls->Add(this->exit_button);
			this->menu_gropbox->Controls->Add(this->second_task);
			this->menu_gropbox->Controls->Add(this->first_task);
			this->menu_gropbox->Controls->Add(this->test_task);
			this->menu_gropbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->menu_gropbox->Location = System::Drawing::Point(0, -18);
			this->menu_gropbox->Name = L"menu_gropbox";
			this->menu_gropbox->Size = System::Drawing::Size(223, 689);
			this->menu_gropbox->TabIndex = 4;
			this->menu_gropbox->TabStop = false;
			this->menu_gropbox->Text = L"menu";
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->exit_button->FlatAppearance->BorderSize = 0;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exit_button->Location = System::Drawing::Point(6, 635);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(211, 37);
			this->exit_button->TabIndex = 3;
			this->exit_button->Text = L"exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &main_window::exit_button_Click);
			// 
			// second_task
			// 
			this->second_task->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->second_task->FlatAppearance->BorderSize = 0;
			this->second_task->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->second_task->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->second_task->Location = System::Drawing::Point(6, 302);
			this->second_task->Name = L"second_task";
			this->second_task->Size = System::Drawing::Size(211, 54);
			this->second_task->TabIndex = 2;
			this->second_task->Text = L"second task";
			this->second_task->UseVisualStyleBackColor = false;
			this->second_task->Click += gcnew System::EventHandler(this, &main_window::second_task_Click);
			// 
			// first_task
			// 
			this->first_task->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->first_task->FlatAppearance->BorderSize = 0;
			this->first_task->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->first_task->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->first_task->Location = System::Drawing::Point(6, 242);
			this->first_task->Name = L"first_task";
			this->first_task->Size = System::Drawing::Size(211, 54);
			this->first_task->TabIndex = 1;
			this->first_task->Text = L"first task";
			this->first_task->UseVisualStyleBackColor = false;
			this->first_task->Click += gcnew System::EventHandler(this, &main_window::first_task_Click);
			// 
			// parameters_gb
			// 
			this->parameters_gb->Controls->Add(this->entry_v_negative);
			this->parameters_gb->Controls->Add(this->entry_v_positive);
			this->parameters_gb->Controls->Add(this->x_max_tb);
			this->parameters_gb->Controls->Add(this->label5);
			this->parameters_gb->Controls->Add(this->x_min_tb);
			this->parameters_gb->Controls->Add(this->label4);
			this->parameters_gb->Controls->Add(this->control_step_cb);
			this->parameters_gb->Controls->Add(this->max_stp_tb);
			this->parameters_gb->Controls->Add(this->label3);
			this->parameters_gb->Controls->Add(this->local_err_tb);
			this->parameters_gb->Controls->Add(this->label2);
			this->parameters_gb->Controls->Add(this->initial_step_tb);
			this->parameters_gb->Controls->Add(this->label1);
			this->parameters_gb->Location = System::Drawing::Point(229, 12);
			this->parameters_gb->Name = L"parameters_gb";
			this->parameters_gb->Size = System::Drawing::Size(256, 252);
			this->parameters_gb->TabIndex = 5;
			this->parameters_gb->TabStop = false;
			this->parameters_gb->Text = L"parameters";
			// 
			// entry_v_negative
			// 
			this->entry_v_negative->AutoSize = true;
			this->entry_v_negative->ForeColor = System::Drawing::SystemColors::Desktop;
			this->entry_v_negative->Location = System::Drawing::Point(98, 199);
			this->entry_v_negative->Name = L"entry_v_negative";
			this->entry_v_negative->Size = System::Drawing::Size(76, 24);
			this->entry_v_negative->TabIndex = 13;
			this->entry_v_negative->Text = L"u0 = -1";
			this->entry_v_negative->UseVisualStyleBackColor = true;
			// 
			// entry_v_positive
			// 
			this->entry_v_positive->AutoSize = true;
			this->entry_v_positive->ForeColor = System::Drawing::SystemColors::Desktop;
			this->entry_v_positive->Location = System::Drawing::Point(6, 199);
			this->entry_v_positive->Name = L"entry_v_positive";
			this->entry_v_positive->Size = System::Drawing::Size(70, 24);
			this->entry_v_positive->TabIndex = 12;
			this->entry_v_positive->Text = L"u0 = 1";
			this->entry_v_positive->UseVisualStyleBackColor = true;
			// 
			// x_max_tb
			// 
			this->x_max_tb->Location = System::Drawing::Point(101, 152);
			this->x_max_tb->Name = L"x_max_tb";
			this->x_max_tb->Size = System::Drawing::Size(146, 27);
			this->x_max_tb->TabIndex = 11;
			this->x_max_tb->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(6, 152);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"x maximum = ";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// x_min_tb
			// 
			this->x_min_tb->Location = System::Drawing::Point(101, 122);
			this->x_min_tb->Name = L"x_min_tb";
			this->x_min_tb->Size = System::Drawing::Size(146, 27);
			this->x_min_tb->TabIndex = 9;
			this->x_min_tb->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label4->Location = System::Drawing::Point(7, 122);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"x minimum = ";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// control_step_cb
			// 
			this->control_step_cb->AutoSize = true;
			this->control_step_cb->ForeColor = System::Drawing::SystemColors::Desktop;
			this->control_step_cb->Location = System::Drawing::Point(6, 222);
			this->control_step_cb->Name = L"control_step_cb";
			this->control_step_cb->Size = System::Drawing::Size(219, 24);
			this->control_step_cb->TabIndex = 7;
			this->control_step_cb->Text = L"control h (const h by default)";
			this->control_step_cb->UseVisualStyleBackColor = true;
			this->control_step_cb->CheckedChanged += gcnew System::EventHandler(this, &main_window::control_step_cb_CheckedChanged);
			// 
			// max_stp_tb
			// 
			this->max_stp_tb->Location = System::Drawing::Point(98, 92);
			this->max_stp_tb->Name = L"max_stp_tb";
			this->max_stp_tb->Size = System::Drawing::Size(149, 27);
			this->max_stp_tb->TabIndex = 5;
			this->max_stp_tb->Text = L"1000";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(6, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"max steps = ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// local_err_tb
			// 
			this->local_err_tb->Location = System::Drawing::Point(148, 62);
			this->local_err_tb->Name = L"local_err_tb";
			this->local_err_tb->Size = System::Drawing::Size(99, 27);
			this->local_err_tb->TabIndex = 3;
			this->local_err_tb->Text = L"0,0001";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(7, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"local error control = ";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// initial_step_tb
			// 
			this->initial_step_tb->Location = System::Drawing::Point(98, 32);
			this->initial_step_tb->Name = L"initial_step_tb";
			this->initial_step_tb->Size = System::Drawing::Size(149, 27);
			this->initial_step_tb->TabIndex = 1;
			this->initial_step_tb->Text = L"0,1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(6, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"initial step = ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// help_gb
			// 
			this->help_gb->Location = System::Drawing::Point(800, 387);
			this->help_gb->Name = L"help_gb";
			this->help_gb->Size = System::Drawing::Size(378, 267);
			this->help_gb->TabIndex = 6;
			this->help_gb->TabStop = false;
			this->help_gb->Text = L"help";
			// 
			// method_start
			// 
			this->method_start->ForeColor = System::Drawing::SystemColors::ControlText;
			this->method_start->Location = System::Drawing::Point(284, 280);
			this->method_start->Name = L"method_start";
			this->method_start->Size = System::Drawing::Size(152, 30);
			this->method_start->TabIndex = 8;
			this->method_start->Text = L"start";
			this->method_start->UseVisualStyleBackColor = true;
			this->method_start->Click += gcnew System::EventHandler(this, &main_window::method_start_Click);
			// 
			// method_clear
			// 
			this->method_clear->ForeColor = System::Drawing::SystemColors::ControlText;
			this->method_clear->Location = System::Drawing::Point(284, 325);
			this->method_clear->Name = L"method_clear";
			this->method_clear->Size = System::Drawing::Size(152, 30);
			this->method_clear->TabIndex = 9;
			this->method_clear->Text = L"clear";
			this->method_clear->UseVisualStyleBackColor = true;
			this->method_clear->Click += gcnew System::EventHandler(this, &main_window::method_clear_Click);
			// 
			// data_table
			// 
			this->data_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->index, this->x_index,
					this->h_index, this->v_index, this->v_index_corr, this->v_diff, this->loc_err_est, this->v_index_updated, this->division, this->doubling,
					this->abs_difference
			});
			this->data_table->Location = System::Drawing::Point(229, 387);
			this->data_table->Name = L"data_table";
			this->data_table->Size = System::Drawing::Size(565, 267);
			this->data_table->TabIndex = 10;
			// 
			// index
			// 
			this->index->HeaderText = L"i";
			this->index->Name = L"index";
			// 
			// x_index
			// 
			this->x_index->HeaderText = L"x_i";
			this->x_index->Name = L"x_index";
			// 
			// h_index
			// 
			this->h_index->HeaderText = L"h_i";
			this->h_index->Name = L"h_index";
			// 
			// v_index
			// 
			this->v_index->HeaderText = L"v_i";
			this->v_index->Name = L"v_index";
			// 
			// v_index_corr
			// 
			this->v_index_corr->HeaderText = L"v^i";
			this->v_index_corr->Name = L"v_index_corr";
			// 
			// v_diff
			// 
			this->v_diff->HeaderText = L"v_i - v^i";
			this->v_diff->Name = L"v_diff";
			// 
			// loc_err_est
			// 
			this->loc_err_est->HeaderText = L"loc_err_est";
			this->loc_err_est->Name = L"loc_err_est";
			// 
			// v_index_updated
			// 
			this->v_index_updated->HeaderText = L"v_i_upd";
			this->v_index_updated->Name = L"v_index_updated";
			// 
			// division
			// 
			this->division->HeaderText = L"div";
			this->division->Name = L"division";
			// 
			// doubling
			// 
			this->doubling->HeaderText = L"doub.";
			this->doubling->Name = L"doubling";
			// 
			// abs_difference
			// 
			this->abs_difference->HeaderText = L"|u_i - v_i|";
			this->abs_difference->Name = L"abs_difference";
			// 
			// main_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(1190, 666);
			this->Controls->Add(this->data_table);
			this->Controls->Add(this->method_clear);
			this->Controls->Add(this->method_start);
			this->Controls->Add(this->help_gb);
			this->Controls->Add(this->parameters_gb);
			this->Controls->Add(this->menu_gropbox);
			this->Controls->Add(this->chart1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::GrayText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"main_window";
			this->Text = L"numerical methods";
			this->TransparencyKey = System::Drawing::Color::AliceBlue;
			this->Load += gcnew System::EventHandler(this, &main_window::main_window_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menu_gropbox->ResumeLayout(false);
			this->parameters_gb->ResumeLayout(false);
			this->parameters_gb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_table))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: double x_current, y_true, y_numerical;

	private: method::task* current_task;

	private: System::Void main_window_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void method_clear_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void method_start_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void control_step_cb_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void clear_all();

	private: method::initial_conditions initialize_all();

	private: System::Void test_task_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void first_task_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void second_task_Click(System::Object^ sender, System::EventArgs^ e);

};
}
