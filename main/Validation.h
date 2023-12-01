
#pragma once
#include <string>
using namespace std;
class Validation
{
public:
	static bool checkCharName(const string& newName) {
		if (newName.size() >= 5 && newName.size() <= 20) {
			for (char c : newName) {
				if (!isalpha(c)) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	static bool checkCharPass(const string& newPassword) {
		return newPassword.size() >= 8 && newPassword.size() <= 20;
	}
	static bool checkSalary(double& salary) {
		if (salary >= 5000) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool checkBalance(double& balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}

	static string inputName() {
		string name;
		system("cls");
		cout << "Enter name : ";
		cin >> name;
		while (!checkCharName(name)) {
			system("cls");
			cout << "Invalid user name ! \n";
			cout << "The name needs to be greater than 5 and lesser than 20! \n";
			cout << "Enter the name AGAIN! : ";
			cin >> name;
		}
		return name; 
	}
	static string inputPassword() {
		string password;
		system("cls");
		cout << "Enter Password : ";
		cin >> password;
		while (!checkCharPass(password)) {
			system("cls");
			cout << "Invalid password ! \n";
			cout << "The Password needs to be greater than 8 and lesser than 20! \n";
			cout << "Enter Password AGAIN! : ";
			cin >> password;
		}
		return password; 
	}
	static double inputBalance() {
		double balance;
		system("cls");
		cout << "Enter balance : ";
		cin >> balance;
		while (balance < 1500){
			system("cls");
			cout << "Invalid balance ! \n";
			cout << "Balance needs to be at least 1500! \n";
			cout << "Enter Balance AGAIN! : ";
			cin >> balance;
		}
		return balance;
	}
	static double inputSalary() {
		double salary;
		system("cls");
		cout << "Enter salary : ";
		cin >> salary;
		while (salary < 1500){
			system("cls");
			cout << "Invalid salary ! \n";
			cout << "Salary needs to be at least 5000! \n";
			cout << "Enter salary AGAIN! : ";
			cin >> salary;
		}
		return salary;
	}
};


