#pragma once
#include "Dashboard.h"
#include "DatabaseManager.h"
//#include <msclr/marshal_cppstd.h>
using namespace System::Runtime::InteropServices;

namespace Bakeflow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_UserName;

	private: System::Windows::Forms::TextBox^ textBox_Passwd;

	private: System::Windows::Forms::Button^ button_Login;
	private: System::Windows::Forms::Button^ button1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_UserName = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Passwd = (gcnew System::Windows::Forms::TextBox());
			this->button_Login = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->label1->Location = System::Drawing::Point(804, 259);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->label2->Location = System::Drawing::Point(807, 331);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 27);
			this->label2->TabIndex = 1;
			this->label2->Text = L"User Name :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->label3->Location = System::Drawing::Point(807, 409);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 27);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Password :";
			this->label3->Click += gcnew System::EventHandler(this, &LoginForm::label3_Click);
			// 
			// textBox_UserName
			// 
			this->textBox_UserName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)),
				static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->textBox_UserName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_UserName->Location = System::Drawing::Point(812, 361);
			this->textBox_UserName->Name = L"textBox_UserName";
			this->textBox_UserName->Size = System::Drawing::Size(270, 26);
			this->textBox_UserName->TabIndex = 1;
			this->textBox_UserName->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox_UserName_TextChanged);
			this->textBox_UserName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::textBox_UserName_KeyDown);
			// 
			// textBox_Passwd
			// 
			this->textBox_Passwd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->textBox_Passwd->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Passwd->Location = System::Drawing::Point(812, 439);
			this->textBox_Passwd->Name = L"textBox_Passwd";
			this->textBox_Passwd->Size = System::Drawing::Size(270, 26);
			this->textBox_Passwd->TabIndex = 2;
			this->textBox_Passwd->UseSystemPasswordChar = true;
			this->textBox_Passwd->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::textBox_Passwd_KeyDown);
			// 
			// button_Login
			// 
			this->button_Login->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->button_Login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Login->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Login->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->button_Login->Location = System::Drawing::Point(812, 491);
			this->button_Login->Name = L"button_Login";
			this->button_Login->Size = System::Drawing::Size(113, 34);
			this->button_Login->TabIndex = 3;
			this->button_Login->Text = L"Log in";
			this->button_Login->UseVisualStyleBackColor = false;
			this->button_Login->Click += gcnew System::EventHandler(this, &LoginForm::button_Login_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Goudy Old Style", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->button1->Location = System::Drawing::Point(969, 491);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 34);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(205)), static_cast<System::Int32>(static_cast<System::Byte>(172)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1197, 682);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_Login);
			this->Controls->Add(this->textBox_Passwd);
			this->Controls->Add(this->textBox_UserName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(94)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	}
	private: System::Void button_Login_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ sysUser = textBox_UserName->Text->Trim();
		System::String^ sysPass = textBox_Passwd->Text->Trim();

		if (System::String::IsNullOrEmpty(sysUser) || System::String::IsNullOrEmpty(sysPass)) {
			MessageBox::Show("Please enter both Username and Password.", "Validation Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Safely convert System::String^ to std::string without pulling in any Windows SDK headers
		IntPtr pUser = Marshal::StringToHGlobalAnsi(sysUser);
		IntPtr pPass = Marshal::StringToHGlobalAnsi(sysPass);

		std::string username(static_cast<const char*>(pUser.ToPointer()));
		std::string password(static_cast<const char*>(pPass.ToPointer()));

		// Free the unmanaged memory allocated by Marshal
		Marshal::FreeHGlobal(pUser);
		Marshal::FreeHGlobal(pPass);

		// Validate against SQLite
		if (DatabaseManager::ValidateUser(username, password)) {
			// Hide login form
			this->Hide();

			// Fetch native std::string role from database
			std::string nativeRole = DatabaseManager::GetUserRole(username);

		

			// Convert std::string to managed System::String^
			System::String^ role = gcnew System::String(nativeRole.c_str());


			// Pass role into dashboard
			Bakeflow::DashboardForm^ dashboard = gcnew Bakeflow::DashboardForm(role);
			dashboard->ShowDialog();

			this->Show();
			textBox_Passwd->Clear();
			textBox_UserName->Clear();
			textBox_UserName->Focus();
		}
		else {
			MessageBox::Show("Invalid Username or Password!", "Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	

		
	}








private: System::Void textBox_UserName_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		textBox_Passwd->Focus();
	}

}
private: System::Void textBox_Passwd_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter) {
		button_Login->PerformClick();
	}

}






private: System::Void textBox_UserName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}



};
}
