#include "LoginForm.h"
#include "DatabaseManager.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Creates tables and seeds default admin user ('admin', '1234')
    Bakeflow::DatabaseManager::Initialize();

    Bakeflow::LoginForm^ loginForm = gcnew Bakeflow::LoginForm();
    Application::Run(loginForm);

    return 0;
}