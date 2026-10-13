# 🥐 BakeFlow — Bakery Management System

> A complete point-of-sale and business management system built for bakeries and small food businesses.

---

## 📋 Table of Contents

- [About the Project](#about-the-project)
- [Scope](#scope)
- [Tech Stack](#tech-stack)
- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [How to Run](#how-to-run)
- [Default Login Credentials](#default-login-credentials)
- [Database](#database)

---

## About the Project

**BakeFlow** is a desktop-based bakery management system designed to streamline daily operations for small to mid-size bakeries. It handles everything from point-of-sale billing to inventory tracking, customer records, sales reports, and day-end closing — all in a single native Windows desktop application.

---

## Scope

This system covers the full day-to-day operations of a bakery business:

| Module | Scope |
|---|---|
| **Authentication** | Role-based login (Admin / Cashier) with secure password storage |
| **POS / Billing** | Cart-based order system with product selection, customer assignment, table number, and invoice total |
| **Product Catalog** | Add, view, and delete menu/bakery items with categories, pricing, and descriptions |
| **Inventory Management** | Track product stock levels; update quantities; low-stock alerts on dashboard |
| **Customer Management** | Maintain a database of customers with name, phone, and email |
| **User Management** | Admin-only panel to add and remove staff user accounts |
| **Reports** | Date-filtered sales reports, top-selling products, and order summaries |
| **Day End Closing** | Capture daily totals (sales, orders, items sold) and log closing records |
| **Live Dashboard** | Real-time KPIs — today's revenue, today's order count, top-selling items, and low-stock warnings |

---

## Tech Stack

| Layer | Technology |
|---|---|
| **Language** | C++/CLI (Managed C++) |
| **UI Framework** | Windows Forms (.NET Framework) |
| **Database** | SQLite 3 (embedded, via `sqlite3.c` / `sqlite3.h`) |
| **IDE** | Visual Studio 2022 |
| **Build System** | MSBuild (`.vcxproj`) |
| **Platform** | Windows x64 |
| **Runtime** | .NET Framework 4.x |

> SQLite is bundled directly in the project (amalgamation build) — no separate database engine installation needed.

---

## Features

- ✅ Role-based access control (Admin vs Cashier)
- ✅ Full POS billing with cart management
- ✅ Product catalog with categories and pricing
- ✅ Inventory tracking with low-stock warnings
- ✅ Customer database
- ✅ User account management (Admin only)
- ✅ Sales reports with date filtering
- ✅ Top-selling products report
- ✅ Day-end closing log with daily totals
- ✅ Live dashboard with daily KPI cards
- ✅ Resizable and maximizable window
- ✅ Zero external dependencies — SQLite is embedded

---

## Project Structure

```
Bakeflow/
├── main.cpp                  # App entry point — initializes DB and shows Login form
├── LoginForm.h / .cpp        # Login screen with role-based auth
├── Dashboard.h / .cpp        # Main dashboard with live stats and navigation
├── POSBillingForm.h / .cpp   # Point-of-sale / order entry screen
├── ManageProducts.h / .cpp   # Product catalog management
├── Inventory.h / .cpp        # Inventory stock management
├── Customers.h / .cpp        # Customer records management
├── ManageUsers.h / .cpp      # Admin-only user account management
├── ReportsForm.h / .cpp      # Sales reports + day-end closing
├── DatabaseManager.h / .cpp  # All SQLite database operations
├── sqlite3.h / sqlite3.c     # Bundled SQLite 3 amalgamation
├── bakery_system.db          # SQLite database file (auto-created on first run)
├── Bakeflow.vcxproj          # Visual Studio project file
├── Bakeflow.slnx             # Visual Studio solution file
└── .gitignore
```

---

## Prerequisites

Before running the project, make sure you have:

1. **Visual Studio 2022** (Community, Professional, or Enterprise)
   - Download: https://visualstudio.microsoft.com/
2. **Workloads required** (install via Visual Studio Installer):
   - ✅ **Desktop development with C++**
   - ✅ **.NET desktop development**
3. **Windows 10 or later** (x64)

> No additional libraries or package managers (NuGet, vcpkg) are required. SQLite is bundled.

---

## How to Run

### Option 1 — Visual Studio (Recommended)

1. Clone or download this repository.
2. Open **`Bakeflow.slnx`** in Visual Studio 2022.
3. Set the build configuration to **`Debug | x64`** (or `Release | x64`).
4. Press **`F5`** (Start Debugging) or **`Ctrl+F5`** (Start Without Debugging).
5. The app will automatically create the SQLite database (`bakery_system.db`) on first launch.

### Option 2 — MSBuild via Command Line

```powershell
# Navigate to the project folder
cd "C:\Users\user\Desktop\Projects\Bakeflow"

# Build using MSBuild (Visual Studio must be installed)
msbuild Bakeflow.vcxproj /p:Configuration=Debug /p:Platform=x64

# Run the compiled executable
.\x64\Debug\Bakeflow.exe
```

---

## Default Login Credentials

On first launch, the database is seeded with a default admin account:

| Field | Value |
|---|---|
| **Username** | `admin` |
| **Password** | `admin123` |
| **Role** | Admin |

> ⚠️ Change the default password after first login using the **Manage Users** panel.

---

## Database

- The database file `bakery_system.db` is an SQLite 3 database.
- It is **auto-created** the first time the application runs.
- Tables created automatically:
  - `Users` — staff accounts and roles
  - `Products` — bakery product catalog
  - `Customers` — customer records
  - `Orders` — sales transactions
  - `OrderItems` — line items per order
  - `DayEndClosings` — day-end closing logs

> The `bakery_system.db` file is **excluded from Git** (see `.gitignore`) since it is auto-generated and may contain live data.

---

## Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature`
3. Commit your changes: `git commit -m "Add your feature"`
4. Push to the branch: `git push origin feature/your-feature`
5. Open a Pull Request