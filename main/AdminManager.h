#pragma once
#include "EmployeeManager.h"
class AdminManager
{
private:
	static void printAdminMenu() {
		system("cls");
		cout << "---- Employee Menu ----\n";
		cout << "1. Display Info\n";
		cout << "2. Update Password\n";
		cout << "3. Add new Client\n";
		cout << "4. Search for Client\n";
		cout << "5. List all Clients\n";
		cout << "6. Edit Client info\n";
		cout << "7. Back\n";
		cout << "---------------------\n";

	}
};

