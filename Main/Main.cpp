#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>

#include "employeeHold.h"
#include "loginPage.h"
#include "adminAccess.h"
#include "employeeLog.h"


employeeEntry employee;
adminAccess adminEnter;
login loginMenu;
using namespace std;

const int MENU_ADMIN_EXIT = 0;



int main()
{
	loginMenu.loginPage();
	cin.ignore();

}


void login::loginPage()
{

	system("cls");
	int logChoice;
	cout << "\n" << setw(48) << right << "********************";
	cout << "\n" << setw(48) << right << "    LOGIN PLEASE    ";
	cout << "\n" << setw(48) << right << "********************";
	cout << "\n" << setw(48) << right << "[1] Login as Admin  ";
	cout << "\n" << setw(51) << right << "[2] Login as employee";
	cout << "\n" << setw(38) << right << "[3] Exit";
	cout << "\n\n\n" << setw(48) << right << "Enter your choice: ";
	cin >> logChoice;





	switch (logChoice)
	{
	case 1:
		adminEnter.mainMenu();
		break;

	case 2:
		employee.employeeLogin();
		break;

	case 3:

		break;

	default:
		cout << "\n" << setw(56) << right << "********************";
		cout << "\n" << setw(48) << right << "      INVALID       ";
		cout << "\n" << setw(56) << right << "********************";
		cout << "\n\n\n" << setw(48) << right << "Enter again";
		cin.get();
		cin.get();
		loginPage();


	}
}

void adminChoices()
{
	int mad = MENU_ADMIN_EXIT;
	do
	{
		system("cls");
		

		cout << "\n" << setw(48) << right << "********************************************" << endl;
		cout << "\n" << setw(49) << right << "               Admin Menu                   " << endl;
		cout << "\n" << setw(48) << right << "********************************************" << endl;

		cout << "\n" << setw(56) << right << "Please choose one of the following tasks";
		cout << "\n" << setw(56) << right << "[1] Add new employee";
		cout << "\n" << setw(56) << right << "[2] Delete employee information";
		cout << "\n" << setw(56) << right << "[3] Update employee information";
		cout << "\n" << setw(56) << right << "[4] View employee profile";
		cout << "\n" << setw(56) << right << "[5] Quit";
		cout << "\n" << setw(56) << right << "ENTER ONE:";
		cin >> mad;

		switch (mad)
		{
		case 1:
		{

			adminEnter.addEmployee(); //Allows the user to add any employees into the file 
			
			
		}
		break;


		case 2:
		{
			adminEnter.deleteEmployee(); //Deletes employee data
			
		}
		break;
		break;

		case 3:
		{
			adminEnter.updateInformation(); //Updates employee information
			
			
		}
		break;

		case 4:
		{
			adminEnter.viewEmployeeProfile(); //Allows Admin to view profile
			
		}
		break;

		
		case 5: 
		{
			MENU_ADMIN_EXIT;
			break;
		}

		default:
			cout << "\n INVALID" << mad;

		}

	} while (mad != MENU_ADMIN_EXIT);

}






void employeeEntry::mainMenu()
{
	system("cls");
	string line = "";
	bool found = false;

	string user, pass, u, p;
	ifstream chat("adminLogin.txt");

	cout << "\n" << setw(48) << right << "********************";
	cout << "\n" << setw(48) << right << "    ADMIN LOGIN     ";
	cout << "\n" << setw(48) << right << "********************";
	cout << "\n" << setw(48) << right << "ENTER YOUR USERNAME:";
	cin >> user;
	cout << "\n" << setw(48) << right << "ENTER YOUR PASSWORD:";
	cin >> pass;

	while (getline(chat, line))
	{
		stringstream iss(line);
		iss >> u >> p;

		if (user == u && pass == p) {
			cout << "Login Successfully" << endl;
			found = true;
			adminChoices();
			break;
		}
		if(!found) {
			cout << "Invalid username or password" << endl;
		}
	}

	}



void employeeEntry::employeeLogin()
{

	system("cls");
	
	string line = "";
	bool found = false;
	string user, pass, u, p;
	cout << "\n" << setw(48) << right << "**********************";
	cout << "\n" << setw(48) << right << "    EMPLOYEE LOGIN    ";
	cout << "\n" << setw(48) << right << "***********************";
	cout << "\n" << setw(48) << right << "ENTER YOUR USERNAME:";
	cin >> user;
	cout << "\n" << setw(48) << right << "ENTER YOUR PASSWORD:";
	cin >> pass;

	ifstream input("logins.txt");


	while (getline(input, line))
	{
		stringstream iss(line);
		iss >> u >> p;

		if (user == u && pass == p) {
			cout << "Login Successfull" << endl;
			found = true;
			employee.employeeOptions();
			break;
		}
		if (!found) {
			cout << "Invalid username or password" << endl;
		}
	}

}


void employeeEntry::employeeOptions()
{
	int click;

		system("cls");
		cout << "\n" << setw(48) << right << "****************************";
		cout << "\n" << setw(48) << right << "   THE EMPLOYEE MENU    ";
		cout << "\n" << setw(48) << right << "****************************";

		cout << "\n" << setw(48) << right << "[1] View employee profile";
		cout << "\n" << setw(48) << right << "[2] Quit";
		cout << "\n\n\n" << setw(48) << right << "Please enter your choice:";
		cin >> click;


	switch (click)
	{

	case 1:
		employee.viewEmployeeProfile();
		cin.get();
		break;

	

	case 2:

		exit(0);
		break;

	default:
		cout << "\n" << setw(56) << right << "********************";
		cout << "\n" << setw(48) << right << "      INVALID       ";
		cout << "\n" << setw(56) << right << "********************";
		cout << "\n\n\n" << setw(48) << right << "Enter again";
		cin.get();
		cin.get();

	}
}

