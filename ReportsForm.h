#pragma once
#include "DatabaseManager.h"

namespace Bakeflow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ReportsForm : public System::Windows::Forms::Form
	{
	public:
		ReportsForm(void)
		{
			InitializeComponent();
			dtpStartDate->Value = DateTime::Today;
			dtpEndDate->Value = DateTime::Today;
			chkEnableDateFilter->Checked = false;
			dtpStartDate->Enabled = false;
			dtpEndDate->Enabled = false;
			LoadReportsData();
		}

	protected:
		~ReportsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::Panel^ panelContent;

		// Summary KPI Cards
		System::Windows::Forms::Panel^ cardTotalSales;
		System::Windows::Forms::Panel^ cardTotalOrders;
		System::Windows::Forms::Label^ lblSalesHeading;
		System::Windows::Forms::Label^ lblSalesValue;
		System::Windows::Forms::Label^ lblOrdersHeading;
		System::Windows::Forms::Label^ lblOrdersValue;

		// Filter Controls
		System::Windows::Forms::GroupBox^ grpDateFilter;
		System::Windows::Forms::CheckBox^ chkEnableDateFilter;
		System::Windows::Forms::Label^ lblStartDate;
		System::Windows::Forms::DateTimePicker^ dtpStartDate;
		System::Windows::Forms::Label^ lblEndDate;
		System::Windows::Forms::DateTimePicker^ dtpEndDate;
		System::Windows::Forms::Button^ btnApplyFilter;
		System::Windows::Forms::Button^ btnResetFilter;

		// Tabs and Grids
		System::Windows::Forms::TabControl^ tabControlReports;
		System::Windows::Forms::TabPage^ tabOrders;
		System::Windows::Forms::TabPage^ tabTopSelling;
		System::Windows::Forms::TabPage^ tabDayEndClosings;
		System::Windows::Forms::DataGridView^ dgvOrders;
		System::Windows::Forms::DataGridView^ dgvTopSelling;
		System::Windows::Forms::DataGridView^ dgvDayEndClosings;

		// Bottom Action Buttons
		System::Windows::Forms::Button^ btnDayEndProcess;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::Button^ btnBack;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());

			this->cardTotalSales = (gcnew System::Windows::Forms::Panel());
			this->lblSalesHeading = (gcnew System::Windows::Forms::Label());
			this->lblSalesValue = (gcnew System::Windows::Forms::Label());
			this->cardTotalOrders = (gcnew System::Windows::Forms::Panel());
			this->lblOrdersHeading = (gcnew System::Windows::Forms::Label());
			this->lblOrdersValue = (gcnew System::Windows::Forms::Label());

			this->grpDateFilter = (gcnew System::Windows::Forms::GroupBox());
			this->chkEnableDateFilter = (gcnew System::Windows::Forms::CheckBox());
			this->lblStartDate = (gcnew System::Windows::Forms::Label());
			this->dtpStartDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblEndDate = (gcnew System::Windows::Forms::Label());
			this->dtpEndDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnApplyFilter = (gcnew System::Windows::Forms::Button());
			this->btnResetFilter = (gcnew System::Windows::Forms::Button());

			this->tabControlReports = (gcnew System::Windows::Forms::TabControl());
			this->tabOrders = (gcnew System::Windows::Forms::TabPage());
			this->dgvOrders = (gcnew System::Windows::Forms::DataGridView());
			this->tabTopSelling = (gcnew System::Windows::Forms::TabPage());
			this->dgvTopSelling = (gcnew System::Windows::Forms::DataGridView());
			this->tabDayEndClosings = (gcnew System::Windows::Forms::TabPage());
			this->dgvDayEndClosings = (gcnew System::Windows::Forms::DataGridView());

			this->btnDayEndProcess = (gcnew System::Windows::Forms::Button());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());

			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			this->cardTotalSales->SuspendLayout();
			this->cardTotalOrders->SuspendLayout();
			this->grpDateFilter->SuspendLayout();
			this->tabControlReports->SuspendLayout();
			this->tabOrders->SuspendLayout();
			this->tabTopSelling->SuspendLayout();
			this->tabDayEndClosings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOrders))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTopSelling))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDayEndClosings))->BeginInit();
			this->SuspendLayout();

			// panelHeader
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->panelHeader->Controls->Add(this->labelTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(1020, 60);
			this->panelHeader->TabIndex = 0;

			// labelTitle
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold));
			this->labelTitle->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->labelTitle->Location = System::Drawing::Point(25, 15);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(400, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Bakeflow - Reports, Analytics & Day End";

			// panelContent
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->panelContent->Controls->Add(this->cardTotalSales);
			this->panelContent->Controls->Add(this->cardTotalOrders);
			this->panelContent->Controls->Add(this->grpDateFilter);
			this->panelContent->Controls->Add(this->tabControlReports);
			this->panelContent->Controls->Add(this->btnDayEndProcess);
			this->panelContent->Controls->Add(this->btnRefresh);
			this->panelContent->Controls->Add(this->btnBack);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 60);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(1020, 580);
			this->panelContent->TabIndex = 1;

			// cardTotalSales
			this->cardTotalSales->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->cardTotalSales->Controls->Add(this->lblSalesHeading);
			this->cardTotalSales->Controls->Add(this->lblSalesValue);
			this->cardTotalSales->Location = System::Drawing::Point(25, 15);
			this->cardTotalSales->Name = L"cardTotalSales";
			this->cardTotalSales->Size = System::Drawing::Size(210, 75);
			this->cardTotalSales->TabIndex = 0;

			// lblSalesHeading
			this->lblSalesHeading->AutoSize = true;
			this->lblSalesHeading->Font = (gcnew System::Drawing::Font(L"Garamond", 10, System::Drawing::FontStyle::Bold));
			this->lblSalesHeading->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->lblSalesHeading->Location = System::Drawing::Point(15, 10);
			this->lblSalesHeading->Name = L"lblSalesHeading";
			this->lblSalesHeading->Size = System::Drawing::Size(117, 16);
			this->lblSalesHeading->TabIndex = 0;
			this->lblSalesHeading->Text = L"TOTAL REVENUE";

			// lblSalesValue
			this->lblSalesValue->AutoSize = true;
			this->lblSalesValue->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold));
			this->lblSalesValue->ForeColor = System::Drawing::Color::White;
			this->lblSalesValue->Location = System::Drawing::Point(14, 32);
			this->lblSalesValue->Name = L"lblSalesValue";
			this->lblSalesValue->Size = System::Drawing::Size(70, 27);
			this->lblSalesValue->TabIndex = 1;
			this->lblSalesValue->Text = L"$0.00";

			// cardTotalOrders
			this->cardTotalOrders->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->cardTotalOrders->Controls->Add(this->lblOrdersHeading);
			this->cardTotalOrders->Controls->Add(this->lblOrdersValue);
			this->cardTotalOrders->Location = System::Drawing::Point(250, 15);
			this->cardTotalOrders->Name = L"cardTotalOrders";
			this->cardTotalOrders->Size = System::Drawing::Size(180, 75);
			this->cardTotalOrders->TabIndex = 1;

			// lblOrdersHeading
			this->lblOrdersHeading->AutoSize = true;
			this->lblOrdersHeading->Font = (gcnew System::Drawing::Font(L"Garamond", 10, System::Drawing::FontStyle::Bold));
			this->lblOrdersHeading->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->lblOrdersHeading->Location = System::Drawing::Point(15, 10);
			this->lblOrdersHeading->Name = L"lblOrdersHeading";
			this->lblOrdersHeading->Size = System::Drawing::Size(117, 16);
			this->lblOrdersHeading->TabIndex = 0;
			this->lblOrdersHeading->Text = L"TOTAL ORDERS";

			// lblOrdersValue
			this->lblOrdersValue->AutoSize = true;
			this->lblOrdersValue->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold));
			this->lblOrdersValue->ForeColor = System::Drawing::Color::White;
			this->lblOrdersValue->Location = System::Drawing::Point(14, 32);
			this->lblOrdersValue->Name = L"lblOrdersValue";
			this->lblOrdersValue->Size = System::Drawing::Size(24, 27);
			this->lblOrdersValue->TabIndex = 1;
			this->lblOrdersValue->Text = L"0";

			// grpDateFilter
			this->grpDateFilter->Controls->Add(this->btnResetFilter);
			this->grpDateFilter->Controls->Add(this->btnApplyFilter);
			this->grpDateFilter->Controls->Add(this->dtpEndDate);
			this->grpDateFilter->Controls->Add(this->lblEndDate);
			this->grpDateFilter->Controls->Add(this->dtpStartDate);
			this->grpDateFilter->Controls->Add(this->lblStartDate);
			this->grpDateFilter->Controls->Add(this->chkEnableDateFilter);
			this->grpDateFilter->Font = (gcnew System::Drawing::Font(L"Garamond", 10, System::Drawing::FontStyle::Bold));
			this->grpDateFilter->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->grpDateFilter->Location = System::Drawing::Point(445, 10);
			this->grpDateFilter->Name = L"grpDateFilter";
			this->grpDateFilter->Size = System::Drawing::Size(550, 80);
			this->grpDateFilter->TabIndex = 2;
			this->grpDateFilter->TabStop = false;
			this->grpDateFilter->Text = L"Date Range Filter";

			// chkEnableDateFilter
			this->chkEnableDateFilter->AutoSize = true;
			this->chkEnableDateFilter->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->chkEnableDateFilter->Location = System::Drawing::Point(10, 32);
			this->chkEnableDateFilter->Name = L"chkEnableDateFilter";
			this->chkEnableDateFilter->Size = System::Drawing::Size(62, 20);
			this->chkEnableDateFilter->TabIndex = 0;
			this->chkEnableDateFilter->Text = L"Enable";
			this->chkEnableDateFilter->UseVisualStyleBackColor = true;
			this->chkEnableDateFilter->CheckedChanged += gcnew System::EventHandler(this, &ReportsForm::chkEnableDateFilter_CheckedChanged);

			// lblStartDate
			this->lblStartDate->AutoSize = true;
			this->lblStartDate->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->lblStartDate->Location = System::Drawing::Point(75, 33);
			this->lblStartDate->Name = L"lblStartDate";
			this->lblStartDate->Size = System::Drawing::Size(40, 16);
			this->lblStartDate->TabIndex = 1;
			this->lblStartDate->Text = L"From:";

			// dtpStartDate
			this->dtpStartDate->CustomFormat = L"yyyy-MM-dd";
			this->dtpStartDate->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->dtpStartDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpStartDate->Location = System::Drawing::Point(118, 30);
			this->dtpStartDate->Name = L"dtpStartDate";
			this->dtpStartDate->Size = System::Drawing::Size(100, 22);
			this->dtpStartDate->TabIndex = 2;

			// lblEndDate
			this->lblEndDate->AutoSize = true;
			this->lblEndDate->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->lblEndDate->Location = System::Drawing::Point(225, 33);
			this->lblEndDate->Name = L"lblEndDate";
			this->lblEndDate->Size = System::Drawing::Size(26, 16);
			this->lblEndDate->TabIndex = 3;
			this->lblEndDate->Text = L"To:";

			// dtpEndDate
			this->dtpEndDate->CustomFormat = L"yyyy-MM-dd";
			this->dtpEndDate->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->dtpEndDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpEndDate->Location = System::Drawing::Point(255, 30);
			this->dtpEndDate->Name = L"dtpEndDate";
			this->dtpEndDate->Size = System::Drawing::Size(100, 22);
			this->dtpEndDate->TabIndex = 4;

			// btnApplyFilter
			this->btnApplyFilter->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnApplyFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnApplyFilter->Font = (gcnew System::Drawing::Font(L"Garamond", 10, System::Drawing::FontStyle::Bold));
			this->btnApplyFilter->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnApplyFilter->Location = System::Drawing::Point(365, 27);
			this->btnApplyFilter->Name = L"btnApplyFilter";
			this->btnApplyFilter->Size = System::Drawing::Size(85, 28);
			this->btnApplyFilter->TabIndex = 5;
			this->btnApplyFilter->Text = L"Filter";
			this->btnApplyFilter->UseVisualStyleBackColor = false;
			this->btnApplyFilter->Click += gcnew System::EventHandler(this, &ReportsForm::btnApplyFilter_Click);

			// btnResetFilter
			this->btnResetFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnResetFilter->Font = (gcnew System::Drawing::Font(L"Garamond", 10));
			this->btnResetFilter->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnResetFilter->Location = System::Drawing::Point(458, 27);
			this->btnResetFilter->Name = L"btnResetFilter";
			this->btnResetFilter->Size = System::Drawing::Size(80, 28);
			this->btnResetFilter->TabIndex = 6;
			this->btnResetFilter->Text = L"All Time";
			this->btnResetFilter->UseVisualStyleBackColor = true;
			this->btnResetFilter->Click += gcnew System::EventHandler(this, &ReportsForm::btnResetFilter_Click);

			// tabControlReports
			this->tabControlReports->Controls->Add(this->tabOrders);
			this->tabControlReports->Controls->Add(this->tabTopSelling);
			this->tabControlReports->Controls->Add(this->tabDayEndClosings);
			this->tabControlReports->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->tabControlReports->Location = System::Drawing::Point(25, 105);
			this->tabControlReports->Name = L"tabControlReports";
			this->tabControlReports->SelectedIndex = 0;
			this->tabControlReports->Size = System::Drawing::Size(970, 410);
			this->tabControlReports->TabIndex = 3;

			// tabOrders
			this->tabOrders->Controls->Add(this->dgvOrders);
			this->tabOrders->Location = System::Drawing::Point(4, 26);
			this->tabOrders->Name = L"tabOrders";
			this->tabOrders->Padding = System::Windows::Forms::Padding(5);
			this->tabOrders->Size = System::Drawing::Size(962, 380);
			this->tabOrders->TabIndex = 0;
			this->tabOrders->Text = L"Sales Orders";
			this->tabOrders->UseVisualStyleBackColor = true;

			// dgvOrders
			this->dgvOrders->AllowUserToAddRows = false;
			this->dgvOrders->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvOrders->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvOrders->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvOrders->Location = System::Drawing::Point(5, 5);
			this->dgvOrders->Name = L"dgvOrders";
			this->dgvOrders->ReadOnly = true;
			this->dgvOrders->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvOrders->Size = System::Drawing::Size(952, 370);
			this->dgvOrders->TabIndex = 0;

			// tabTopSelling
			this->tabTopSelling->Controls->Add(this->dgvTopSelling);
			this->tabTopSelling->Location = System::Drawing::Point(4, 26);
			this->tabTopSelling->Name = L"tabTopSelling";
			this->tabTopSelling->Padding = System::Windows::Forms::Padding(5);
			this->tabTopSelling->Size = System::Drawing::Size(962, 380);
			this->tabTopSelling->TabIndex = 1;
			this->tabTopSelling->Text = L"Top Selling Products";
			this->tabTopSelling->UseVisualStyleBackColor = true;

			// dgvTopSelling
			this->dgvTopSelling->AllowUserToAddRows = false;
			this->dgvTopSelling->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTopSelling->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvTopSelling->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTopSelling->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvTopSelling->Location = System::Drawing::Point(5, 5);
			this->dgvTopSelling->Name = L"dgvTopSelling";
			this->dgvTopSelling->ReadOnly = true;
			this->dgvTopSelling->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTopSelling->Size = System::Drawing::Size(952, 370);
			this->dgvTopSelling->TabIndex = 0;

			// tabDayEndClosings
			this->tabDayEndClosings->Controls->Add(this->dgvDayEndClosings);
			this->tabDayEndClosings->Location = System::Drawing::Point(4, 26);
			this->tabDayEndClosings->Name = L"tabDayEndClosings";
			this->tabDayEndClosings->Padding = System::Windows::Forms::Padding(5);
			this->tabDayEndClosings->Size = System::Drawing::Size(962, 380);
			this->tabDayEndClosings->TabIndex = 2;
			this->tabDayEndClosings->Text = L"Day End Closing Logs";
			this->tabDayEndClosings->UseVisualStyleBackColor = true;

			// dgvDayEndClosings
			this->dgvDayEndClosings->AllowUserToAddRows = false;
			this->dgvDayEndClosings->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDayEndClosings->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvDayEndClosings->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDayEndClosings->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDayEndClosings->Location = System::Drawing::Point(5, 5);
			this->dgvDayEndClosings->Name = L"dgvDayEndClosings";
			this->dgvDayEndClosings->ReadOnly = true;
			this->dgvDayEndClosings->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDayEndClosings->Size = System::Drawing::Size(952, 370);
			this->dgvDayEndClosings->TabIndex = 0;

			// btnDayEndProcess
			this->btnDayEndProcess->BackColor = System::Drawing::Color::FromArgb(139, 35, 35);
			this->btnDayEndProcess->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDayEndProcess->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->btnDayEndProcess->ForeColor = System::Drawing::Color::White;
			this->btnDayEndProcess->Location = System::Drawing::Point(25, 528);
			this->btnDayEndProcess->Name = L"btnDayEndProcess";
			this->btnDayEndProcess->Size = System::Drawing::Size(240, 36);
			this->btnDayEndProcess->TabIndex = 4;
			this->btnDayEndProcess->Text = L"Perform Day End Closing";
			this->btnDayEndProcess->UseVisualStyleBackColor = false;
			this->btnDayEndProcess->Click += gcnew System::EventHandler(this, &ReportsForm::btnDayEndProcess_Click);

			// btnRefresh
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->btnRefresh->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnRefresh->Location = System::Drawing::Point(680, 528);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(150, 36);
			this->btnRefresh->TabIndex = 5;
			this->btnRefresh->Text = L"Refresh Data";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &ReportsForm::btnRefresh_Click);

			// btnBack
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Garamond", 11));
			this->btnBack->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnBack->Location = System::Drawing::Point(845, 528);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(150, 36);
			this->btnBack->TabIndex = 6;
			this->btnBack->Text = L"Back to Dashboard";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &ReportsForm::btnBack_Click);

			// ReportsForm
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1020, 640);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Name = L"ReportsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakeflow - Reports, Analytics & Day End";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->cardTotalSales->ResumeLayout(false);
			this->cardTotalSales->PerformLayout();
			this->cardTotalOrders->ResumeLayout(false);
			this->cardTotalOrders->PerformLayout();
			this->grpDateFilter->ResumeLayout(false);
			this->grpDateFilter->PerformLayout();
			this->tabControlReports->ResumeLayout(false);
			this->tabOrders->ResumeLayout(false);
			this->tabTopSelling->ResumeLayout(false);
			this->tabDayEndClosings->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOrders))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTopSelling))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDayEndClosings))->EndInit();
			this->ResumeLayout(false);
		}

	private:
		System::Void chkEnableDateFilter_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			bool isEnabled = chkEnableDateFilter->Checked;
			dtpStartDate->Enabled = isEnabled;
			dtpEndDate->Enabled = isEnabled;
		}

		System::Void LoadReportsData() {
			String^ startDate = nullptr;
			String^ endDate = nullptr;

			if (chkEnableDateFilter->Checked) {
				startDate = dtpStartDate->Value.ToString("yyyy-MM-dd");
				endDate = dtpEndDate->Value.ToString("yyyy-MM-dd");
			}

			double totalSales = 0.0;
			int totalOrders = 0;
			DatabaseManager::GetSalesSummary(startDate, endDate, totalSales, totalOrders);

			lblSalesValue->Text = "$" + totalSales.ToString("N2");
			lblOrdersValue->Text = totalOrders.ToString();

			dgvOrders->DataSource = DatabaseManager::GetSalesReportDataTable(startDate, endDate);
			dgvTopSelling->DataSource = DatabaseManager::GetTopSellingProductsDataTable(startDate, endDate);
			dgvDayEndClosings->DataSource = DatabaseManager::GetDayEndClosingsDataTable();
		}

		System::Void btnApplyFilter_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!chkEnableDateFilter->Checked) {
				chkEnableDateFilter->Checked = true;
			}
			LoadReportsData();
		}

		System::Void btnResetFilter_Click(System::Object^ sender, System::EventArgs^ e) {
			chkEnableDateFilter->Checked = false;
			LoadReportsData();
		}

		System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
			LoadReportsData();
		}

		System::Void btnDayEndProcess_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult dr = MessageBox::Show(
				"Are you sure you want to run the Day End Closing process for today?\n\nThis will snapshot today's sales, orders count, and inventory sold.",
				"Confirm Day End Closing",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);

			if (dr == System::Windows::Forms::DialogResult::Yes) {
				double daySales = 0.0;
				int dayOrders = 0;
				int dayItems = 0;

				if (DatabaseManager::PerformDayEndClosing("Admin", daySales, dayOrders, dayItems)) {
					MessageBox::Show(
						"Day End Closing Completed Successfully!\n\n" +
						"Business Date: " + DateTime::Today.ToString("yyyy-MM-dd") + "\n" +
						"Total Sales Today: $" + daySales.ToString("N2") + "\n" +
						"Total Orders: " + dayOrders.ToString() + "\n" +
						"Total Items Sold: " + dayItems.ToString(),
						"Day End Closed",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information
					);
					LoadReportsData();
					tabControlReports->SelectedTab = tabDayEndClosings;
				}
				else {
					MessageBox::Show("Failed to record Day End Closing into database.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
