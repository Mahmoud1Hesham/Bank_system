
#pragma once
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
	static bool checkSalary(double& salary) {
		if (salary >= 5000) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool checkBalance(double& balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}
};


