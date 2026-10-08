#pragma once

namespace Bakeflow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
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
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ dashboardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ customerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ productsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ordersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ reportsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageStaffToolStripMenuItem;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->dashboardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->productsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ordersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageStaffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->dashboardToolStripMenuItem,
					this->customerToolStripMenuItem, this->productsToolStripMenuItem, this->ordersToolStripMenuItem, this->reportsToolStripMenuItem,
					this->manageStaffToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1118, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// dashboardToolStripMenuItem
			// 
			this->dashboardToolStripMenuItem->Name = L"dashboardToolStripMenuItem";
			this->dashboardToolStripMenuItem->Size = System::Drawing::Size(116, 29);
			this->dashboardToolStripMenuItem->Text = L"Dashboard";
			// 
			// customerToolStripMenuItem
			// 
			this->customerToolStripMenuItem->Name = L"customerToolStripMenuItem";
			this->customerToolStripMenuItem->Size = System::Drawing::Size(105, 29);
			this->customerToolStripMenuItem->Text = L"Customer";
			// 
			// productsToolStripMenuItem
			// 
			this->productsToolStripMenuItem->Name = L"productsToolStripMenuItem";
			this->productsToolStripMenuItem->Size = System::Drawing::Size(98, 29);
			this->productsToolStripMenuItem->Text = L"Products";
			// 
			// ordersToolStripMenuItem
			// 
			this->ordersToolStripMenuItem->Name = L"ordersToolStripMenuItem";
			this->ordersToolStripMenuItem->Size = System::Drawing::Size(79, 29);
			this->ordersToolStripMenuItem->Text = L"orders";
			// 
			// reportsToolStripMenuItem
			// 
			this->reportsToolStripMenuItem->Name = L"reportsToolStripMenuItem";
			this->reportsToolStripMenuItem->Size = System::Drawing::Size(85, 29);
			this->reportsToolStripMenuItem->Text = L"reports";
			// 
			// manageStaffToolStripMenuItem
			// 
			this->manageStaffToolStripMenuItem->Name = L"manageStaffToolStripMenuItem";
			this->manageStaffToolStripMenuItem->Size = System::Drawing::Size(132, 29);
			this->manageStaffToolStripMenuItem->Text = L"manage staff";
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1118, 626);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dashboardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
