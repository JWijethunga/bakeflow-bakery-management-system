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

	public ref class ManageProductsForm : public System::Windows::Forms::Form
	{
	public:
		ManageProductsForm(void)
		{
			InitializeComponent();
			LoadProductsData();
		}

	protected:
		~ManageProductsForm()
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
		System::Windows::Forms::DataGridView^ dgvProducts;
		System::Windows::Forms::TextBox^ txtName;
		System::Windows::Forms::TextBox^ txtCategory;
		System::Windows::Forms::TextBox^ txtPrice;
		System::Windows::Forms::TextBox^ txtDescription;
		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::Label^ lblCategory;
		System::Windows::Forms::Label^ lblPrice;
		System::Windows::Forms::Label^ lblDescription;
		System::Windows::Forms::Button^ btnAddProduct;
		System::Windows::Forms::Button^ btnDeleteProduct;
		System::Windows::Forms::Button^ btnBack;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnDeleteProduct = (gcnew System::Windows::Forms::Button());
			this->btnAddProduct = (gcnew System::Windows::Forms::Button());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->txtPrice = (gcnew System::Windows::Forms::TextBox());
			this->txtCategory = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblDescription = (gcnew System::Windows::Forms::Label());
			this->lblPrice = (gcnew System::Windows::Forms::Label());
			this->lblCategory = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->dgvProducts = (gcnew System::Windows::Forms::DataGridView());
			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProducts))->BeginInit();
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
			this->labelTitle->Size = System::Drawing::Size(277, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Manage Product Catalog";
			// 
			// panelContent
			// 
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->panelContent->Controls->Add(this->btnBack);
			this->panelContent->Controls->Add(this->btnDeleteProduct);
			this->panelContent->Controls->Add(this->btnAddProduct);
			this->panelContent->Controls->Add(this->txtDescription);
			this->panelContent->Controls->Add(this->txtPrice);
			this->panelContent->Controls->Add(this->txtCategory);
			this->panelContent->Controls->Add(this->txtName);
			this->panelContent->Controls->Add(this->lblDescription);
			this->panelContent->Controls->Add(this->lblPrice);
			this->panelContent->Controls->Add(this->lblCategory);
			this->panelContent->Controls->Add(this->lblName);
			this->panelContent->Controls->Add(this->dgvProducts);
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
			this->btnBack->Location = System::Drawing::Point(680, 380);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(130, 35);
			this->btnBack->TabIndex = 11;
			this->btnBack->Text = L"Close";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &ManageProductsForm::btnBack_Click);
			// 
			// btnDeleteProduct
			// 
			this->btnDeleteProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteProduct->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeleteProduct->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnDeleteProduct->Location = System::Drawing::Point(530, 380);
			this->btnDeleteProduct->Name = L"btnDeleteProduct";
			this->btnDeleteProduct->Size = System::Drawing::Size(130, 35);
			this->btnDeleteProduct->TabIndex = 10;
			this->btnDeleteProduct->Text = L"Delete Selected";
			this->btnDeleteProduct->UseVisualStyleBackColor = true;
			this->btnDeleteProduct->Click += gcnew System::EventHandler(this, &ManageProductsForm::btnDeleteProduct_Click);
			// 
			// btnAddProduct
			// 
			this->btnAddProduct->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnAddProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddProduct->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddProduct->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->btnAddProduct->Location = System::Drawing::Point(530, 325);
			this->btnAddProduct->Name = L"btnAddProduct";
			this->btnAddProduct->Size = System::Drawing::Size(280, 40);
			this->btnAddProduct->TabIndex = 9;
			this->btnAddProduct->Text = L"Add New Product";
			this->btnAddProduct->UseVisualStyleBackColor = false;
			this->btnAddProduct->Click += gcnew System::EventHandler(this, &ManageProductsForm::btnAddProduct_Click);
			// 
			// txtDescription
			// 
			this->txtDescription->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDescription->Location = System::Drawing::Point(530, 240);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(280, 70);
			this->txtDescription->TabIndex = 8;
			// 
			// txtPrice
			// 
			this->txtPrice->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPrice->Location = System::Drawing::Point(530, 175);
			this->txtPrice->Name = L"txtPrice";
			this->txtPrice->Size = System::Drawing::Size(280, 25);
			this->txtPrice->TabIndex = 7;
			// 
			// txtCategory
			// 
			this->txtCategory->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCategory->Location = System::Drawing::Point(530, 110);
			this->txtCategory->Name = L"txtCategory";
			this->txtCategory->Size = System::Drawing::Size(280, 25);
			this->txtCategory->TabIndex = 6;
			// 
			// txtName
			// 
			this->txtName->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtName->Location = System::Drawing::Point(530, 45);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(280, 25);
			this->txtName->TabIndex = 5;
			// 
			// lblDescription
			// 
			this->lblDescription->AutoSize = true;
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDescription->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblDescription->Location = System::Drawing::Point(527, 215);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(91, 18);
			this->lblDescription->TabIndex = 4;
			this->lblDescription->Text = L"Description:";
			// 
			// lblPrice
			// 
			this->lblPrice->AutoSize = true;
			this->lblPrice->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblPrice->Location = System::Drawing::Point(527, 150);
			this->lblPrice->Name = L"lblPrice";
			this->lblPrice->Size = System::Drawing::Size(47, 18);
			this->lblPrice->TabIndex = 3;
			this->lblPrice->Text = L"Price:";
			// 
			// lblCategory
			// 
			this->lblCategory->AutoSize = true;
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategory->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblCategory->Location = System::Drawing::Point(527, 85);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(76, 18);
			this->lblCategory->TabIndex = 2;
			this->lblCategory->Text = L"Category:";
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->lblName->Location = System::Drawing::Point(527, 20);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(107, 18);
			this->lblName->TabIndex = 1;
			this->lblName->Text = L"Product Name:";
			// 
			// dgvProducts
			// 
			this->dgvProducts->AllowUserToAddRows = false;
			this->dgvProducts->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvProducts->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->dgvProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProducts->Location = System::Drawing::Point(25, 20);
			this->dgvProducts->Name = L"dgvProducts";
			this->dgvProducts->ReadOnly = true;
			this->dgvProducts->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvProducts->Size = System::Drawing::Size(475, 395);
			this->dgvProducts->TabIndex = 0;
			// 
			// ManageProductsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 500);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Name = L"ManageProductsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakeflow - Product Management";
			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProducts))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion

	private:
		System::Void LoadProductsData() {
			dgvProducts->DataSource = DatabaseManager::GetProductsDataTable();
		}

		System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ name = txtName->Text->Trim();
			System::String^ category = txtCategory->Text->Trim();
			System::String^ priceStr = txtPrice->Text->Trim();
			System::String^ description = txtDescription->Text->Trim();

			if (String::IsNullOrEmpty(name) || String::IsNullOrEmpty(category) || String::IsNullOrEmpty(priceStr)) {
				MessageBox::Show("Please provide product name, category, and price.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			double price = 0.0;
			if (!Double::TryParse(priceStr, price)) {
				MessageBox::Show("Price must be a valid numeric value.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			const char* pName = (const char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer();
			const char* pCat = (const char*)(Marshal::StringToHGlobalAnsi(category)).ToPointer();
			const char* pDesc = (const char*)(Marshal::StringToHGlobalAnsi(description)).ToPointer();

			std::string sName(pName);
			std::string sCat(pCat);
			std::string sDesc(pDesc);

			Marshal::FreeHGlobal(IntPtr((void*)pName));
			Marshal::FreeHGlobal(IntPtr((void*)pCat));
			Marshal::FreeHGlobal(IntPtr((void*)pDesc));

			if (DatabaseManager::AddProduct(sName, sCat, price, sDesc)) {
				MessageBox::Show("Product added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				txtName->Clear();
				txtCategory->Clear();
				txtPrice->Clear();
				txtDescription->Clear();
				LoadProductsData();
			}
			else {
				MessageBox::Show("Failed to add product. Product name might already exist.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnDeleteProduct_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dgvProducts->SelectedRows->Count > 0) {
				System::String^ selectedProduct = dgvProducts->SelectedRows[0]->Cells[0]->Value->ToString();

				System::Windows::Forms::DialogResult result = MessageBox::Show(
					"Are you sure you want to delete product '" + selectedProduct + "'?",
					"Confirm Deletion",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question
				);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					const char* pName = (const char*)(Marshal::StringToHGlobalAnsi(selectedProduct)).ToPointer();
					std::string sName(pName);
					Marshal::FreeHGlobal(IntPtr((void*)pName));

					if (DatabaseManager::DeleteProduct(sName)) {
						MessageBox::Show("Product deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
						LoadProductsData();
					}
					else {
						MessageBox::Show("Failed to delete product from database.", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else {
				MessageBox::Show("Please select a product row in the table to delete.", "Selection Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}