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

	public ref class ManageInventoryForm : public System::Windows::Forms::Form
	{
	public:
		ManageInventoryForm(void)
		{
			InitializeComponent();
			LoadInventoryData();
		}

	protected:
		~ManageInventoryForm()
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
		System::Windows::Forms::DataGridView^ dgvInventory;
		System::Windows::Forms::TextBox^ txtProductName;
		System::Windows::Forms::TextBox^ txtStockQuantity;
		System::Windows::Forms::Label^ lblProductName;
		System::Windows::Forms::Label^ lblStockQuantity;
		System::Windows::Forms::Button^ btnUpdateStock;
		System::Windows::Forms::Button^ btnBack;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnUpdateStock = (gcnew System::Windows::Forms::Button());
			this->txtStockQuantity = (gcnew System::Windows::Forms::TextBox());
			this->txtProductName = (gcnew System::Windows::Forms::TextBox());
			this->lblStockQuantity = (gcnew System::Windows::Forms::Label());
			this->lblProductName = (gcnew System::Windows::Forms::Label());
			this->dgvInventory = (gcnew System::Windows::Forms::DataGridView());
			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventory))->BeginInit();
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
			this->labelTitle->Size = System::Drawing::Size(248, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Product Stock & Inventory";
			// 
			// panelContent
			// 
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->panelContent->Controls->Add(this->btnBack);
			this->panelContent->Controls->Add(this->btnUpdateStock);
			this->panelContent->Controls->Add(this->txtStockQuantity);
			this->panelContent->Controls->Add(this->txtProductName);
			this->panelContent->Controls->Add(this->lblStockQuantity);
			this->panelContent->Controls->Add(this->lblProductName);
			this->panelContent->Controls->Add(this->dgvInventory);
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
			this->btnBack->Location = System::Drawing::Point(530, 290);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(280, 35);
			this->btnBack->TabIndex = 6;
			this->btnBack->Text = L"Close / Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &ManageInventoryForm::btnBack_Click);
			// 
			// btnUpdateStock
			// 
			this->btnUpdateStock->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnUpdateStock->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdateStock->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdateStock->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->btnUpdateStock->Location = System::Drawing::Point(530, 235);
			this->btnUpdateStock->Name = L"btnUpdateStock";
			this->btnUpdateStock->Size = System::Drawing::Size(280, 40);
			this->btnUpdateStock->TabIndex = 5;
			this->btnUpdateStock->Text = L"Update Stock Quantity";
			this->btnUpdateStock->UseVisualStyleBackColor = false;
			this->btnUpdateStock->Click += gcnew System::EventHandler(this, &ManageInventoryForm::btnUpdateStock_Click);
			// 
			// txtStockQuantity
			// 
			this->txtStockQuantity->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStockQuantity->Location = System::Drawing::Point(530, 165);
			this->txtStockQuantity->Name = L"txtStockQuantity";
			this->txtStockQuantity->Size = System::Drawing::Size(280, 25);
			this->txtStockQuantity->TabIndex = 4;
			// 
			// txtProductName
			// 
			this->txtProductName->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtProductName->Location = System::Drawing::Point(530, 85);
			this->txtProductName->Name = L"txtProductName";
			this->txtProductName->ReadOnly = true;
			this->txtProductName->Size = System::Drawing::Size(280, 25);
			this->txtProductName->TabIndex = 3;
			// 
			// lblStockQuantity
			// 
			this->lblStockQuantity->AutoSize = true;
			this->lblStockQuantity->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStockQuantity->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblStockQuantity->Location = System::Drawing::Point(527, 140);
			this->lblStockQuantity->Name = L"lblStockQuantity";
			this->lblStockQuantity->Size = System::Drawing::Size(113, 18);
			this->lblStockQuantity->TabIndex = 2;
			this->lblStockQuantity->Text = L"New Stock Level:";
			// 
			// lblProductName
			// 
			this->lblProductName->AutoSize = true;
			this->lblProductName->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProductName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblProductName->Location = System::Drawing::Point(527, 60);
			this->lblProductName->Name = L"lblProductName";
			this->lblProductName->Size = System::Drawing::Size(103, 18);
			this->lblProductName->TabIndex = 1;
			this->lblProductName->Text = L"Product Name:";
			// 
			// dgvInventory
			// 
			this->dgvInventory->AllowUserToAddRows = false;
			this->dgvInventory->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvInventory->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->dgvInventory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvInventory->Location = System::Drawing::Point(25, 25);
			this->dgvInventory->Name = L"dgvInventory";
			this->dgvInventory->ReadOnly = true;
			this->dgvInventory->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvInventory->Size = System::Drawing::Size(475, 385);
			this->dgvInventory->TabIndex = 0;
			this->dgvInventory->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ManageInventoryForm::dgvInventory_CellClick);
			// 
			// ManageInventoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 500);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Name = L"ManageInventoryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakeflow - Inventory Management";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventory))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion

	private:
		System::Void LoadInventoryData() {
			dgvInventory->DataSource = DatabaseManager::GetInventoryDataTable();
		}

		System::Void dgvInventory_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0 && e->RowIndex < dgvInventory->Rows->Count) {
				DataGridViewRow^ row = dgvInventory->Rows[e->RowIndex];
				txtProductName->Text = row->Cells[0]->Value ? row->Cells[0]->Value->ToString() : "";
				txtStockQuantity->Text = row->Cells[3]->Value ? row->Cells[3]->Value->ToString() : "";
			}
		}

		System::Void btnUpdateStock_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ name = txtProductName->Text->Trim();
			System::String^ stockStr = txtStockQuantity->Text->Trim();

			if (String::IsNullOrEmpty(name)) {
				MessageBox::Show("Please select a product from the table first.", "Selection Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int newStock = 0;
			if (!Int32::TryParse(stockStr, newStock) || newStock < 0) {
				MessageBox::Show("Please enter a valid non-negative integer for stock quantity.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			const char* pName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
			std::string sName(pName);
			Marshal::FreeHGlobal(IntPtr((void*)pName));

			if (DatabaseManager::UpdateProductStock(sName, newStock)) {
				MessageBox::Show("Stock quantity updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadInventoryData();
			}
			else {
				MessageBox::Show("Failed to update stock in database.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}