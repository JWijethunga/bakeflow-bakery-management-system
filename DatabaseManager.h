#pragma once

#include <string>

// Import .NET Data assembly
#using <System.Data.dll>

using namespace System;
using namespace System::Data;

namespace Bakeflow {

    public ref class DatabaseManager {
    public:
        // 1. Creates SQLite tables and seeds default admin user
        static bool Initialize();

        // 2. Verifies username and password against the database
        static bool ValidateUser(const std::string& username, const std::string& password);

        // 3. User Role lookup
        static std::string GetUserRole(const std::string& username);

        // User Management Database Operations
        static bool AddUser(const std::string& username, const std::string& password, const std::string& role);
        static bool DeleteUser(const std::string& username);
        static System::Data::DataTable^ GetUsersDataTable();

        // Product Catalog & Options Management
        static System::Data::DataTable^ GetProductsDataTable();
        static bool AddProduct(const std::string& name, const std::string& category, double price, const std::string& description);
        static bool DeleteProduct(const std::string& name);
        
        // Customer Management Functions
        static System::Data::DataTable^ GetCustomersDataTable();
        static bool AddCustomer(const std::string& name, const std::string& phone, const std::string& email);
        static bool DeleteCustomer(const std::string& phone);
        
        // Inventory Management
        static System::Data::DataTable^ GetInventoryDataTable();
        static bool UpdateProductStock(const std::string& productName, int newStock);
        static int GetProductStock(const std::string& productName);

        // POS Checkout
        static bool CompleteCheckout(System::String^ customerName, System::String^ tableNo, double totalAmount, System::Data::DataTable^ cartTable);

        // Reports Management & Date Filters
        static System::Data::DataTable^ GetSalesReportDataTable();
        static System::Data::DataTable^ GetSalesReportDataTable(System::String^ startDate, System::String^ endDate);
        static System::Data::DataTable^ GetTopSellingProductsDataTable();
        static System::Data::DataTable^ GetTopSellingProductsDataTable(System::String^ startDate, System::String^ endDate);
        static void GetSalesSummary(double% totalSales, int% totalOrders);
        static void GetSalesSummary(System::String^ startDate, System::String^ endDate, double% totalSales, int% totalOrders);

        // Day End Closing Process
        static bool PerformDayEndClosing(System::String^ closedBy, double% daySales, int% dayOrders, int% dayItemsSold);
        static System::Data::DataTable^ GetDayEndClosingsDataTable();

        // Dashboard Live Stats
        static void GetDailyStats(double% todaySales, int% todayOrders);
        static System::Data::DataTable^ GetDailyTopSellingProductsDataTable();
        static System::Data::DataTable^ GetLowStockProductsDataTable(int threshold);
    };

}