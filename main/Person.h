#pragma once
#include<iostream>
#include<string>
#include "Validation.h"
using namespace std;
class Person
{
protected:
	string name, password;
	int id = 0;
public:
	Person(int _id, string _name, string _password) {
		this->id = _id;
		this->name = _name;
		this->password = _password;
	}	//setteres
	void setName(string& newName)
	{
		if (Validation::checkCharName(newName)) {
			name = newName;
		}
		else {
			cout << "Invalid input. the required Name must contain alphabetic characters and contain a length between 5 and 20." << endl;
		}

	}

	void setPassword(string& newPassword)
	{
		if (Validation::checkCharPass(newPassword)) {
			password = newPassword;
		}
		else {
			cout << "Invalid input. The required Password's range must be between 8 and 20." << endl;
		}

	}
	void setId(int _id)
	{
		id = _id;
	}
	//getters
	string getName()
	{
		return name;
	}
	string getPassword()
	{
		return password;
	}
	int getId()
	{
		return id;
	}
	virtual void display()
	{
		cout << "Name :" << name <<
			" \n" << "Password : " << password << " \n" <<
			"Id : " << id << endl;
	}
};


