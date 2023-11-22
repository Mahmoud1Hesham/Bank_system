#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager : public DataSourceInterface {
private:
	static void addClient(Client client) {
		Fileshelper::saveClient(client);
	}static void addEmployee(Employee emp) {
		Fileshelper::saveEmployee("Employees.txt","EmployeeLastId.txt", emp);
	}static void addAdmin(Admin ad) {
		Fileshelper::saveEmployee("Admins.txt","AdminLastId.txt",ad);
	}static void getAllClients() {
		Fileshelper::getClients();
	}static void getAllEmployees() {
		Fileshelper::getEmployees();
	}static void getAllAdmins() {
		Fileshelper::getAdmins();
	}static void removeAllClients() {
		Fileshelper::clearFile("Clients.txt", "ClientLastId.txt");
	}static void removeAllEmployees() {
		Fileshelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}static void removeAllAdmins() {
		Fileshelper::clearFile("Admins.txt", "AdminLastId.txt");
	}
public:
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	static void updateClients() {
		removeAllClients();
		for (clIt = allClients.begin();clIt != allClients.end();clIt++) addClient(*clIt);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (emIt = allEmployees.begin();emIt != allEmployees.end();emIt++) addEmployee(*emIt);
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (adIt = allAdmins.begin();adIt != allAdmins.end();adIt++) addEmployee(*adIt);
	}

};

