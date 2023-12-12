#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = 0;
	for (int i = 0; i < 3; i++) { daysInCourse[i] = 0; }
	degreeProgram = DegreeProgram::SECURITY;
};

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) { this->daysInCourse[i] = daysInCourse[i]; }
	this->degreeProgram = degreeProgram;
}

Student::~Student() {};

// Getters
string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysInCourse() {
	return this->daysInCourse;
}

DegreeProgram Student::getDegree() {
	return this->degreeProgram;
}

//Setters
void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(std::string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int DaysInCourse[]) {
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = DaysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	int* tempDays = this->getDaysInCourse();
	cout << this->getStudentID() << "\t"; // Use Getter Functions
	cout << this->getFirstName() << "\t";
	cout << this->getLastName() << "\t";
	cout << this->getEmail() << "\t";
	cout << this->getAge() << "\t";
	cout << tempDays[0] << "," << tempDays[1] << "," << tempDays[2] << "\t";
	cout << degreeStrings[(int)this->getDegree()] << endl;
}