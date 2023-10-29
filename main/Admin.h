#pragma once
#ifndef ADMIN_H
#define ADMIN_H
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
		try {
			if (_salary < 5000)
			{
				throw 1;
			}
			else
			{
				salary = _salary;
			}
		}
		catch (int)
		{
			cout << "Salary below 5000" << endl;
		}
	}
	void display()
	{
		cout << "ID : " << id << "& Name : " << name << "& Password : " << password << "Salary : " << salary << endl;
	}
};

#endif