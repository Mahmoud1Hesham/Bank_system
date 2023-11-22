#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
int main()
{
	int id;
	double salary, balance;
	string name, password, nam, pass;
	cin >> id >> name >> password >> balance;
	Client c(id, name, password, balance);
	c.deposit(1000);
	c.display();
	c.withDraw(500);
	c.display();
	//cin >> nam>> pass;
	//c.setName(nam);
	//c.setPassword(pass);
	//c.display();
	//c.checkBalance();
	//Client c2(id, name, password, balance);
	//c.transferTo(c2, 1000);
	//cout << c.getBalance() << endl;
	//cout << c2.getBalance() << endl;
	//cin >> salary;
	//Employee e(id, name, password, salary);
	//e.display();
	//cin >> salary;
	//Admin a(id, name, password, salary);
	//a.setSalary(7000);
	//e.display();

}

