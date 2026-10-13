#pragma once
#include "DatabaseManager.h"

namespace Bakeflow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class ManageCustomersForm : public System::Windows::Forms::Form
	{
	public:
		ManageCustomersForm(void)
		{
			InitializeComponent();
			LoadCustomersData();
		}

	protected:
		~ManageCustomersForm()
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
		System::Windows::Forms::DataGridView^ dgvCustomers;
		System::Windows::Forms::TextBox^ txtName;
		System::Windows::Forms::TextBox^ txtPhone;
		System::Windows::Forms::TextBox^ txtEmail;
		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::Label^ lblPhone;
		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::Button^ btnAddCustomer;
		System::Windows::Forms::Button^ btnDeleteCustomer;
		System::Windows::Forms::Button^ btnBack;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnDeleteCustomer = (gcnew System::Windows::Forms::Button());
			this->btnAddCustomer = (gcnew System::Windows::Forms::Button());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblPhone = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->dgvCustomers = (gcnew System::Windows::Forms::DataGridView());
			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->BeginInit();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panelHeader->Controls->Add(this->labelTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(850, 60);
			this->panelHeader->TabIndex = 0;
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->labelTitle->Location = System::Drawing::Point(25, 15);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(227, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Manage Bakery Customers";
			// 
			// panelContent
			// 
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->panelContent->Controls->Add(this->btnBack);
			this->panelContent->Controls->Add(this->btnDeleteCustomer);
			this->panelContent->Controls->Add(this->btnAddCustomer);
			this->panelContent->Controls->Add(this->txtEmail);
			this->panelContent->Controls->Add(this->txtPhone);
			this->panelContent->Controls->Add(this->txtName);
			this->panelContent->Controls->Add(this->lblEmail);
			this->panelContent->Controls->Add(this->lblPhone);
			this->panelContent->Controls->Add(this->lblName);
			this->panelContent->Controls->Add(this->dgvCustomers);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 60);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(850, 440);
			this->panelContent->TabIndex = 1;
			// 
			// btnBack
			// 
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnBack->Location = System::Drawing::Point(680, 360);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(130, 35);
			this->btnBack->TabIndex = 9;
			this->btnBack->Text = L"Close";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &ManageCustomersForm::btnBack_Click);
			// 
			// btnDeleteCustomer
			// 
			this->btnDeleteCustomer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteCustomer->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeleteCustomer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnDeleteCustomer->Location = System::Drawing::Point(530, 360);
			this->btnDeleteCustomer->Name = L"btnDeleteCustomer";
			this->btnDeleteCustomer->Size = System::Drawing::Size(130, 35);
			this->btnDeleteCustomer->TabIndex = 8;
			this->btnDeleteCustomer->Text = L"Delete Selected";
			this->btnDeleteCustomer->UseVisualStyleBackColor = true;
			this->btnDeleteCustomer->Click += gcnew System::EventHandler(this, &ManageCustomersForm::btnDeleteCustomer_Click);
			// 
			// btnAddCustomer
			// 
			this->btnAddCustomer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnAddCustomer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCustomer->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddCustomer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->btnAddCustomer->Location = System::Drawing::Point(530, 305);
			this->btnAddCustomer->Name = L"btnAddCustomer";
			this->btnAddCustomer->Size = System::Drawing::Size(280, 40);
			this->btnAddCustomer->TabIndex = 7;
			this->btnAddCustomer->Text = L"Add New Customer";
			this->btnAddCustomer->UseVisualStyleBackColor = false;
			this->btnAddCustomer->Click += gcnew System::EventHandler(this, &ManageCustomersForm::btnAddCustomer_Click);
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEmail->Location = System::Drawing::Point(530, 205);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(280, 25);
			this->txtEmail->TabIndex = 6;
			// 
			// txtPhone
			// 
			this->txtPhone->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPhone->Location = System::Drawing::Point(530, 130);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(280, 25);
			this->txtPhone->TabIndex = 5;
			// 
			// txtName
			// 
			this->txtName->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtName->Location = System::Drawing::Point(530, 55);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(280, 25);
			this->txtName->TabIndex = 4;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEmail->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblEmail->Location = System::Drawing::Point(527, 180);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(107, 18);
			this->lblEmail->TabIndex = 3;
			this->lblEmail->Text = L"Email Address:";
			// 
			// lblPhone
			// 
			this->lblPhone->AutoSize = true;
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPhone->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblPhone->Location = System::Drawing::Point(527, 105);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(112, 18);
			this->lblPhone->TabIndex = 2;
			this->lblPhone->Text = L"Phone Number:";
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblName->Location = System::Drawing::Point(527, 30);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(107, 18);
			this->lblName->Text = L"Customer Name:";
			// 
			// dgvCustomers
			// 
			this->dgvCustomers->AllowUserToAddRows = false;
			this->dgvCustomers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCustomers->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->dgvCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCustomers->Location = System::Drawing::Point(25, 25);
			this->dgvCustomers->Name = L"dgvCustomers";
			this->dgvCustomers->ReadOnly = true;
			this->dgvCustomers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCustomers->Size = System::Drawing::Size(475, 385);
			this->dgvCustomers->TabIndex = 0;
			this->dgvCustomers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ManageCustomersForm::dgvCustomers_CellClick);
			// 
			// ManageCustomersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 500);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Name = L"ManageCustomersForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakeflow - Customer Management";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion

	private:
		System::Void LoadCustomersData() {
			dgvCustomers->DataSource = DatabaseManager::GetCustomersDataTable();
		}

		System::Void dgvCustomers_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0 && e->RowIndex < dgvCustomers->Rows->Count) {
				DataGridViewRow^ row = dgvCustomers->Rows[e->RowIndex];
				txtName->Text = row->Cells[0]->Value ? row->Cells[0]->Value->ToString() : "";
				txtPhone->Text = row->Cells[1]->Value ? row->Cells[1]->Value->ToString() : "";
				txtEmail->Text = row->Cells[2]->Value ? row->Cells[2]->Value->ToString() : "";
			}
		}

		System::Void btnAddCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ name = txtName->Text->Trim();
			System::String^ phone = txtPhone->Text->Trim();
			System::String^ email = txtEmail->Text->Trim();

			if (String::IsNullOrEmpty(name) || String::IsNullOrEmpty(phone)) {
				MessageBox::Show("Please provide at least a customer name and phone number.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			const char* pName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
			const char* pPhone = (const char*)(Marshal::StringToHGlobalAnsi(phone)).ToPointer();
			const char* pEmail = (const char*)(Marshal::StringToHGlobalAnsi(email)).ToPointer();

			std::string sName(pName);
			std::string sPhone(pPhone);
			std::string sEmail(pEmail);

			Marshal::FreeHGlobal(IntPtr((void*)pName));
			Marshal::FreeHGlobal(IntPtr((void*)pPhone));
			Marshal::FreeHGlobal(IntPtr((void*)pEmail));

			if (DatabaseManager::AddCustomer(sName, sPhone, sEmail)) {
				MessageBox::Show("Customer added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				txtName->Clear();
				txtPhone->Clear();
				txtEmail->Clear();
				LoadCustomersData();
			}
			else {
				MessageBox::Show("Failed to add customer. Phone number or name might already exist.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnDeleteCustomer_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dgvCustomers->SelectedRows->Count > 0) {
				System::String^ selectedPhone = dgvCustomers->SelectedRows[0]->Cells[1]->Value->ToString();

				System::Windows::Forms::DialogResult result = MessageBox::Show(
					"Are you sure you want to delete this customer?",
					"Confirm Deletion",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question
				);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					const char* pPhone = (const char*)(Marshal::StringToHGlobalAnsi(selectedPhone)).ToPointer();
					std::string sPhone(pPhone);
					Marshal::FreeHGlobal(IntPtr((void*)pPhone));

					if (DatabaseManager::DeleteCustomer(sPhone)) {
						MessageBox::Show("Customer deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
						LoadCustomersData();
					}
					else {
						MessageBox::Show("Failed to delete customer from database.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else {
				MessageBox::Show("Please select a customer row in the table to delete.", "Selection Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}