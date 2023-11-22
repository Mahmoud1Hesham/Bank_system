#pragma once
#include "Person.h"
#include<iostream>
#include<string>
using namespace std;

class Client : public Person
{
	double balance = 0;
public:
	Client(int _id, string _name, string _password, double _balance) :Person(_id, _name, _password) {
		setBalance(_balance);

		//balance = _balance;
	}
	void setBalance(double _balance) {
		if (Validation::checkBalance(_balance)) {
			balance = _balance;
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		if (amount > 0)
			balance += amount;
		cout << "balance after transaction: " << balance << endl;
	}
	void withDraw(double amount) {
		if (balance >= amount && amount > 0) {
			balance -= amount;
			cout << "Balance after transaction: " << balance << endl;
		}
		else {
			cout << "Amount Exceeded Balance!" << endl;
		}
	}
	void transferTo(Client& recipient, double amount) {
		if (balance >= amount) {
			balance -= amount;
			recipient.balance += amount;
			cout << "The amount has been transferred successfully " << balance << endl;
		}
		else {
			cout << "Amount Exceeded Balance!" << endl;
		}
	}
	void checkBalance() {
		cout << "Balance Is: " << balance << endl;
	}
	void display() {
		Person::display();
		cout << "Your Balance Is: " << balance << endl;
	}

};

static vector<Client> allClients;
static vector<Client>::iterator clIt;

