#include <iostream>
#include "Roster.h"
using namespace std;

int main()
{
	cout << "Course: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS" << endl;
	cout << "Programming Language: C++ " << endl;
	cout << "Student ID: 010867947" << endl;
	cout << "Student Name: Brady McGuire" << endl;
	cout << endl;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Brady,McGuire,Bmccgu41@wgu.edu,21,15,25,30,SOFTWARE"
	};

	Roster classRoster;

	for (int i = 0; i < 5; i++) { classRoster.parse(studentData[i]); }

	// Main -> call roster.parse -> calls roster.add -> Calls student constructor

	classRoster.printAll();

	cout << endl; //formating purpose, does nothing with or for data, Cosmetic only

	classRoster.printInvalidEmails();

	cout << endl; //formating purpose, does nothing with or for data, Cosmetic only

	for (int i = 0; i < 5; i++) { classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID()); }

	cout << endl; //formating purpose, does nothing with or for data, Cosmetic only

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl; //formating purpose, does nothing with or for data, Cosmetic only

	classRoster.remove("A3");

	classRoster.printAll();

	cout << endl;

	classRoster.remove("A3");

	//expected: the above line should print a message saying such a student with this ID was not found.

	cout << endl; //formating purpose, does nothing with or for data, Cosmetic only

	return 0;
}