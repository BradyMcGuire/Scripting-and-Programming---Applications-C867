#include <iostream>
#include <string>
#include "Roster.h"
using namespace std;

Roster::Roster() {
};

void Roster::parse(string myData) {
	size_t rhs = myData.find(",");
	string studentID = myData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	string firstName = myData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	string lastName = myData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	string email = myData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	int age = stoi(myData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	int daysInCourse1 = stoi(myData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	int daysInCourse2 = stoi(myData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	int daysInCourse3 = stoi(myData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = myData.find(",", lhs);
	string strDegreeProgram = myData.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
	if (strDegreeProgram == "NETWORK")
		degreeProgram = DegreeProgram::NETWORK;
	else if (strDegreeProgram == "SOFTWARE")
		degreeProgram = DegreeProgram::SOFTWARE;

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}



void Roster::remove(string studentID) {
	cout << "Removing student: " << studentID << endl << endl;
	bool check = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			string ID = classRosterArray[i]->getStudentID();
			if (ID == studentID) {
				check = true;
				classRosterArray[i] = nullptr;
				continue;
			}
		}
	}
	if (check == false) {
		cout << studentID << " was not found" << endl;
	}
}


void Roster::printAll() {
	cout << "Displaying all students: " << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
};



void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			int* ave = classRosterArray[i]->getDaysInCourse();
			cout << "Student ID: " << studentID << ", average days in course is: " << (ave[0] + ave[1] + ave[2]) / 3 << endl;
			break;
		}
	}
};



void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string invEmail = classRosterArray[i]->getEmail();
		if (invEmail.find(' ') != string::npos || invEmail.find('.') == string::npos || invEmail.find('@') == string::npos)
			cout << invEmail << " is Invalid" << endl;
	}
};



void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in the SOFTWARE program: " << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegree() == degreeProgram) classRosterArray[i]->print();
	}
};




 Roster::~Roster() {
	cout << "Destructor Running";
	for (int i = 0; i < 5; i++) {
		classRosterArray[i] = nullptr;
	}
	cout << endl; // Format Purpose
};