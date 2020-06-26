#include<iostream>
#include "softwareStudent.h"
#include <string>
using namespace std;

SoftwareStudent::SoftwareStudent():Student()
{
	degreeProgram = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[],Degree degreeProgram):Student(studentID, firstName, lastName, email, age, daysInCourse)
{
	degreeProgram = SOFTWARE;
}

Degree SoftwareStudent::GetDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::print() 
{
	this->Student::print();
		cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}