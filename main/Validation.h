//#pragma once
//#ifndef VALIDATION_H
//#define VALIDATION_H
//#include "Person.h"
//#include<iostream>
//#include<string>
//using namespace std;
//class Validation
//{
//public:
//	bool checkCharName(string& newName) {
//		if (newName.size() >= 5 && newName.size() <= 20) {
//			/*name = newName;*/
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	bool checkCharPass(string& newPassword) {
//		if (newPassword.size() >= 8 && newPassword.size() <= 20) {
//			/*password = newPassword;*/
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//};
//
//#endif


#pragma once
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
using namespace std;
class Validation
{
public:
    static bool checkCharName(const string& newName) {
        if (newName.size() >= 5 && newName.size() <= 20) {
            for (char c : newName) {
                if (!isalpha(c)) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    static bool checkCharPass(const string& newPassword) {
        return newPassword.size() >= 8 && newPassword.size() <= 20;
    }
};

#endif