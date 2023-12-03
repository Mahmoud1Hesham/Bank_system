#pragma once
#include <iostream>
#include "ClientManager.h"
using namespace std;
class EmployeeManager
{
private:
	static void printEmployeeMenu() {
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
	static void Back(Employee* employee) {
		cout << endl;
		system("pause");
		employeeOptions(employee);
	}
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
		static Employee* Login(int id, string password) {
			for (emIt = allEmployees.begin();emIt != allEmployees.end();emIt++) {
				if (emIt->getId() == id && emIt->getPassword() == password) {
					return emIt._Ptr;
				}
				return NULL;
			}
		}
		static bool employeeOptions(Employee* employee) {
			printEmployeeMenu();
			cout << "Your Choise is : ";
			int choise;
			cin >> choise;
			switch (choise)
			{
			case 1:
				system("cls");
				employee->display();
				break;
				case 2:
					ClientManager::updatePassword(employee);
					FileManager::updateEmployees();
					break;
				case 3:
					newClient(employee);
					break;
				case 4:
					searchForClient(employee);
					break;
				case 5:
					listAllClients(employee);
					break;
				case 6:
					editClientInfo(employee);
					break;
				case 7:
					return false;
					break;
			default:
				system("cls");
				employeeOptions(employee);
				return true;
			}
			Back(employee);
			return true;
		}
};

