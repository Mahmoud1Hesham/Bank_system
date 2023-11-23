#pragma once
#include <iostream>
using namespace std;
class EmployeeManager
{
    void printClientMenu() {
        cout << "---- Client Menu ----\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "---------------------\n";
    }
};

