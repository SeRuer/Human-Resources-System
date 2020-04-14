#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <conio.h>
#include <sstream>
#include <vector>

//Own header files
#include "employeeLog.h"
#include "employeeHold.h"
#include "loginPage.h"

using namespace std;

void employeeEntry::viewEmployeeProfile()
{
	system("cls");
	cout << "\n" << setw(48) << right << "****************************";
	cout << "\n" << setw(48) << right << "   VIEW EMPLOYEE PROFILE    ";
	cout << "\n" << setw(48) << right << "****************************";

	ifstream k;
	int i;
	string line, temp;
	int count = 0;


	k.open("temp.txt", ios::out | ios::app);
	cout << "\n\n" << setw(48) << right << "PLEASE ENTER ID:";
	cin >> search;
	if (!k.is_open())
	{
		cout << "SORRY FILE NOT FOUND" << "\n";
		return;
	}
	else {

		if (k.is_open())
		{
			while (!k.eof())
			{
				getline(k, line);
				if ((i == line.find(search, 0)) != string::npos){
				cout << "EMPLOYEE FOUND " << search << endl;
				cout << fName << ',';
				cout << lName << ',';
				cout << nationality << ',';
				cout << gender << ',';
				cout << maritialStatus << ',';
				cout << salary << ',' << endl;

			}
			}
			k.close();
		}
		system("pause");
		



	}
}



//WOrks fine
void employeeEntry::addEmployee()
{
	system("cls");
	cout << "\n" << setw(56) << right << "********************";
	cout << "\n" << setw(48) << right << "   ADD EMPLOYEE     ";
	cout << "\n" << setw(56) << right << "********************";
	int i;
	ofstream myfile;
	fstream outfile("employeeDetails.txt", ios::app);
	myfile.open("employeeNew.csv", ios::app);

	for (i = 0; i < 7; i++) {



		cout << "\n" << setw(56) << right << "Input Employee ID:";
		cin >> id;
		myfile << id << ",";
		cout << "\n" << setw(48) << right << "INPUT FIRST NAME:";
		cin >> fName;
		myfile << fName << ",";
		cout << "\n" << setw(56) << right << "INPUT LAST NAME:";
		cin >> lName;
		myfile << lName << ",";
		cout<< "\n" << setw(56) << right << "INPUT GENDER:";
		cin >> gender;
		myfile << gender << " ,";
		cout << "\n" << setw(48) << right << "INPUT DEPARTMENT:";
		cin >> department;
		myfile << department << ",";
		cout << "\n" << setw(56) << right << "INPUT MARITIAL STATUS:";
		cin >> maritialStatus;
		myfile << maritialStatus << ",";
		cout << "\n" << setw(48) << right << "INPUT THE NATIONALITY:";
		cin >> nationality;
		myfile << nationality << ",";
		cout << "\n" << setw(56) << right << "INPUT SALARY:";
		cin >> salary;
		myfile << salary << ",";

		outfile << id << " " << fName << "" << lName << "" << department << " " << maritialStatus << " " << nationality << " " << salary << endl;
		myfile << id << std::setw(10) << " " << fName << std::setw(10) << "" << lName << std::setw(10) << "" << department << std::setw(10) << " " << maritialStatus << std::setw(10) << " " << nationality << std::setw(10) << " " << salary << std::setw(10) << endl;
		cout << "\n" << setw(48) << right << "   EMPLOYEE HAS SUCCESFULLY BEEN ADDED     ";
		cout << "\n" << setw(48) << right << "         PRESS ENTER TO CONTINUE           ";
		cin.ignore();
		system("pause");
		outfile.close();
		myfile.close();
		return;

	}
}

//Done
void employeeEntry::deleteEmployee()
{
	system("cls");
	cout << "\n" << setw(56) << right << "***********************";
	cout << "\n" << setw(48) << right << "   DELETE EMPLOYEE     ";
	cout << "\n" << setw(56) << right << "***********************";
	ifstream flower;
	fstream fin;
	ofstream temp;
	int search;
	string line;
	int num;
	fin.open("employeeNew.csv");
	temp.open("temp.txt", ios::out | ios::trunc);
	cout << "\n\n" << setw(48) << right << "PLEASE ENTER ID:";
	cin >> search;
	if (!fin)
	{
		cout << "FILE NOT FOUND. PRESS ANY KEY";
		return;
	}
	else 
	{
		while (fin.good())
		{
			getline(fin, line);
			if (fin) {
				int n = 0;
				istringstream(line) >> num;
				if (num != search)
				{
					temp << line << endl;
				}
			}
		}
		cout << "RECORD NAME " << search << "HAS BEEN ERASED" << endl;
		fin.close();
		flower.close();
		temp.close();
		remove("employeeInformation.csv");
		rename("temp.csv", "employeeNew.csv");
		system("pause");

	} 
}


void employeeEntry::updateInformation()
{
	system("cls");
	cout << "\n" << setw(56) << right << "*******************************";
	cout << "\n" << setw(48) << right << "   UPDATE EMPLOYEE PROFILE     ";
	cout << "\n" << setw(56) << right << "*******************************";
	int n = 0, i = 0;
	fstream fin;
	ofstream employeeTwo;
	string line, sign;
	fin.open("employeeNew.csv", ios::in | ios::out | ios::ate | ios::binary);
	fin.seekg(0, ios::beg);
	fin.read((char*)this, sizeof(*this));
	cout << right << "ENTER EMPLOYEE ID: ";
	cin >> sign;
	cout << endl;
	fin.seekg(0);
	if (!fin)    cout << "FILE NOT FOUND";
	else {
		while (!(cin >> sign)) //receiving the variables from input
		{
			cout << "ENTER A NUMBER! TRY AGAIN: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		int flag1 = 0;
		for (int i = 0; i < n; i++) {
		
			{
				flag1++;
			}
		}
		cout << endl;

		for (int i = 0; i < n;  i++);

	}

	}


