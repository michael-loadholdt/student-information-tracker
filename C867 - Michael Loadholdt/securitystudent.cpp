#include<iostream>
#include "securityStudent.h"
#include <string>
using namespace std;

SecurityStudent::SecurityStudent():Student()
{
	degreeProgram = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], Degree degreeProgram)
	: Student(studentID, firstName, lastName, email, age, daysInCourse)
{
	degreeProgram = SECURITY;
}

Degree SecurityStudent::GetDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
		cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}