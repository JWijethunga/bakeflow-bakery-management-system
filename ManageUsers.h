
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

	public ref class ManageUsersForm : public System::Windows::Forms::Form
	{
	public:
		ManageUsersForm(void)
		{
			InitializeComponent();
			LoadUsersData();
		}

	protected:
		~ManageUsersForm()
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
		System::Windows::Forms::DataGridView^ dgvUsers;
		System::Windows::Forms::TextBox^ txtUsername;
		System::Windows::Forms::TextBox^ txtPassword;
		System::Windows::Forms::ComboBox^ cmbRole;
		System::Windows::Forms::Label^ lblUsername;
		System::Windows::Forms::Label^ lblPassword;
		System::Windows::Forms::Label^ lblRole;
		System::Windows::Forms::Button^ btnAddUser;
		System::Windows::Forms::Button^ btnDeleteUser;
		System::Windows::Forms::Button^ btnBack;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnDeleteUser = (gcnew System::Windows::Forms::Button());
			this->btnAddUser = (gcnew System::Windows::Forms::Button());
			this->cmbRole = (gcnew System::Windows::Forms::ComboBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblRole = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->dgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->BeginInit();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panelHeader->Controls->Add(this->labelTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(800, 60);
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
			this->labelTitle->Size = System::Drawing::Size(248, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Manage System Users";
			// 
			// panelContent
			// 
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->panelContent->Controls->Add(this->btnBack);
			this->panelContent->Controls->Add(this->btnDeleteUser);
			this->panelContent->Controls->Add(this->btnAddUser);
			this->panelContent->Controls->Add(this->cmbRole);
			this->panelContent->Controls->Add(this->txtPassword);
			this->panelContent->Controls->Add(this->txtUsername);
			this->panelContent->Controls->Add(this->lblRole);
			this->panelContent->Controls->Add(this->lblPassword);
			this->panelContent->Controls->Add(this->lblUsername);
			this->panelContent->Controls->Add(this->dgvUsers);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 60);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(800, 441);
			this->panelContent->TabIndex = 1;
			// 
			// btnBack
			// 
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnBack->Location = System::Drawing::Point(630, 375);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(130, 35);
			this->btnBack->TabIndex = 9;
			this->btnBack->Text = L"Close";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &ManageUsersForm::btnBack_Click);
			// 
			// btnDeleteUser
			// 
			this->btnDeleteUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteUser->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeleteUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnDeleteUser->Location = System::Drawing::Point(480, 375);
			this->btnDeleteUser->Name = L"btnDeleteUser";
			this->btnDeleteUser->Size = System::Drawing::Size(130, 35);
			this->btnDeleteUser->TabIndex = 8;
			this->btnDeleteUser->Text = L"Delete Selected";
			this->btnDeleteUser->UseVisualStyleBackColor = true;
			this->btnDeleteUser->Click += gcnew System::EventHandler(this, &ManageUsersForm::btnDeleteUser_Click);
			// 
			// btnAddUser
			// 
			this->btnAddUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnAddUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddUser->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->btnAddUser->Location = System::Drawing::Point(480, 240);
			this->btnAddUser->Name = L"btnAddUser";
			this->btnAddUser->Size = System::Drawing::Size(280, 40);
			this->btnAddUser->TabIndex = 7;
			this->btnAddUser->Text = L"Add New User";
			this->btnAddUser->UseVisualStyleBackColor = false;
			this->btnAddUser->Click += gcnew System::EventHandler(this, &ManageUsersForm::btnAddUser_Click);
			// 
			// cmbRole
			// 
			this->cmbRole->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbRole->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbRole->FormattingEnabled = true;
			this->cmbRole->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"admin", L"staff" });
			this->cmbRole->Location = System::Drawing::Point(480, 185);
			this->cmbRole->Name = L"cmbRole";
			this->cmbRole->Size = System::Drawing::Size(280, 26);
			this->cmbRole->TabIndex = 6;
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(480, 115);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(280, 25);
			this->txtPassword->TabIndex = 5;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(480, 50);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(280, 25);
			this->txtUsername->TabIndex = 4;
			// 
			// lblRole
			// 
			this->lblRole->AutoSize = true;
			this->lblRole->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRole->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblRole->Location = System::Drawing::Point(477, 160);
			this->lblRole->Name = L"lblRole";
			this->lblRole->Size = System::Drawing::Size(78, 18);
			this->lblRole->TabIndex = 3;
			this->lblRole->Text = L"User Role:";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblPassword->Location = System::Drawing::Point(477, 90);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(75, 18);
			this->lblPassword->TabIndex = 2;
			this->lblPassword->Text = L"Password:";
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblUsername->Location = System::Drawing::Point(477, 25);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(80, 18);
			this->lblUsername->TabIndex = 1;
			this->lblUsername->Text = L"Username:";
			// 
			// dgvUsers
			// 
			this->dgvUsers->AllowUserToAddRows = false;
			this->dgvUsers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvUsers->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->dgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsers->Location = System::Drawing::Point(25, 25);
			this->dgvUsers->Name = L"dgvUsers";
			this->dgvUsers->ReadOnly = true;
			this->dgvUsers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvUsers->Size = System::Drawing::Size(420, 385);
			this->dgvUsers->TabIndex = 0;
			// 
			// ManageUsersForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 501);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Name = L"ManageUsersForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakeflow - User Management";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion

	private:
		System::Void LoadUsersData() {
			dgvUsers->DataSource = DatabaseManager::GetUsersDataTable();
			if (cmbRole->Items->Count > 0) {
				cmbRole->SelectedIndex = 0;
			}
		}

		System::Void btnAddUser_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ user = txtUsername->Text->Trim();
			System::String^ pass = txtPassword->Text->Trim();
			System::String^ role = cmbRole->SelectedItem ? cmbRole->SelectedItem->ToString() : "staff";

			if (String::IsNullOrEmpty(user) || String::IsNullOrEmpty(pass)) {
				MessageBox::Show("Please provide both username and password.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			const char* pUser = (const char*)(Marshal::StringToHGlobalAnsi(user)).ToPointer();
			const char* pPass = (const char*)(Marshal::StringToHGlobalAnsi(pass)).ToPointer();
			const char* pRole = (const char*)(Marshal::StringToHGlobalAnsi(role)).ToPointer();

			std::string sUser(pUser);
			std::string sPass(pPass);
			std::string sRole(pRole);

			Marshal::FreeHGlobal(IntPtr((void*)pUser));
			Marshal::FreeHGlobal(IntPtr((void*)pPass));
			Marshal::FreeHGlobal(IntPtr((void*)pRole));

			if (DatabaseManager::AddUser(sUser, sPass, sRole)) {
				MessageBox::Show("User added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				txtUsername->Clear();
				txtPassword->Clear();
				LoadUsersData();
			}
			else {
				MessageBox::Show("Failed to add user. Username might already exist.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnDeleteUser_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dgvUsers->SelectedRows->Count > 0) {
				System::String^ selectedUser = dgvUsers->SelectedRows[0]->Cells[0]->Value->ToString();

				if (selectedUser->Equals("admin", StringComparison::OrdinalIgnoreCase)) {
					MessageBox::Show("Cannot delete the primary admin account!", "Access Restricted", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				System::Windows::Forms::DialogResult result = MessageBox::Show(
					"Are you sure you want to delete user '" + selectedUser + "'?",
					"Confirm Deletion",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question
				);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					const char* pUser = (const char*)(Marshal::StringToHGlobalAnsi(selectedUser)).ToPointer();
					std::string sUser(pUser);
					Marshal::FreeHGlobal(IntPtr((void*)pUser));

					if (DatabaseManager::DeleteUser(sUser)) {
						MessageBox::Show("User deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
						LoadUsersData();
					}
					else {
						MessageBox::Show("Failed to delete user from database.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else {
				MessageBox::Show("Please select a user row in the table to delete.", "Selection Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}