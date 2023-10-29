#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include "Validation.h"
using namespace std;
class Person :  public Validation
{
protected:
	static string name, password;
	int id = 0;
public:
	Person(int _id, string _name, string _password) {
		this->id = _id;
		this->name = _name;
		this->password = _password;
	}	//setteres
	void setName(string& newName)
	{
		Validation::checkCharName(newName);
	}

	void setPassword(string& newPassword)
	{
		Validation::CheckCharPass(newPassword);
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

#endif