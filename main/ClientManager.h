#pragma once
#include <iostream>
using namespace std;
#include "FileManager.h"
#include "Validation.h"
class ClientManager
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
	static void Back(Client* client) {
		cout << endl;
		system("pause");
		clientOptions(client);
	}
public:
	static void updatePassword(Person* person) {
		person->setPassword(Validation::inputPassword());
		cout << "Password updated!" << endl;
	}
	static Client* Login(int id, string password) {
		for (clIt = allClients.begin();clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id && clIt->getPassword() == password) {
				return clIt._Ptr;
			}
			return NULL;
		}
	}
	static bool clientOptions(Client* client) {
		printClientMenu();
		cout << "Your Choise is : ";
		Employee e;
		double amount;
		int choise, id;
		cin >> choise;
		switch (choise) {
		case 1:
			system("cls");
			client->display();
			break;
		case 2:
			system("cls");
			client->checkBalance();
			break;
		case 3:
			system("cls");
			updatePassword(client);
			FileManager::updateClients();
		case 4 :
			system("cls");
			cout << "Enter The amount : ";
			cin >> amount;
			client->withDraw(amount);
			FileManager::updateClients();
			break;
		case 5:
			system("cls");
			cout << "Enter The amount : ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6:
			system("cls");
			cout << "Enter The id of the recipient : ";
			cin >> id;
			while (e.searchClient(id)==NULL)
			{
				system("cls");
				cout << "Invalid id !\n";
				cout << "Enter valid id : \n";
				cin >> id;
			}
			cout << "Enter amount to transfer : ";
			cin >> amount;
			client->transferTo(*e.searchClient(id),amount);
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOptions(client);
			return true;
		}
		Back(client);
		return true;
	}
};
