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
	void display() {
		cout << "ID: " << id << ", Name: " << name << ", Password: " << password << ", Salary: " << salary << endl;
	}
};

static vector<Admin> allAdmins;
static vector<Admin>::iterator adIt;