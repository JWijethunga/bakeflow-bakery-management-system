#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
    connectionString = "Data Source=app_database.db;Version=3;";
}

bool DatabaseManager::InitializeDatabase() {
    SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
    try {
        conn->Open();
        String^ sql = "CREATE TABLE IF NOT EXISTS Users (Id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT);";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
        cmd->ExecuteNonQuery();
        return true;
    }
    catch (Exception^ ex) {
        return false;
    }
    finally {
        conn->Close();
    }
}

bool DatabaseManager::AddUser(String^ name) {
    SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
    try {
        conn->Open();
        String^ sql = "INSERT INTO Users (Name) VALUES (@name);";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(sql, conn);
        cmd->Parameters->AddWithValue("@name", name);
        cmd->ExecuteNonQuery();
        return true;
    }
    catch (Exception^ ex) {
        return false;
    }
    finally {
        conn->Close();
    }
}

DataTable^ DatabaseManager::GetAllUsers() {
    SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
    DataTable^ dt = gcnew DataTable();
    try {
        conn->Open();
        String^ sql = "SELECT * FROM Users;";
        SQLiteDataAdapter^ da = gcnew SQLiteDataAdapter(sql, conn);
        da->Fill(dt);
    }
    catch (Exception^ ex) {
        // Handle exception or log error
    }
    finally {
        conn->Close();
    }
    return dt;
}