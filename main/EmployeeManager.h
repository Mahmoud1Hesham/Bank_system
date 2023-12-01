#pragma once
#include <iostream>
#include "ClientManager.h"
using namespace std;
class EmployeeManager
{
private:
	static void printClientMenu() {
		system("cls");
		cout << "---- Client Menu ----\n";
		cout << "1. Display Info\n";
		cout << "2. Check Balance\n";
		cout << "3. Update Password\n";
		cout << "4. Withdraw\n";
		cout << "5. Deposit\n";
		cout << "6. Transfer\n";
		cout << "7. Back\n";
		cout << "---------------------\n";
	}
	//static void Back(Employee* employee) {
	//	cout << endl;
	//	system("pause");
	//	employeeOptions(employee);
	//}
public:
    static void newClient(Employee* employee) {
		Client c;
		c.setId(Fileshelper::getLast("ClientLastId.txt") + 1);
		string password;
		c.setName(Validation::inputName());
		c.setPassword(Validation::inputPassword());
		employee->addClient(c);
		FileManager::updateClients();
		cout << "\n Client added successfully! \n";
	}
	static void searchForClient(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id : ";
		cin >> id;
		if (employee->searchClient(id) == NULL) {
			cout << "Client Not Found!";
		}
		else {
			employee->searchClient(id)->display();
		}
	}
		static void listAllClients(Employee * employee) {
			system("cls");
			cout << "All clients\n";
			employee->listClient();
		}
		static void editClientInfo(Employee* employee) {
			int id;
			system("cls");
			cout << "Enter Client id : ";
			cin >> id;
			if (employee->searchClient(id) == NULL) {
				cout << "Client Not Found!";
			}
			else {
				string name = Validation::inputName();
				string pass = Validation::inputPassword();
				double balance = Validation::inputBalance();
				employee->editClient(id, name, pass, balance);
				FileManager::updateClients();
				cout << "Client Info Updated!" << endl;
			}
		}

};

