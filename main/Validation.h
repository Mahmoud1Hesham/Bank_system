#pragma once
#ifndef VALIDATION_H
#define VALIDATION_H
#include "Person.h"
#include<iostream>
#include<string>
using namespace std;
class Validation : public Person
{
public:
	static int checkCharName(string& newName) {
		if (newName.size() >= 5 && newName.size() <= 20) {
			name = newName;
		}
		else {
			cout << "Invalid name. Name must be alphabetic characters and have a length between 5 and 20." << endl;
		}
	}
	static int CheckCharPass(string& newPassword) {
		if (newPassword.size() >= 8 && newPassword.size() <= 20) {
			password = newPassword;
		}
		else {
			cout << "Invalid password. Password must have a length between 8 and 20." << endl;
		}
	}
};

#endif