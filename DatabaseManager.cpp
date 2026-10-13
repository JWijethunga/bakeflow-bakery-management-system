#include "DatabaseManager.h"
#include "sqlite3.h"
#include <string>

#using <System.Data.dll>

namespace Bakeflow {

	using namespace System;
	using namespace System::Data;
	using namespace System::Runtime::InteropServices;

	// ==========================================
	// 1. INITIALIZATION & SCHEMA SETUP
	// ==========================================
	bool DatabaseManager::Initialize() {
		sqlite3* db = nullptr;

		if (sqlite3_open("bakery_system.db", &db) != SQLITE_OK) {
			if (db) { sqlite3_close(db); }
			return false;
		}

		const char* schemaSql = R"(
			CREATE TABLE IF NOT EXISTS Users (
				ID INTEGER PRIMARY KEY AUTOINCREMENT,
				Username TEXT UNIQUE NOT NULL,
				Password TEXT NOT NULL,
				Role TEXT NOT NULL DEFAULT 'Cashier'
			);

			CREATE TABLE IF NOT EXISTS Products (
				ID INTEGER PRIMARY KEY AUTOINCREMENT,
				Name TEXT NOT NULL UNIQUE,
				Category TEXT NOT NULL,
				Price REAL NOT NULL,
				Description TEXT,
				stock INTEGER NOT NULL DEFAULT 0
			);

			CREATE TABLE IF NOT EXISTS Customers (
				ID INTEGER PRIMARY KEY AUTOINCREMENT,
				Name TEXT NOT NULL,
				Phone TEXT UNIQUE,
				email TEXT
			);

			CREATE TABLE IF NOT EXISTS Orders (
				ID INTEGER PRIMARY KEY AUTOINCREMENT,
				CustomerID INTEGER,
				OrderDate TEXT NOT NULL,
				TotalAmount REAL NOT NULL,
				FOREIGN KEY(CustomerID) REFERENCES Customers(ID)
			);

			CREATE TABLE IF NOT EXISTS OrderItems (
				ID INTEGER PRIMARY KEY AUTOINCREMENT,
				OrderID INTEGER NOT NULL,
				ProductID INTEGER NOT NULL,
				Quantity INTEGER NOT NULL,
				Price REAL NOT NULL,
				Subtotal REAL NOT NULL,
				FOREIGN KEY(OrderID) REFERENCES Orders(ID),
				FOREIGN KEY(ProductID) REFERENCES Products(ID)
			);

			CREATE TABLE IF NOT EXISTS DayEndClosings (
				ID INTEGER PRIMARY KEY AUTOINCREMENT,
				ClosingDate TEXT NOT NULL,
				ClosedAt TEXT NOT NULL,
				TotalSales REAL NOT NULL,
				TotalOrders INTEGER NOT NULL,
				TotalItemsSold INTEGER NOT NULL,
				ClosedBy TEXT NOT NULL
			);

			INSERT OR IGNORE INTO Users (Username, Password, Role) VALUES ('admin', '1234', 'Admin');
			INSERT OR IGNORE INTO Customers (ID, Name, Phone, email) VALUES (1, 'Walk-in', '000', '-');
			INSERT OR IGNORE INTO Products (Name, Category, Price, Description, stock) VALUES ('Butter Croissant', 'Pastry', 2.50, 'Freshly baked butter croissant', 25);
			INSERT OR IGNORE INTO Products (Name, Category, Price, Description, stock) VALUES ('Chocolate Muffin', 'Bakery', 3.00, 'Rich chocolate chip muffin', 15);
			INSERT OR IGNORE INTO Products (Name, Category, Price, Description, stock) VALUES ('Sourdough Loaf', 'Bread', 5.50, 'Artisanal crusty sourdough', 10);
		)";

		char* errMsg = nullptr;
		int rc = sqlite3_exec(db, schemaSql, nullptr, nullptr, &errMsg);

		if (errMsg) {
			sqlite3_free(errMsg);
		}

