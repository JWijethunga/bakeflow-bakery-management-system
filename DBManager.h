#pragma once


using namespace System;
using namespace System::Data;
using namespace System::Data::SQLite;

public ref class DatabaseManager {
private:
    String^ connectionString;

public:
    DatabaseManager();

    // Core database functions
    bool InitializeDatabase();
    bool AddUser(String^ name);
    DataTable^ GetAllUsers();
};