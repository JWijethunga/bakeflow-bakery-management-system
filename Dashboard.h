#pragma once
#include "ManageUsers.h"
#include "ManageProducts.h"
#include "Customers.h"
#include "Inventory.h"
#include "POSBillingForm.h"
#include "ReportsForm.h"
#include "DatabaseManager.h"

namespace Bakeflow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DashboardForm : public System::Windows::Forms::Form
	{
	public:
		DashboardForm(System::String^ Role)
		{
			InitializeComponent();
			if (!String::IsNullOrEmpty(Role) && Role->Equals("Admin", StringComparison::OrdinalIgnoreCase)) {
				buttonManageUsers->Visible = true;
				labelUserRole->Text = L"Welcome, Admin";
			}
			else {
				buttonManageUsers->Visible = false;
				labelUserRole->Text = L"Welcome, Cashier";
			}
			LoadDailyDashboardStats();
		}

	protected:
		~DashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelSidebar;
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::Label^ labelUserRole;
		System::Windows::Forms::Button^ btnOrders;
		System::Windows::Forms::Button^ btnProducts;
		System::Windows::Forms::Button^ btnInventory;
		System::Windows::Forms::Button^ btnLogout;
		System::Windows::Forms::Button^ buttonCustomer;
		System::Windows::Forms::Button^ buttonManageUsers;
		System::Windows::Forms::Button^ btnReports;

		// Main Content Panels
		System::Windows::Forms::Panel^ panelContent;
		System::Windows::Forms::Label^ labelWelcome;
		System::Windows::Forms::Button^ btnRefreshDashboard;

		// KPI Cards
		System::Windows::Forms::Panel^ cardDailySales;
		System::Windows::Forms::Label^ lblDailySalesTitle;
		System::Windows::Forms::Label^ lblDailySalesVal;

		System::Windows::Forms::Panel^ cardDailyOrders;
		System::Windows::Forms::Label^ lblDailyOrdersTitle;
		System::Windows::Forms::Label^ lblDailyOrdersVal;

		System::Windows::Forms::Panel^ cardLowStockAlert;
		System::Windows::Forms::Label^ lblLowStockTitle;
		System::Windows::Forms::Label^ lblLowStockVal;

		// Data Tables & Headings
		System::Windows::Forms::Label^ lblTopSellingHeading;
		System::Windows::Forms::DataGridView^ dgvDailyTopSelling;

		System::Windows::Forms::Label^ lblLowStockHeading;
		System::Windows::Forms::DataGridView^ dgvLowStock;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnReports = (gcnew System::Windows::Forms::Button());
			this->buttonManageUsers = (gcnew System::Windows::Forms::Button());
			this->buttonCustomer = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnInventory = (gcnew System::Windows::Forms::Button());
			this->btnProducts = (gcnew System::Windows::Forms::Button());
			this->btnOrders = (gcnew System::Windows::Forms::Button());

			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelUserRole = (gcnew System::Windows::Forms::Label());
			this->labelTitle = (gcnew System::Windows::Forms::Label());

			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->labelWelcome = (gcnew System::Windows::Forms::Label());
			this->btnRefreshDashboard = (gcnew System::Windows::Forms::Button());

			this->cardDailySales = (gcnew System::Windows::Forms::Panel());
			this->lblDailySalesTitle = (gcnew System::Windows::Forms::Label());
			this->lblDailySalesVal = (gcnew System::Windows::Forms::Label());

			this->cardDailyOrders = (gcnew System::Windows::Forms::Panel());
			this->lblDailyOrdersTitle = (gcnew System::Windows::Forms::Label());
			this->lblDailyOrdersVal = (gcnew System::Windows::Forms::Label());

			this->cardLowStockAlert = (gcnew System::Windows::Forms::Panel());
			this->lblLowStockTitle = (gcnew System::Windows::Forms::Label());
			this->lblLowStockVal = (gcnew System::Windows::Forms::Label());

			this->lblTopSellingHeading = (gcnew System::Windows::Forms::Label());
			this->dgvDailyTopSelling = (gcnew System::Windows::Forms::DataGridView());

			this->lblLowStockHeading = (gcnew System::Windows::Forms::Label());
			this->dgvLowStock = (gcnew System::Windows::Forms::DataGridView());

			this->panelSidebar->SuspendLayout();
			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			this->cardDailySales->SuspendLayout();
			this->cardDailyOrders->SuspendLayout();
			this->cardLowStockAlert->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDailyTopSelling))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLowStock))->BeginInit();
			this->SuspendLayout();

			// 
			// panelSidebar
			// 
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->panelSidebar->Controls->Add(this->btnReports);
			this->panelSidebar->Controls->Add(this->buttonManageUsers);
			this->panelSidebar->Controls->Add(this->buttonCustomer);
			this->panelSidebar->Controls->Add(this->btnLogout);
			this->panelSidebar->Controls->Add(this->btnInventory);
			this->panelSidebar->Controls->Add(this->btnProducts);
			this->panelSidebar->Controls->Add(this->btnOrders);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Location = System::Drawing::Point(0, 0);
			this->panelSidebar->Name = L"panelSidebar";
			this->panelSidebar->Size = System::Drawing::Size(240, 720);
			this->panelSidebar->TabIndex = 0;

			// btnOrders
			this->btnOrders->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOrders->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnOrders->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnOrders->Location = System::Drawing::Point(20, 90);
			this->btnOrders->Name = L"btnOrders";
			this->btnOrders->Size = System::Drawing::Size(200, 50);
			this->btnOrders->TabIndex = 0;
			this->btnOrders->Text = L"POS / Orders";
			this->btnOrders->UseVisualStyleBackColor = true;
			this->btnOrders->Click += gcnew System::EventHandler(this, &DashboardForm::btnOrders_Click);

			// btnProducts
			this->btnProducts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProducts->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->btnProducts->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnProducts->Location = System::Drawing::Point(20, 150);
			this->btnProducts->Name = L"btnProducts";
			this->btnProducts->Size = System::Drawing::Size(200, 50);
			this->btnProducts->TabIndex = 1;
			this->btnProducts->Text = L"Products Menu";
			this->btnProducts->UseVisualStyleBackColor = true;
			this->btnProducts->Click += gcnew System::EventHandler(this, &DashboardForm::btnProducts_Click);

			// btnInventory
			this->btnInventory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInventory->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->btnInventory->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnInventory->Location = System::Drawing::Point(20, 210);
			this->btnInventory->Name = L"btnInventory";
			this->btnInventory->Size = System::Drawing::Size(200, 50);
			this->btnInventory->TabIndex = 2;
			this->btnInventory->Text = L"Inventory";
			this->btnInventory->UseVisualStyleBackColor = true;
			this->btnInventory->Click += gcnew System::EventHandler(this, &DashboardForm::btnInventory_Click);

			// buttonCustomer
			this->buttonCustomer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCustomer->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->buttonCustomer->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->buttonCustomer->Location = System::Drawing::Point(20, 270);
			this->buttonCustomer->Name = L"buttonCustomer";
			this->buttonCustomer->Size = System::Drawing::Size(200, 50);
			this->buttonCustomer->TabIndex = 4;
			this->buttonCustomer->Text = L"Customer";
			this->buttonCustomer->UseVisualStyleBackColor = true;
			this->buttonCustomer->Click += gcnew System::EventHandler(this, &DashboardForm::buttonCustomer_Click);

			// buttonManageUsers
			this->buttonManageUsers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonManageUsers->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->buttonManageUsers->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->buttonManageUsers->Location = System::Drawing::Point(20, 330);
			this->buttonManageUsers->Name = L"buttonManageUsers";
			this->buttonManageUsers->Size = System::Drawing::Size(200, 50);
			this->buttonManageUsers->TabIndex = 5;
			this->buttonManageUsers->Text = L"Manage Users";
			this->buttonManageUsers->UseVisualStyleBackColor = true;
			this->buttonManageUsers->Click += gcnew System::EventHandler(this, &DashboardForm::buttonManageUsers_Click);

			// btnReports
			this->btnReports->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReports->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->btnReports->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnReports->Location = System::Drawing::Point(20, 390);
			this->btnReports->Name = L"btnReports";
			this->btnReports->Size = System::Drawing::Size(200, 50);
			this->btnReports->TabIndex = 6;
			this->btnReports->Text = L"Reports & Day End";
			this->btnReports->UseVisualStyleBackColor = true;
			this->btnReports->Click += gcnew System::EventHandler(this, &DashboardForm::btnReports_Click);

			// btnLogout
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->btnLogout->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnLogout->Location = System::Drawing::Point(20, 640);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(200, 50);
			this->btnLogout->TabIndex = 3;
			this->btnLogout->Text = L"Log out";
			this->btnLogout->UseVisualStyleBackColor = true;
			this->btnLogout->Click += gcnew System::EventHandler(this, &DashboardForm::btnLogout_Click);

			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->panelHeader->Controls->Add(this->labelUserRole);
			this->panelHeader->Controls->Add(this->labelTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(240, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(940, 70);
			this->panelHeader->TabIndex = 1;

			// labelTitle
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold));
			this->labelTitle->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->labelTitle->Location = System::Drawing::Point(25, 20);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(262, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Bakerflow Management";

			// labelUserRole
			this->labelUserRole->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelUserRole->AutoSize = true;
			this->labelUserRole->Font = (gcnew System::Drawing::Font(L"Garamond", 13, System::Drawing::FontStyle::Regular));
			this->labelUserRole->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->labelUserRole->Location = System::Drawing::Point(750, 25);
			this->labelUserRole->Name = L"labelUserRole";
			this->labelUserRole->Size = System::Drawing::Size(125, 20);
			this->labelUserRole->TabIndex = 1;
			this->labelUserRole->Text = L"Welcome, Baker";

			// 
			// panelContent
			// 
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->panelContent->Controls->Add(this->labelWelcome);
			this->panelContent->Controls->Add(this->btnRefreshDashboard);
			this->panelContent->Controls->Add(this->cardDailySales);
			this->panelContent->Controls->Add(this->cardDailyOrders);
			this->panelContent->Controls->Add(this->cardLowStockAlert);
			this->panelContent->Controls->Add(this->lblTopSellingHeading);
			this->panelContent->Controls->Add(this->dgvDailyTopSelling);
			this->panelContent->Controls->Add(this->lblLowStockHeading);
			this->panelContent->Controls->Add(this->dgvLowStock);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(240, 70);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(940, 650);
			this->panelContent->TabIndex = 2;

			// labelWelcome
			this->labelWelcome->AutoSize = true;
			this->labelWelcome->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold));
			this->labelWelcome->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->labelWelcome->Location = System::Drawing::Point(25, 18);
			this->labelWelcome->Name = L"labelWelcome";
			this->labelWelcome->Size = System::Drawing::Size(248, 27);
			this->labelWelcome->TabIndex = 0;
			this->labelWelcome->Text = L"Today's Business Pulse";

			// btnRefreshDashboard
			this->btnRefreshDashboard->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnRefreshDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefreshDashboard->Font = (gcnew System::Drawing::Font(L"Garamond", 10, System::Drawing::FontStyle::Bold));
			this->btnRefreshDashboard->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnRefreshDashboard->Location = System::Drawing::Point(780, 16);
			this->btnRefreshDashboard->Name = L"btnRefreshDashboard";
			this->btnRefreshDashboard->Size = System::Drawing::Size(130, 32);
			this->btnRefreshDashboard->TabIndex = 1;
			this->btnRefreshDashboard->Text = L"Refresh Stats";
			this->btnRefreshDashboard->UseVisualStyleBackColor = false;
			this->btnRefreshDashboard->Click += gcnew System::EventHandler(this, &DashboardForm::btnRefreshDashboard_Click);

			// cardDailySales
			this->cardDailySales->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->cardDailySales->Controls->Add(this->lblDailySalesTitle);
			this->cardDailySales->Controls->Add(this->lblDailySalesVal);
			this->cardDailySales->Location = System::Drawing::Point(25, 60);
			this->cardDailySales->Name = L"cardDailySales";
			this->cardDailySales->Size = System::Drawing::Size(270, 90);
			this->cardDailySales->TabIndex = 2;

			this->lblDailySalesTitle->AutoSize = true;
			this->lblDailySalesTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->lblDailySalesTitle->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->lblDailySalesTitle->Location = System::Drawing::Point(15, 15);
			this->lblDailySalesTitle->Name = L"lblDailySalesTitle";
			this->lblDailySalesTitle->Size = System::Drawing::Size(157, 17);
			this->lblDailySalesTitle->TabIndex = 0;
			this->lblDailySalesTitle->Text = L"TODAY'S REVENUE";

			this->lblDailySalesVal->AutoSize = true;
			this->lblDailySalesVal->Font = (gcnew System::Drawing::Font(L"Garamond", 22, System::Drawing::FontStyle::Bold));
			this->lblDailySalesVal->ForeColor = System::Drawing::Color::White;
			this->lblDailySalesVal->Location = System::Drawing::Point(14, 40);
			this->lblDailySalesVal->Name = L"lblDailySalesVal";
			this->lblDailySalesVal->Size = System::Drawing::Size(85, 34);
			this->lblDailySalesVal->TabIndex = 1;
			this->lblDailySalesVal->Text = L"$0.00";

			// cardDailyOrders
			this->cardDailyOrders->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->cardDailyOrders->Controls->Add(this->lblDailyOrdersTitle);
			this->cardDailyOrders->Controls->Add(this->lblDailyOrdersVal);
			this->cardDailyOrders->Location = System::Drawing::Point(330, 60);
			this->cardDailyOrders->Name = L"cardDailyOrders";
			this->cardDailyOrders->Size = System::Drawing::Size(270, 90);
			this->cardDailyOrders->TabIndex = 3;

			this->lblDailyOrdersTitle->AutoSize = true;
			this->lblDailyOrdersTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->lblDailyOrdersTitle->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->lblDailyOrdersTitle->Location = System::Drawing::Point(15, 15);
			this->lblDailyOrdersTitle->Name = L"lblDailyOrdersTitle";
			this->lblDailyOrdersTitle->Size = System::Drawing::Size(147, 17);
			this->lblDailyOrdersTitle->TabIndex = 0;
			this->lblDailyOrdersTitle->Text = L"TODAY'S ORDERS";

			this->lblDailyOrdersVal->AutoSize = true;
			this->lblDailyOrdersVal->Font = (gcnew System::Drawing::Font(L"Garamond", 22, System::Drawing::FontStyle::Bold));
			this->lblDailyOrdersVal->ForeColor = System::Drawing::Color::White;
			this->lblDailyOrdersVal->Location = System::Drawing::Point(14, 40);
			this->lblDailyOrdersVal->Name = L"lblDailyOrdersVal";
			this->lblDailyOrdersVal->Size = System::Drawing::Size(29, 34);
			this->lblDailyOrdersVal->TabIndex = 1;
			this->lblDailyOrdersVal->Text = L"0";

			// cardLowStockAlert
			this->cardLowStockAlert->BackColor = System::Drawing::Color::FromArgb(139, 35, 35);
			this->cardLowStockAlert->Controls->Add(this->lblLowStockTitle);
			this->cardLowStockAlert->Controls->Add(this->lblLowStockVal);
			this->cardLowStockAlert->Location = System::Drawing::Point(635, 60);
			this->cardLowStockAlert->Name = L"cardLowStockAlert";
			this->cardLowStockAlert->Size = System::Drawing::Size(275, 90);
			this->cardLowStockAlert->TabIndex = 4;

			this->lblLowStockTitle->AutoSize = true;
			this->lblLowStockTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 11, System::Drawing::FontStyle::Bold));
			this->lblLowStockTitle->ForeColor = System::Drawing::Color::FromArgb(255, 230, 230);
			this->lblLowStockTitle->Location = System::Drawing::Point(15, 15);
			this->lblLowStockTitle->Name = L"lblLowStockTitle";
			this->lblLowStockTitle->Size = System::Drawing::Size(189, 17);
			this->lblLowStockTitle->TabIndex = 0;
			this->lblLowStockTitle->Text = L"LOW STOCK WARNING";

			this->lblLowStockVal->AutoSize = true;
			this->lblLowStockVal->Font = (gcnew System::Drawing::Font(L"Garamond", 22, System::Drawing::FontStyle::Bold));
			this->lblLowStockVal->ForeColor = System::Drawing::Color::White;
			this->lblLowStockVal->Location = System::Drawing::Point(14, 40);
			this->lblLowStockVal->Name = L"lblLowStockVal";
			this->lblLowStockVal->Size = System::Drawing::Size(125, 34);
			this->lblLowStockVal->TabIndex = 1;
			this->lblLowStockVal->Text = L"0 Item(s)";

			// lblTopSellingHeading
			this->lblTopSellingHeading->AutoSize = true;
			this->lblTopSellingHeading->Font = (gcnew System::Drawing::Font(L"Garamond", 14, System::Drawing::FontStyle::Bold));
			this->lblTopSellingHeading->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblTopSellingHeading->Location = System::Drawing::Point(25, 175);
			this->lblTopSellingHeading->Name = L"lblTopSellingHeading";
			this->lblTopSellingHeading->Size = System::Drawing::Size(258, 21);
			this->lblTopSellingHeading->TabIndex = 5;
			this->lblTopSellingHeading->Text = L"Top Selling Items Today";

			// dgvDailyTopSelling
			this->dgvDailyTopSelling->AllowUserToAddRows = false;
			this->dgvDailyTopSelling->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDailyTopSelling->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvDailyTopSelling->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDailyTopSelling->Location = System::Drawing::Point(25, 205);
			this->dgvDailyTopSelling->Name = L"dgvDailyTopSelling";
			this->dgvDailyTopSelling->ReadOnly = true;
			this->dgvDailyTopSelling->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDailyTopSelling->Size = System::Drawing::Size(425, 420);
			this->dgvDailyTopSelling->TabIndex = 6;

			// lblLowStockHeading
			this->lblLowStockHeading->AutoSize = true;
			this->lblLowStockHeading->Font = (gcnew System::Drawing::Font(L"Garamond", 14, System::Drawing::FontStyle::Bold));
			this->lblLowStockHeading->ForeColor = System::Drawing::Color::FromArgb(139, 35, 35);
			this->lblLowStockHeading->Location = System::Drawing::Point(485, 175);
			this->lblLowStockHeading->Name = L"lblLowStockHeading";
			this->lblLowStockHeading->Size = System::Drawing::Size(298, 21);
			this->lblLowStockHeading->TabIndex = 7;
			this->lblLowStockHeading->Text = L"Low Stock Inventory (<= 5 left)";

			// dgvLowStock
			this->dgvLowStock->AllowUserToAddRows = false;
			this->dgvLowStock->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvLowStock->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvLowStock->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLowStock->Location = System::Drawing::Point(485, 205);
			this->dgvLowStock->Name = L"dgvLowStock";
			this->dgvLowStock->ReadOnly = true;
			this->dgvLowStock->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvLowStock->Size = System::Drawing::Size(425, 420);
			this->dgvLowStock->TabIndex = 8;

			// DashboardForm
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelSidebar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			this->MaximizeBox = true;
			this->Name = L"DashboardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BakerFlow - Dashboard & Live Stats";

			this->panelSidebar->ResumeLayout(false);
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			this->cardDailySales->ResumeLayout(false);
			this->cardDailySales->PerformLayout();
			this->cardDailyOrders->ResumeLayout(false);
			this->cardDailyOrders->PerformLayout();
			this->cardLowStockAlert->ResumeLayout(false);
			this->cardLowStockAlert->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDailyTopSelling))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLowStock))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

	public:
		System::Void LoadDailyDashboardStats() {
			double todaySales = 0.0;
			int todayOrders = 0;
			DatabaseManager::GetDailyStats(todaySales, todayOrders);

			lblDailySalesVal->Text = "$" + todaySales.ToString("N2");
			lblDailyOrdersVal->Text = todayOrders.ToString();

			DataTable^ topSellingDt = DatabaseManager::GetDailyTopSellingProductsDataTable();
			dgvDailyTopSelling->DataSource = topSellingDt;

			// Threshold of 5 units for low stock warning
			DataTable^ lowStockDt = DatabaseManager::GetLowStockProductsDataTable(5);
			dgvLowStock->DataSource = lowStockDt;

			int lowStockCount = lowStockDt->Rows->Count;
			lblLowStockVal->Text = lowStockCount.ToString() + (lowStockCount == 1 ? " Item" : " Items");
			if (lowStockCount > 0) {
				cardLowStockAlert->BackColor = System::Drawing::Color::FromArgb(139, 35, 35);
			}
			else {
				cardLowStockAlert->BackColor = System::Drawing::Color::FromArgb(46, 117, 89); // Forest green if all in stock
				lblLowStockTitle->Text = L"INVENTORY STATUS";
				lblLowStockVal->Text = L"All Stocked";
			}
		}

	private:
		System::Void btnRefreshDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
			LoadDailyDashboardStats();
		}

		System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void buttonCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
			Bakeflow::ManageCustomersForm^ customer = gcnew Bakeflow::ManageCustomersForm();
			customer->ShowDialog();
			LoadDailyDashboardStats();
		}

		System::Void btnInventory_Click(System::Object^ sender, System::EventArgs^ e) {
			Bakeflow::ManageInventoryForm^ inventory = gcnew Bakeflow::ManageInventoryForm();
			inventory->ShowDialog();
			LoadDailyDashboardStats();
		}

		System::Void btnProducts_Click(System::Object^ sender, System::EventArgs^ e) {
			Bakeflow::ManageProductsForm^ manageproducts = gcnew Bakeflow::ManageProductsForm();
			manageproducts->ShowDialog();
			LoadDailyDashboardStats();
		}

		System::Void btnOrders_Click(System::Object^ sender, System::EventArgs^ e) {
			Bakeflow::POSBillingForm^ posForm = gcnew Bakeflow::POSBillingForm();
			posForm->ShowDialog();
			LoadDailyDashboardStats();
		}

		System::Void buttonManageUsers_Click(System::Object^ sender, System::EventArgs^ e) {
			Bakeflow::ManageUsersForm^ manageuser = gcnew Bakeflow::ManageUsersForm();
			manageuser->ShowDialog();
			LoadDailyDashboardStats();
		}

		System::Void btnReports_Click(System::Object^ sender, System::EventArgs^ e) {
			Bakeflow::ReportsForm^ reportsForm = gcnew Bakeflow::ReportsForm();
			reportsForm->ShowDialog();
			LoadDailyDashboardStats();
		}
	};
}