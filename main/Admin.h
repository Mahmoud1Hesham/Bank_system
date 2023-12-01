#pragma once
#include "Employee.h"
#include<iostream>
#include<string>
using namespace std;

class Admin :public Employee {
public:
	Admin(double _salary, int _id, string _name, string _password) : Employee(salary, _id, _name, _password) {
		salary = _salary;
	}
	void setSalary(double _salary) {
		if (Validation::checkSalary(_salary)) {
			salary = _salary;
		}
	}
	void addEmployee(Employee& emp) {
		allEmployees.push_back(emp);
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
	Employee* searchEmployee(int id) {
		for (emIt = allEmployees.begin();emIt != allEmployees.end();emIt++) {
			if (emIt->getId() == id) return emIt._Ptr;
		}
		return NULL;
	}
	void display() {
		cout << "ID: " << id << ", Name: " << name << ", Password: " << password << ", Salary: " << salary << endl;
	}
	void listEmployee() {
		for (emIt = allEmployees.begin();emIt != allEmployees.end(); emIt++) {
			emIt->display();
			cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
		}
	}
};

static vector<Admin> allAdmins;
static vector<Admin>::iterator adIt;