#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"
#include<iostream>
#include<string>
using namespace std;

class Client : public Person
{
	double balance = 0;
public:
	Client(int _id, string _name, string _password, double _balance) :Person(_id, _name, _password) {
		balance = _balance;

	}
	void setBalance(double _balance) {
		if (_balance > 1500) {
			balance = _balance;
		}
		else {
			cout << "The minimum cannot be exceeded!" << endl;
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		balance += amount;
		cout << "balance after transaction: " << balance << endl;
	}
	void withDraw(double amount) {
		if (balance >= amount) {
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

#endif