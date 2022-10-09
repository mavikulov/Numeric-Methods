#pragma once

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
	private: System::Windows::Forms::TableLayoutPanel^ value_table;
	private: System::Windows::Forms::TextBox^ max_stp_tb;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ local_err_tb;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ initial_step_tb;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ method_start;
	private: System::Windows::Forms::Button^ method_clear;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_window::typeid));
			this->test_task = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menu_gropbox = (gcnew System::Windows::Forms::GroupBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->second_task = (gcnew System::Windows::Forms::Button());
			this->first_task = (gcnew System::Windows::Forms::Button());
			this->parameters_gb = (gcnew System::Windows::Forms::GroupBox());
			this->max_stp_tb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->local_err_tb = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->initial_step_tb = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->help_gb = (gcnew System::Windows::Forms::GroupBox());
			this->value_table = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->method_start = (gcnew System::Windows::Forms::Button());
			this->method_clear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menu_gropbox->SuspendLayout();
			this->parameters_gb->SuspendLayout();
			this->SuspendLayout();
			// 
			// test_task
			// 
			this->test_task->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->test_task->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->test_task->Location = System::Drawing::Point(44, 206);
			this->test_task->Name = L"test_task";
			this->test_task->Size = System::Drawing::Size(135, 30);
			this->test_task->TabIndex = 0;
			this->test_task->Text = L"test";
			this->test_task->UseVisualStyleBackColor = false;
			this->test_task->Click += gcnew System::EventHandler(this, &main_window::button1_Click);
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
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Blue;
			series1->Legend = L"chart_legend";
			series1->LegendText = L"true solution";
			series1->Name = L"true_solution";
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"chart_legend";
			series2->LegendText = L"numerical solution";
			series2->Name = L"numerical_solution";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(673, 369);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// menu_gropbox
			// 
			this->menu_gropbox->BackColor = System::Drawing::Color::DarkGray;
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
			this->menu_gropbox->Enter += gcnew System::EventHandler(this, &main_window::groupBox1_Enter);
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->exit_button->Location = System::Drawing::Point(44, 642);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(135, 30);
			this->exit_button->TabIndex = 3;
			this->exit_button->Text = L"exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &main_window::exit_button_Click);
			// 
			// second_task
			// 
			this->second_task->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->second_task->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->second_task->Location = System::Drawing::Point(44, 298);
			this->second_task->Name = L"second_task";
			this->second_task->Size = System::Drawing::Size(135, 30);
			this->second_task->TabIndex = 2;
			this->second_task->Text = L"second task";
			this->second_task->UseVisualStyleBackColor = false;
			// 
			// first_task
			// 
			this->first_task->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->first_task->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->first_task->Location = System::Drawing::Point(44, 252);
			this->first_task->Name = L"first_task";
			this->first_task->Size = System::Drawing::Size(135, 30);
			this->first_task->TabIndex = 1;
			this->first_task->Text = L"first task";
			this->first_task->UseVisualStyleBackColor = false;
			// 
			// parameters_gb
			// 
			this->parameters_gb->Controls->Add(this->max_stp_tb);
			this->parameters_gb->Controls->Add(this->label3);
			this->parameters_gb->Controls->Add(this->local_err_tb);
			this->parameters_gb->Controls->Add(this->label2);
			this->parameters_gb->Controls->Add(this->initial_step_tb);
			this->parameters_gb->Controls->Add(this->label1);
			this->parameters_gb->Location = System::Drawing::Point(229, 12);
			this->parameters_gb->Name = L"parameters_gb";
			this->parameters_gb->Size = System::Drawing::Size(256, 206);
			this->parameters_gb->TabIndex = 5;
			this->parameters_gb->TabStop = false;
			this->parameters_gb->Text = L"parameters";
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
			this->initial_step_tb->Location = System::Drawing::Point(98, 26);
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
			this->label1->Location = System::Drawing::Point(7, 27);
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
			this->help_gb->Size = System::Drawing::Size(355, 284);
			this->help_gb->TabIndex = 6;
			this->help_gb->TabStop = false;
			this->help_gb->Text = L"help";
			// 
			// value_table
			// 
			this->value_table->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->value_table->ColumnCount = 11;
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->value_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			this->value_table->ForeColor = System::Drawing::SystemColors::ControlText;
			this->value_table->Location = System::Drawing::Point(230, 388);
			this->value_table->Name = L"value_table";
			this->value_table->RowCount = 2;
			this->value_table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->value_table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->value_table->Size = System::Drawing::Size(564, 283);
			this->value_table->TabIndex = 7;
			// 
			// method_start
			// 
			this->method_start->ForeColor = System::Drawing::SystemColors::ControlText;
			this->method_start->Location = System::Drawing::Point(284, 234);
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
			this->method_clear->Location = System::Drawing::Point(284, 280);
			this->method_clear->Name = L"method_clear";
			this->method_clear->Size = System::Drawing::Size(152, 30);
			this->method_clear->TabIndex = 9;
			this->method_clear->Text = L"clear";
			this->method_clear->UseVisualStyleBackColor = true;
			this->method_clear->Click += gcnew System::EventHandler(this, &main_window::method_clear_Click);
			// 
			// main_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(1167, 666);
			this->Controls->Add(this->method_clear);
			this->Controls->Add(this->method_start);
			this->Controls->Add(this->value_table);
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
			this->TransparencyKey = System::Drawing::Color::Blue;
			this->Load += gcnew System::EventHandler(this, &main_window::main_window_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menu_gropbox->ResumeLayout(false);
			this->parameters_gb->ResumeLayout(false);
			this->parameters_gb->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: double h, x, y_true, y_numerical;
	private: double x_min, x_max;
	private: System::Void main_window_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void method_clear_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void method_start_Click(System::Object^ sender, System::EventArgs^ e);


};
}
