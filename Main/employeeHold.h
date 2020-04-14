#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

using namespace std;

class employeeEntry
{
public:
	virtual void mainMenu();
	void addEmployee();
	void deleteEmployee();
	void employeeOptions();
	void viewEmployeeProfile();
	void employeeLogin();
	void updateInformation();
	void showEmployee();




protected:


private:
	string search;
	string id;
	string fName;
	string newName;
	string lName;
	string department;
	string maritialStatus;
	string nationality;
	string salary;
	string gender;

};

#endif