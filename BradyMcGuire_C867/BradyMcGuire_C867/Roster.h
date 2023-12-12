#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class Roster {
private:

    const static int numStudents = 5;

public:

    Roster();

    Student* classRosterArray[numStudents];

    int lastIndex = -1;

    void add(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram
    );

    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parse(string myData);

    ~Roster();

};