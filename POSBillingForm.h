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

	public ref class POSBillingForm : public System::Windows::Forms::Form
	{
	public:
		POSBillingForm(void)
		{
			InitializeComponent();
			InitializeCartDataTable();
			LoadCatalogData();
			LoadCustomersData();
		}

	protected:
		~POSBillingForm()
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

		System::Windows::Forms::DataGridView^ dgvCatalog;
		System::Windows::Forms::DataGridView^ dgvCart;

		System::Windows::Forms::ComboBox^ cmbCustomers;
		System::Windows::Forms::ComboBox^ cmbTableNumber;
		System::Windows::Forms::TextBox^ txtQuantity;
		System::Windows::Forms::Label^ lblCatalog;
		System::Windows::Forms::Label^ lblCart;
		System::Windows::Forms::Label^ lblCustomer;
		System::Windows::Forms::Label^ lblTable;
		System::Windows::Forms::Label^ lblQty;
		System::Windows::Forms::Label^ lblTotalValue;
		System::Windows::Forms::Label^ lblTotalText;

		System::Windows::Forms::Button^ btnAddToCart;
		System::Windows::Forms::Button^ btnRemoveItem;
		System::Windows::Forms::Button^ btnCheckout;
		System::Windows::Forms::Button^ btnBack;

		DataTable^ cartTable;
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnCheckout = (gcnew System::Windows::Forms::Button());
			this->btnRemoveItem = (gcnew System::Windows::Forms::Button());
			this->btnAddToCart = (gcnew System::Windows::Forms::Button());
			this->lblTotalValue = (gcnew System::Windows::Forms::Label());
			this->lblTotalText = (gcnew System::Windows::Forms::Label());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->lblQty = (gcnew System::Windows::Forms::Label());
			this->cmbTableNumber = (gcnew System::Windows::Forms::ComboBox());
			this->lblTable = (gcnew System::Windows::Forms::Label());
			this->cmbCustomers = (gcnew System::Windows::Forms::ComboBox());
			this->lblCustomer = (gcnew System::Windows::Forms::Label());
			this->lblCart = (gcnew System::Windows::Forms::Label());
			this->lblCatalog = (gcnew System::Windows::Forms::Label());
			this->dgvCart = (gcnew System::Windows::Forms::DataGridView());
			this->dgvCatalog = (gcnew System::Windows::Forms::DataGridView());

			this->panelHeader->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCatalog))->BeginInit();
			this->SuspendLayout();

			// panelHeader
			this->panelHeader->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->panelHeader->Controls->Add(this->labelTitle);
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(1000, 60);
			this->panelHeader->TabIndex = 0;

			// labelTitle
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Garamond", 18, System::Drawing::FontStyle::Bold));
			this->labelTitle->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->labelTitle->Location = System::Drawing::Point(25, 15);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(248, 27);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"Bakeflow - Point of Sale (POS)";

			// panelContent
			this->panelContent->BackColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->panelContent->Controls->Add(this->btnBack);
			this->panelContent->Controls->Add(this->btnCheckout);
			this->panelContent->Controls->Add(this->btnRemoveItem);
			this->panelContent->Controls->Add(this->btnAddToCart);
			this->panelContent->Controls->Add(this->lblTotalValue);
			this->panelContent->Controls->Add(this->lblTotalText);
			this->panelContent->Controls->Add(this->txtQuantity);
			this->panelContent->Controls->Add(this->lblQty);
			this->panelContent->Controls->Add(this->cmbTableNumber);
			this->panelContent->Controls->Add(this->lblTable);
			this->panelContent->Controls->Add(this->cmbCustomers);
			this->panelContent->Controls->Add(this->lblCustomer);
			this->panelContent->Controls->Add(this->lblCart);
			this->panelContent->Controls->Add(this->lblCatalog);
			this->panelContent->Controls->Add(this->dgvCart);
			this->panelContent->Controls->Add(this->dgvCatalog);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 60);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(1000, 540);
			this->panelContent->TabIndex = 1;

			// btnBack
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Garamond", 12));
			this->btnBack->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnBack->Location = System::Drawing::Point(825, 480);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(145, 35);
			this->btnBack->TabIndex = 15;
			this->btnBack->Text = L"Back to Dashboard";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &POSBillingForm::btnBack_Click);

			// btnCheckout
			this->btnCheckout->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnCheckout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCheckout->Font = (gcnew System::Drawing::Font(L"Garamond", 14, System::Drawing::FontStyle::Bold));
			this->btnCheckout->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnCheckout->Location = System::Drawing::Point(535, 430);
			this->btnCheckout->Name = L"btnCheckout";
			this->btnCheckout->Size = System::Drawing::Size(435, 40);
			this->btnCheckout->TabIndex = 14;
			this->btnCheckout->Text = L"Complete Checkout / Print Bill";
			this->btnCheckout->UseVisualStyleBackColor = false;
			this->btnCheckout->Click += gcnew System::EventHandler(this, &POSBillingForm::btnCheckout_Click);

			// btnRemoveItem
			this->btnRemoveItem->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRemoveItem->Font = (gcnew System::Drawing::Font(L"Garamond", 11));
			this->btnRemoveItem->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnRemoveItem->Location = System::Drawing::Point(680, 480);
			this->btnRemoveItem->Name = L"btnRemoveItem";
			this->btnRemoveItem->Size = System::Drawing::Size(130, 35);
			this->btnRemoveItem->TabIndex = 13;
			this->btnRemoveItem->Text = L"Remove Item";
			this->btnRemoveItem->UseVisualStyleBackColor = true;
			this->btnRemoveItem->Click += gcnew System::EventHandler(this, &POSBillingForm::btnRemoveItem_Click);

			// btnAddToCart
			this->btnAddToCart->BackColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->btnAddToCart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddToCart->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold));
			this->btnAddToCart->ForeColor = System::Drawing::Color::FromArgb(217, 191, 158);
			this->btnAddToCart->Location = System::Drawing::Point(355, 120);
			this->btnAddToCart->Name = L"btnAddToCart";
			this->btnAddToCart->Size = System::Drawing::Size(150, 40);
			this->btnAddToCart->TabIndex = 12;
			this->btnAddToCart->Text = L"Add to Bill >>";
			this->btnAddToCart->UseVisualStyleBackColor = false;
			this->btnAddToCart->Click += gcnew System::EventHandler(this, &POSBillingForm::btnAddToCart_Click);

			// lblTotalValue
			this->lblTotalValue->Font = (gcnew System::Drawing::Font(L"Garamond", 16, System::Drawing::FontStyle::Bold));
			this->lblTotalValue->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblTotalValue->Location = System::Drawing::Point(810, 390);
			this->lblTotalValue->Name = L"lblTotalValue";
			this->lblTotalValue->Size = System::Drawing::Size(160, 25);
			this->lblTotalValue->TabIndex = 11;
			this->lblTotalValue->Text = L"$0.00";
			this->lblTotalValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;

			// lblTotalText
			this->lblTotalText->AutoSize = true;
			this->lblTotalText->Font = (gcnew System::Drawing::Font(L"Garamond", 16, System::Drawing::FontStyle::Bold));
			this->lblTotalText->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblTotalText->Location = System::Drawing::Point(530, 390);
			this->lblTotalText->Name = L"lblTotalText";
			this->lblTotalText->Size = System::Drawing::Size(130, 24);
			this->lblTotalText->TabIndex = 10;
			this->lblTotalText->Text = L"Total Amount:";

			// txtQuantity
			this->txtQuantity->Font = (gcnew System::Drawing::Font(L"Garamond", 12));
			this->txtQuantity->Location = System::Drawing::Point(355, 75);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(150, 25);
			this->txtQuantity->TabIndex = 9;
			this->txtQuantity->Text = L"1";

			// lblQty
			this->lblQty->AutoSize = true;
			this->lblQty->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold));
			this->lblQty->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblQty->Location = System::Drawing::Point(352, 50);
			this->lblQty->Name = L"lblQty";
			this->lblQty->Size = System::Drawing::Size(68, 18);
			this->lblQty->TabIndex = 8;
			this->lblQty->Text = L"Quantity:";

			// cmbTableNumber
			this->cmbTableNumber->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTableNumber->Font = (gcnew System::Drawing::Font(L"Garamond", 12));
			this->cmbTableNumber->FormattingEnabled = true;
			this->cmbTableNumber->Items->Add(L"Takeaway / Counter");
			this->cmbTableNumber->Items->Add(L"Table 01");
			this->cmbTableNumber->Items->Add(L"Table 02");
			this->cmbTableNumber->Items->Add(L"Table 03");
			this->cmbTableNumber->Items->Add(L"Table 04");
			this->cmbTableNumber->Items->Add(L"Table 05");
			this->cmbTableNumber->Items->Add(L"Table 06");
			this->cmbTableNumber->Items->Add(L"VIP Table");
			this->cmbTableNumber->Location = System::Drawing::Point(755, 30);
			this->cmbTableNumber->Name = L"cmbTableNumber";
			this->cmbTableNumber->Size = System::Drawing::Size(215, 26);
			this->cmbTableNumber->TabIndex = 7;
			this->cmbTableNumber->SelectedIndex = 0;

			// lblTable
			this->lblTable->AutoSize = true;
			this->lblTable->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold));
			this->lblTable->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblTable->Location = System::Drawing::Point(660, 33);
			this->lblTable->Name = L"lblTable";
			this->lblTable->Size = System::Drawing::Size(89, 18);
			this->lblTable->TabIndex = 6;
			this->lblTable->Text = L"Dine-in / Tbl:";

			// cmbCustomers
			this->cmbCustomers->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCustomers->Font = (gcnew System::Drawing::Font(L"Garamond", 12));
			this->cmbCustomers->FormattingEnabled = true;
			this->cmbCustomers->Items->Add(L"Walk-in");
			this->cmbCustomers->Location = System::Drawing::Point(145, 30);
			this->cmbCustomers->Name = L"cmbCustomers";
			this->cmbCustomers->Size = System::Drawing::Size(200, 26);
			this->cmbCustomers->TabIndex = 5;
			this->cmbCustomers->SelectedIndex = 0;

			// lblCustomer
			this->lblCustomer->AutoSize = true;
			this->lblCustomer->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold));
			this->lblCustomer->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblCustomer->Location = System::Drawing::Point(25, 33);
			this->lblCustomer->Name = L"lblCustomer";
			this->lblCustomer->Size = System::Drawing::Size(114, 18);
			this->lblCustomer->TabIndex = 4;
			this->lblCustomer->Text = L"Customer/Walk:";

			// lblCart
			this->lblCart->AutoSize = true;
			this->lblCart->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold));
			this->lblCart->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblCart->Location = System::Drawing::Point(532, 75);
			this->lblCart->Name = L"lblCart";
			this->lblCart->Size = System::Drawing::Size(111, 18);
			this->lblCart->TabIndex = 3;
			this->lblCart->Text = L"Current Bill Cart";

			// lblCatalog
			this->lblCatalog->AutoSize = true;
			this->lblCatalog->Font = (gcnew System::Drawing::Font(L"Garamond", 12, System::Drawing::FontStyle::Bold));
			this->lblCatalog->ForeColor = System::Drawing::Color::FromArgb(74, 43, 28);
			this->lblCatalog->Location = System::Drawing::Point(25, 75);
			this->lblCatalog->Name = L"lblCatalog";
			this->lblCatalog->Size = System::Drawing::Size(117, 18);
			this->lblCatalog->TabIndex = 2;
			this->lblCatalog->Text = L"Product Catalog";

			// dgvCart
			this->dgvCart->AllowUserToAddRows = false;
			this->dgvCart->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCart->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvCart->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCart->Location = System::Drawing::Point(535, 100);
			this->dgvCart->Name = L"dgvCart";
			this->dgvCart->ReadOnly = true;
			this->dgvCart->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCart->Size = System::Drawing::Size(435, 275);
			this->dgvCart->TabIndex = 1;

			// dgvCatalog
			this->dgvCatalog->AllowUserToAddRows = false;
			this->dgvCatalog->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCatalog->BackgroundColor = System::Drawing::Color::FromArgb(240, 225, 205);
			this->dgvCatalog->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCatalog->Location = System::Drawing::Point(25, 100);
			this->dgvCatalog->Name = L"dgvCatalog";
			this->dgvCatalog->ReadOnly = true;
			this->dgvCatalog->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCatalog->Size = System::Drawing::Size(315, 415);
			this->dgvCatalog->TabIndex = 0;

			// POSBillingForm
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 600);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panelHeader);
			this->Name = L"POSBillingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakeflow - POS Terminal";

			this->panelHeader->ResumeLayout(false);
			this->panelHeader->PerformLayout();
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCatalog))->EndInit();
			this->ResumeLayout(false);
		}

	private:
		System::Void LoadCatalogData() {
			dgvCatalog->DataSource = DatabaseManager::GetInventoryDataTable();
		}

		System::Void LoadCustomersData() {
			DataTable^ custDt = DatabaseManager::GetCustomersDataTable();
			cmbCustomers->Items->Clear();
			for each (DataRow ^ r in custDt->Rows) {
				String^ cName = r["Customer Name"] ? r["Customer Name"]->ToString() : "";
				if (!String::IsNullOrEmpty(cName)) {
					cmbCustomers->Items->Add(cName);
				}
			}
			if (cmbCustomers->Items->Count == 0) {
				cmbCustomers->Items->Add(L"Walk-in");
			}
			cmbCustomers->SelectedIndex = 0;
		}

		System::Void InitializeCartDataTable() {
			cartTable = gcnew DataTable();
			cartTable->Columns->Add("Item Name", String::typeid);
			cartTable->Columns->Add("Price", Double::typeid);
			cartTable->Columns->Add("Qty", Int32::typeid);
			cartTable->Columns->Add("Subtotal", Double::typeid);
			dgvCart->DataSource = cartTable;
		}

		System::Void CalculateCartTotal() {
			double total = 0.0;
			for each (DataRow ^ row in cartTable->Rows) {
				total += safe_cast<double>(row["Subtotal"]);
			}
			lblTotalValue->Text = "$" + total.ToString("N2");
		}

		System::Void btnAddToCart_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dgvCatalog->SelectedRows->Count == 0) {
				MessageBox::Show("Please select an item from the product catalog.", "Selection Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int qty = 1;
			if (!Int32::TryParse(txtQuantity->Text->Trim(), qty) || qty <= 0) {
				MessageBox::Show("Please enter a valid positive quantity.", "Invalid Quantity", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			DataGridViewRow^ selRow = dgvCatalog->SelectedRows[0];
			String^ itemName = selRow->Cells["Product Name"]->Value->ToString();
			double price = safe_cast<double>(selRow->Cells["Price"]->Value);
			int availableStock = safe_cast<int>(selRow->Cells["Stock Quantity"]->Value);

			int alreadyInCart = 0;
			DataRow^ existingRow = nullptr;
			for each (DataRow ^ row in cartTable->Rows) {
				if (row["Item Name"]->ToString()->Equals(itemName, StringComparison::OrdinalIgnoreCase)) {
					alreadyInCart = safe_cast<int>(row["Qty"]);
					existingRow = row;
					break;
				}
			}

			if (alreadyInCart + qty > availableStock) {
				MessageBox::Show("Insufficient stock! Available: " + availableStock + ", already in cart: " + alreadyInCart, "Stock Limit", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (existingRow != nullptr) {
				int newQty = alreadyInCart + qty;
				existingRow["Qty"] = newQty;
				existingRow["Subtotal"] = price * newQty;
			}
			else {
				cartTable->Rows->Add(itemName, price, qty, price * qty);
			}

			CalculateCartTotal();
			txtQuantity->Text = "1";
		}

		System::Void btnRemoveItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dgvCart->SelectedRows->Count > 0) {
				int index = dgvCart->SelectedRows[0]->Index;
				cartTable->Rows->RemoveAt(index);
				CalculateCartTotal();
			}
			else {
				MessageBox::Show("Please select an item in the bill cart to remove.", "Selection Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		System::Void btnCheckout_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cartTable->Rows->Count == 0) {
				MessageBox::Show("Cart is empty! Please add items before checking out.", "Empty Cart", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			double total = 0.0;
			for each (DataRow ^ row in cartTable->Rows) {
				total += safe_cast<double>(row["Subtotal"]);
			}

			String^ customerName = cmbCustomers->SelectedItem ? cmbCustomers->SelectedItem->ToString() : "Walk-in";
			String^ tableNo = cmbTableNumber->SelectedItem ? cmbTableNumber->SelectedItem->ToString() : "Takeaway / Counter";

			if (DatabaseManager::CompleteCheckout(customerName, tableNo, total, cartTable)) {
				MessageBox::Show("Order completed successfully!\nCustomer: " + customerName + "\nTable: " + tableNo + "\nTotal: $" + total.ToString("N2"), "Checkout Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);
				cartTable->Clear();
				CalculateCartTotal();
				LoadCatalogData();
			}
			else {
				MessageBox::Show("Failed to process transaction in database.", "Transaction Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}