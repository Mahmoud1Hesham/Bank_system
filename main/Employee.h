#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
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
		}	void setSalary(double _salary) {
			salary = _salary;
		}
		double getSalary() {
			return salary;
		}
		void display() {
			cout << "Name :  " << name << "\nPassword  : " << password << "\nId : " << id << "\nSalary : " << salary << endl;
		}

};

#endif