		sqlite3_close(db);
		return (rc == SQLITE_OK);
	}

	// ==========================================
	// 2. USER AUTHENTICATION & MANAGEMENT
	// ==========================================
	bool DatabaseManager::ValidateUser(const std::string& username, const std::string& password) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool isValid = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT ID FROM Users WHERE LOWER(Username) = LOWER(?) AND Password = ?;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_ROW) {
					isValid = true;
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return isValid;
	}

	std::string DatabaseManager::GetUserRole(const std::string& username) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		std::string role = "Cashier";

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT Role FROM Users WHERE LOWER(Username) = LOWER(?);";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
				if (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* r = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					if (r) {
						role = std::string(r);
					}
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return role;
	}

	bool DatabaseManager::AddUser(const std::string& username, const std::string& password, const std::string& role) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "INSERT INTO Users (Username, Password, Role) VALUES (?, ?, ?);";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_text(stmt, 3, role.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = true;
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	bool DatabaseManager::DeleteUser(const std::string& username) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "DELETE FROM Users WHERE LOWER(Username) = LOWER(?);";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = (sqlite3_changes(db) > 0);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	DataTable^ DatabaseManager::GetUsersDataTable() {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Username", String::typeid);
		dt->Columns->Add("Role", String::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT Username, Role FROM Users;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* u = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					const char* r = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

					dt->Rows->Add(
						gcnew String(u ? u : ""),
						gcnew String(r ? r : "")
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	// ==========================================
	// 3. PRODUCT CATALOG MANAGEMENT
	// ==========================================
	DataTable^ DatabaseManager::GetProductsDataTable() {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Product Name", String::typeid);
		dt->Columns->Add("Category", String::typeid);
		dt->Columns->Add("Price", Double::typeid);
		dt->Columns->Add("Description", String::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT Name, Category, Price, Description FROM Products;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					const char* cat = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					double price = sqlite3_column_double(stmt, 2);
					const char* desc = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

					dt->Rows->Add(
						gcnew String(name ? name : ""),
						gcnew String(cat ? cat : ""),
						price,
						gcnew String(desc ? desc : "")
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	bool DatabaseManager::AddProduct(const std::string& name, const std::string& category, double price, const std::string& description) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "INSERT INTO Products (Name, Category, Price, Description, stock) VALUES (?, ?, ?, ?, 0);";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_text(stmt, 2, category.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_double(stmt, 3, price);
				sqlite3_bind_text(stmt, 4, description.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = true;
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	bool DatabaseManager::DeleteProduct(const std::string& name) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "DELETE FROM Products WHERE Name = ?;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = (sqlite3_changes(db) > 0);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	// ==========================================
	// 4. INVENTORY MANAGEMENT
	// ==========================================
	DataTable^ DatabaseManager::GetInventoryDataTable() {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Product Name", String::typeid);
		dt->Columns->Add("Category", String::typeid);
		dt->Columns->Add("Price", Double::typeid);
		dt->Columns->Add("Stock Quantity", Int32::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT Name, Category, Price, stock FROM Products;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					const char* cat = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					double price = sqlite3_column_double(stmt, 2);
					int stock = sqlite3_column_int(stmt, 3);

					dt->Rows->Add(
						gcnew String(name ? name : ""),
						gcnew String(cat ? cat : ""),
						price,
						stock
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	int DatabaseManager::GetProductStock(const std::string& productName) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		int stock = 0;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			std::string sql = "SELECT stock FROM Products WHERE Name = ?;";
			if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, productName.c_str(), -1, SQLITE_TRANSIENT);
				if (sqlite3_step(stmt) == SQLITE_ROW) {
					stock = sqlite3_column_int(stmt, 0);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return stock;
	}

	bool DatabaseManager::UpdateProductStock(const std::string& productName, int newStock) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			std::string sql = "UPDATE Products SET stock = ? WHERE Name = ?;";
			if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_int(stmt, 1, newStock);
				sqlite3_bind_text(stmt, 2, productName.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = (sqlite3_changes(db) > 0);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	// ==========================================
	// 5. CUSTOMER FUNCTIONS
	// ==========================================
	DataTable^ DatabaseManager::GetCustomersDataTable() {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Customer Name", String::typeid);
		dt->Columns->Add("Phone Number", String::typeid);
		dt->Columns->Add("Email Address", String::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT Name, Phone, email FROM Customers;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					const char* phone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					const char* email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

					dt->Rows->Add(
						gcnew String(name ? name : ""),
						gcnew String(phone ? phone : ""),
						gcnew String(email ? email : "")
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	bool DatabaseManager::AddCustomer(const std::string& name, const std::string& phone, const std::string& email) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "INSERT INTO Customers (Name, Phone, email) VALUES (?, ?, ?);";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_text(stmt, 2, phone.c_str(), -1, SQLITE_TRANSIENT);
				sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = true;
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	bool DatabaseManager::DeleteCustomer(const std::string& phone) {
		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;
		bool success = false;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "DELETE FROM Customers WHERE Phone = ?;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, phone.c_str(), -1, SQLITE_TRANSIENT);

				if (sqlite3_step(stmt) == SQLITE_DONE) {
					success = (sqlite3_changes(db) > 0);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return success;
	}

	// ==========================================
	// 6. CHECKOUT & TRANSACTION LOGGING
	// ==========================================
	bool DatabaseManager::CompleteCheckout(System::String^ customerName, System::String^ tableNo, double totalAmount, System::Data::DataTable^ cartTable) {
		sqlite3* db = nullptr;
		if (sqlite3_open("bakery_system.db", &db) != SQLITE_OK) {
			if (db) sqlite3_close(db);
			return false;
		}

		sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

		IntPtr pCustName = Marshal::StringToHGlobalAnsi(customerName ? customerName : "");
		std::string sCustomerName(static_cast<const char*>(pCustName.ToPointer()));
		Marshal::FreeHGlobal(pCustName);

		int customerId = 1;
		sqlite3_stmt* stmtCust = nullptr;
		if (sqlite3_prepare_v2(db, "SELECT ID FROM Customers WHERE Name = ?;", -1, &stmtCust, nullptr) == SQLITE_OK) {
			sqlite3_bind_text(stmtCust, 1, sCustomerName.c_str(), -1, SQLITE_TRANSIENT);
			if (sqlite3_step(stmtCust) == SQLITE_ROW) {
				customerId = sqlite3_column_int(stmtCust, 0);
			}
			sqlite3_finalize(stmtCust);
		}

		sqlite3_stmt* stmtOrder = nullptr;
		if (sqlite3_prepare_v2(db, "INSERT INTO Orders (CustomerID, OrderDate, TotalAmount) VALUES (?, datetime('now', 'localtime'), ?);", -1, &stmtOrder, nullptr) != SQLITE_OK) {
			sqlite3_exec(db, "ROLLBACK;", nullptr, nullptr, nullptr);
			sqlite3_close(db);
			return false;
		}

		sqlite3_bind_int(stmtOrder, 1, customerId);
		sqlite3_bind_double(stmtOrder, 2, totalAmount);
		sqlite3_step(stmtOrder);
		long long orderId = sqlite3_last_insert_rowid(db);
		sqlite3_finalize(stmtOrder);

		for each (System::Data::DataRow ^ row in cartTable->Rows) {
			System::String^ sItemName = row["Item Name"] ? row["Item Name"]->ToString() : "";
			IntPtr pItemName = Marshal::StringToHGlobalAnsi(sItemName);
			std::string itemName(static_cast<const char*>(pItemName.ToPointer()));
			Marshal::FreeHGlobal(pItemName);
			double price = safe_cast<double>(row["Price"]);
			int qty = safe_cast<int>(row["Qty"]);
			double subtotal = safe_cast<double>(row["Subtotal"]);

			int productId = -1;
			int currentStock = 0;
			sqlite3_stmt* stmtProd = nullptr;
			if (sqlite3_prepare_v2(db, "SELECT ID, stock FROM Products WHERE Name = ?;", -1, &stmtProd, nullptr) == SQLITE_OK) {
				sqlite3_bind_text(stmtProd, 1, itemName.c_str(), -1, SQLITE_TRANSIENT);
				if (sqlite3_step(stmtProd) == SQLITE_ROW) {
					productId = sqlite3_column_int(stmtProd, 0);
					currentStock = sqlite3_column_int(stmtProd, 1);
				}
				sqlite3_finalize(stmtProd);
			}

			if (productId != -1) {
				sqlite3_stmt* stmtItem = nullptr;
				if (sqlite3_prepare_v2(db, "INSERT INTO OrderItems (OrderID, ProductID, Quantity, Price, Subtotal) VALUES (?, ?, ?, ?, ?);", -1, &stmtItem, nullptr) == SQLITE_OK) {
					sqlite3_bind_int(stmtItem, 1, (int)orderId);
					sqlite3_bind_int(stmtItem, 2, productId);
					sqlite3_bind_int(stmtItem, 3, qty);
					sqlite3_bind_double(stmtItem, 4, price);
					sqlite3_bind_double(stmtItem, 5, subtotal);
					sqlite3_step(stmtItem);
					sqlite3_finalize(stmtItem);
				}

				int newStock = (currentStock >= qty) ? (currentStock - qty) : 0;
				sqlite3_stmt* stmtStock = nullptr;
				if (sqlite3_prepare_v2(db, "UPDATE Products SET stock = ? WHERE ID = ?;", -1, &stmtStock, nullptr) == SQLITE_OK) {
					sqlite3_bind_int(stmtStock, 1, newStock);
					sqlite3_bind_int(stmtStock, 2, productId);
					sqlite3_step(stmtStock);
					sqlite3_finalize(stmtStock);
				}
			}
		}

		sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);
		sqlite3_close(db);
		return true;
	}

	// ==========================================
	// 7. REPORTS & ANALYTICS
	// ==========================================
	DataTable^ DatabaseManager::GetSalesReportDataTable() {
		return GetSalesReportDataTable(nullptr, nullptr);
	}

	DataTable^ DatabaseManager::GetSalesReportDataTable(System::String^ startDate, System::String^ endDate) {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Order ID", Int32::typeid);
		dt->Columns->Add("Customer Name", String::typeid);
		dt->Columns->Add("Order Date", String::typeid);
		dt->Columns->Add("Total Amount ($)", Double::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			std::string sql = "SELECT o.ID, c.Name, o.OrderDate, o.TotalAmount "
							  "FROM Orders o "
							  "LEFT JOIN Customers c ON o.CustomerID = c.ID ";
			
			bool hasDateFilter = (!String::IsNullOrEmpty(startDate) && !String::IsNullOrEmpty(endDate));
			if (hasDateFilter) {
				sql += "WHERE date(o.OrderDate) BETWEEN ? AND ? ";
			}
			sql += "ORDER BY o.ID DESC;";

			if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				if (hasDateFilter) {
					IntPtr pStart = Marshal::StringToHGlobalAnsi(startDate);
					IntPtr pEnd = Marshal::StringToHGlobalAnsi(endDate);
					sqlite3_bind_text(stmt, 1, static_cast<const char*>(pStart.ToPointer()), -1, SQLITE_TRANSIENT);
					sqlite3_bind_text(stmt, 2, static_cast<const char*>(pEnd.ToPointer()), -1, SQLITE_TRANSIENT);
					Marshal::FreeHGlobal(pStart);
					Marshal::FreeHGlobal(pEnd);
				}

				while (sqlite3_step(stmt) == SQLITE_ROW) {
					int orderId = sqlite3_column_int(stmt, 0);
					const char* custName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					const char* orderDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
					double totalAmount = sqlite3_column_double(stmt, 3);

					dt->Rows->Add(
						orderId,
						gcnew String(custName ? custName : "Walk-in"),
						gcnew String(orderDate ? orderDate : ""),
						totalAmount
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	DataTable^ DatabaseManager::GetTopSellingProductsDataTable() {
		return GetTopSellingProductsDataTable(nullptr, nullptr);
	}

	DataTable^ DatabaseManager::GetTopSellingProductsDataTable(System::String^ startDate, System::String^ endDate) {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Product Name", String::typeid);
		dt->Columns->Add("Total Units Sold", Int32::typeid);
		dt->Columns->Add("Total Revenue ($)", Double::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			std::string sql = "SELECT p.Name, SUM(oi.Quantity) AS UnitsSold, SUM(oi.Subtotal) AS Revenue "
							  "FROM OrderItems oi "
							  "JOIN Products p ON oi.ProductID = p.ID "
							  "JOIN Orders o ON oi.OrderID = o.ID ";
			
			bool hasDateFilter = (!String::IsNullOrEmpty(startDate) && !String::IsNullOrEmpty(endDate));
			if (hasDateFilter) {
				sql += "WHERE date(o.OrderDate) BETWEEN ? AND ? ";
			}
			sql += "GROUP BY p.ID, p.Name ORDER BY UnitsSold DESC;";

			if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				if (hasDateFilter) {
					IntPtr pStart = Marshal::StringToHGlobalAnsi(startDate);
					IntPtr pEnd = Marshal::StringToHGlobalAnsi(endDate);
					sqlite3_bind_text(stmt, 1, static_cast<const char*>(pStart.ToPointer()), -1, SQLITE_TRANSIENT);
					sqlite3_bind_text(stmt, 2, static_cast<const char*>(pEnd.ToPointer()), -1, SQLITE_TRANSIENT);
					Marshal::FreeHGlobal(pStart);
					Marshal::FreeHGlobal(pEnd);
				}

				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* prodName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					int units = sqlite3_column_int(stmt, 1);
					double revenue = sqlite3_column_double(stmt, 2);

					dt->Rows->Add(
						gcnew String(prodName ? prodName : ""),
						units,
						revenue
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	void DatabaseManager::GetSalesSummary(double% totalSales, int% totalOrders) {
		GetSalesSummary(nullptr, nullptr, totalSales, totalOrders);
	}

	void DatabaseManager::GetSalesSummary(System::String^ startDate, System::String^ endDate, double% totalSales, int% totalOrders) {
		totalSales = 0.0;
		totalOrders = 0;

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			std::string sql = "SELECT COUNT(ID), COALESCE(SUM(TotalAmount), 0.0) FROM Orders ";
			bool hasDateFilter = (!String::IsNullOrEmpty(startDate) && !String::IsNullOrEmpty(endDate));
			if (hasDateFilter) {
				sql += "WHERE date(OrderDate) BETWEEN ? AND ?;";
			}
			else {
				sql += ";";
			}

			if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
				if (hasDateFilter) {
					IntPtr pStart = Marshal::StringToHGlobalAnsi(startDate);
					IntPtr pEnd = Marshal::StringToHGlobalAnsi(endDate);
					sqlite3_bind_text(stmt, 1, static_cast<const char*>(pStart.ToPointer()), -1, SQLITE_TRANSIENT);
					sqlite3_bind_text(stmt, 2, static_cast<const char*>(pEnd.ToPointer()), -1, SQLITE_TRANSIENT);
					Marshal::FreeHGlobal(pStart);
					Marshal::FreeHGlobal(pEnd);
				}

				if (sqlite3_step(stmt) == SQLITE_ROW) {
					totalOrders = sqlite3_column_int(stmt, 0);
					totalSales = sqlite3_column_double(stmt, 1);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
	}

	// ==========================================
	// 8. DAY END CLOSING PROCESS
	// ==========================================
	bool DatabaseManager::PerformDayEndClosing(System::String^ closedBy, double% daySales, int% dayOrders, int% dayItemsSold) {
		daySales = 0.0;
		dayOrders = 0;
		dayItemsSold = 0;

		sqlite3* db = nullptr;
		if (sqlite3_open("bakery_system.db", &db) != SQLITE_OK) {
			if (db) sqlite3_close(db);
			return false;
		}

		// Calculate today's metrics
		const char* sqlStats = 
			"SELECT COUNT(DISTINCT o.ID), COALESCE(SUM(o.TotalAmount), 0.0), COALESCE(SUM(oi.Quantity), 0) "
			"FROM Orders o "
			"LEFT JOIN OrderItems oi ON o.ID = oi.OrderID "
			"WHERE date(o.OrderDate) = date('now', 'localtime');";

		sqlite3_stmt* stmtStats = nullptr;
		if (sqlite3_prepare_v2(db, sqlStats, -1, &stmtStats, nullptr) == SQLITE_OK) {
			if (sqlite3_step(stmtStats) == SQLITE_ROW) {
				dayOrders = sqlite3_column_int(stmtStats, 0);
				daySales = sqlite3_column_double(stmtStats, 1);
				dayItemsSold = sqlite3_column_int(stmtStats, 2);
			}
			sqlite3_finalize(stmtStats);
		}

		// Insert closing snapshot
		const char* sqlInsert = 
			"INSERT INTO DayEndClosings (ClosingDate, ClosedAt, TotalSales, TotalOrders, TotalItemsSold, ClosedBy) "
			"VALUES (date('now', 'localtime'), datetime('now', 'localtime'), ?, ?, ?, ?);";

		sqlite3_stmt* stmtInsert = nullptr;
		bool success = false;
		if (sqlite3_prepare_v2(db, sqlInsert, -1, &stmtInsert, nullptr) == SQLITE_OK) {
			IntPtr pUser = Marshal::StringToHGlobalAnsi(closedBy ? closedBy : "Admin");
			sqlite3_bind_double(stmtInsert, 1, daySales);
			sqlite3_bind_int(stmtInsert, 2, dayOrders);
			sqlite3_bind_int(stmtInsert, 3, dayItemsSold);
			sqlite3_bind_text(stmtInsert, 4, static_cast<const char*>(pUser.ToPointer()), -1, SQLITE_TRANSIENT);
			Marshal::FreeHGlobal(pUser);

			if (sqlite3_step(stmtInsert) == SQLITE_DONE) {
				success = true;
			}
			sqlite3_finalize(stmtInsert);
		}

		sqlite3_close(db);
		return success;
	}

	DataTable^ DatabaseManager::GetDayEndClosingsDataTable() {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Closing ID", Int32::typeid);
		dt->Columns->Add("Business Date", String::typeid);
		dt->Columns->Add("Closed At", String::typeid);
		dt->Columns->Add("Day Sales ($)", Double::typeid);
		dt->Columns->Add("Orders Count", Int32::typeid);
		dt->Columns->Add("Items Sold", Int32::typeid);
		dt->Columns->Add("Closed By", String::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT ID, ClosingDate, ClosedAt, TotalSales, TotalOrders, TotalItemsSold, ClosedBy "
							  "FROM DayEndClosings ORDER BY ID DESC;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					int id = sqlite3_column_int(stmt, 0);
					const char* cDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					const char* cAt = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
					double sales = sqlite3_column_double(stmt, 3);
					int orders = sqlite3_column_int(stmt, 4);
					int items = sqlite3_column_int(stmt, 5);
					const char* user = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

					dt->Rows->Add(
						id,
						gcnew String(cDate ? cDate : ""),
						gcnew String(cAt ? cAt : ""),
						sales,
						orders,
						items,
						gcnew String(user ? user : "")
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	// ==========================================
	// 9. DASHBOARD LIVE STATS
	// ==========================================
	void DatabaseManager::GetDailyStats(double% todaySales, int% todayOrders) {
		todaySales = 0.0;
		todayOrders = 0;

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT COUNT(ID), COALESCE(SUM(TotalAmount), 0.0) FROM Orders WHERE date(OrderDate) = date('now', 'localtime');";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				if (sqlite3_step(stmt) == SQLITE_ROW) {
					todayOrders = sqlite3_column_int(stmt, 0);
					todaySales = sqlite3_column_double(stmt, 1);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
	}

	DataTable^ DatabaseManager::GetDailyTopSellingProductsDataTable() {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Item Name", String::typeid);
		dt->Columns->Add("Qty Sold", Int32::typeid);
		dt->Columns->Add("Revenue ($)", Double::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT p.Name, SUM(oi.Quantity) AS UnitsSold, SUM(oi.Subtotal) AS Revenue "
							  "FROM OrderItems oi "
							  "JOIN Products p ON oi.ProductID = p.ID "
							  "JOIN Orders o ON oi.OrderID = o.ID "
							  "WHERE date(o.OrderDate) = date('now', 'localtime') "
							  "GROUP BY p.ID, p.Name "
							  "ORDER BY UnitsSold DESC "
							  "LIMIT 5;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* prodName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					int units = sqlite3_column_int(stmt, 1);
					double revenue = sqlite3_column_double(stmt, 2);

					dt->Rows->Add(
						gcnew String(prodName ? prodName : ""),
						units,
						revenue
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

	DataTable^ DatabaseManager::GetLowStockProductsDataTable(int threshold) {
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("Product Name", String::typeid);
		dt->Columns->Add("Category", String::typeid);
		dt->Columns->Add("In Stock", Int32::typeid);

		sqlite3* db = nullptr;
		sqlite3_stmt* stmt = nullptr;

		if (sqlite3_open("bakery_system.db", &db) == SQLITE_OK) {
			const char* sql = "SELECT Name, Category, stock FROM Products WHERE stock <= ? ORDER BY stock ASC;";
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				sqlite3_bind_int(stmt, 1, threshold);
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					const char* cat = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
					int stock = sqlite3_column_int(stmt, 2);

					dt->Rows->Add(
						gcnew String(name ? name : ""),
						gcnew String(cat ? cat : ""),
						stock
					);
				}
				sqlite3_finalize(stmt);
			}
			sqlite3_close(db);
		}
		return dt;
	}

}