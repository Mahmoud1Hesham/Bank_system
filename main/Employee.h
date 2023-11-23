#pragma once
#include "Person.h"
#include "Parser.h"
#include "Client.h"
//#include "FileManager.h"
#include<iostream>
#include<string>
using namespace std;
class Employee : public Person
{

protected:
	double salary;
public:
	Employee(double _salary, int _id, string _name, string _password) : Person(_id, _name, _password) {
		salary = _salary;
	}
	void setSalary(double _salary) {
		if (Validation::checkSalary(_salary)) {
			salary = _salary;
		}
	}
	double getSalary() {
		return salary;
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
	void display() {
		cout << "Name :  " << name << "\nPassword  : " << password << "\nId : " << id << "\nSalary : " << salary << endl;
	}
	Client* listClient() {
		for (clIt = allClients.begin();clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) return clIt._Ptr;
			clIt->display();
			cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
		}
	}
	void addClient(Client& client) {
		allClients.push_back(client);
	}
	Client* searchClient(int _id) {
		for (clIt = allClients.begin();clIt != allClients.end();clIt++) {
			if (clIt->getId() == id) return clIt._Ptr;
		}
		return NULL;
	}
};
static vector<Employee> allEmployees;
static vector<Employee>::iterator emIt;