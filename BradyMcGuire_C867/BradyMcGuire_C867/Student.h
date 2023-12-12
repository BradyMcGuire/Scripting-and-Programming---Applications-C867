#pragma once
#include <iostream>
#include <string>
#include "Degree.h"
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:

	//constructor 
	Student(); // Default
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);

	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegree();

	//Setters

	void setStudentID(string tudentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degree);

	void print();

	~Student(); //destructor
};