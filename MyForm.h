#pragma once

namespace Bakeflow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ BakeFlow;
	private: System::Windows::Forms::Label^ UserName;
	private: System::Windows::Forms::Label^ Passwd;
	private: System::Windows::Forms::TextBox^ TextBox_UserName;
	private: System::Windows::Forms::TextBox^ textBox_Passwd;
	protected:

	protected:

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
			this->BakeFlow = (gcnew System::Windows::Forms::Label());
			this->UserName = (gcnew System::Windows::Forms::Label());
			this->Passwd = (gcnew System::Windows::Forms::Label());
			this->TextBox_UserName = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Passwd = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// BakeFlow
			// 
			this->BakeFlow->AutoSize = true;
			this->BakeFlow->Location = System::Drawing::Point(374, 79);
			this->BakeFlow->Name = L"BakeFlow";
			this->BakeFlow->Size = System::Drawing::Size(79, 20);
			this->BakeFlow->TabIndex = 0;
			this->BakeFlow->Text = L"BakeFlow";
			this->BakeFlow->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// UserName
			//   
			this->UserName->AutoSize = true;
			this->UserName->Location = System::Drawing::Point(374, 161);
			this->UserName->Name = L"UserName";
			this->UserName->Size = System::Drawing::Size(89, 20);
			this->UserName->TabIndex = 0;
			this->UserName->Text = L"User Name";
			this->UserName->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// Passwd
			// 
			this->Passwd->AutoSize = true;
			this->Passwd->Location = System::Drawing::Point(374, 257);
			this->Passwd->Name = L"Passwd";
			this->Passwd->Size = System::Drawing::Size(78, 20);
			this->Passwd->TabIndex = 0;
			this->Passwd->Text = L"Password";
			this->Passwd->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// TextBox_UserName
			// 
			this->TextBox_UserName->Location = System::Drawing::Point(378, 194);
			this->TextBox_UserName->Name = L"TextBox_UserName";
			this->TextBox_UserName->Size = System::Drawing::Size(100, 26);
			this->TextBox_UserName->TabIndex = 1;
			// 
			// textBox_Passwd
			// 
			this->textBox_Passwd->Location = System::Drawing::Point(378, 305);
			this->textBox_Passwd->Name = L"textBox_Passwd";
			this->textBox_Passwd->Size = System::Drawing::Size(100, 26);
			this->textBox_Passwd->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 531);
			this->Controls->Add(this->textBox_Passwd);
			this->Controls->Add(this->TextBox_UserName);
			this->Controls->Add(this->Passwd);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->BakeFlow);
			this->Name = L"MyForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
