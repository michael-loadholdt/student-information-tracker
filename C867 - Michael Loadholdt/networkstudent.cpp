#include<iostream>
#include "securityStudent.h"
#include <string>
#include "networkstudent.h"
using namespace std;

NetworkStudent::NetworkStudent():Student()
{
	degreeProgram = NETWORKING;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], Degree degreeProgram)
	:Student(studentID, firstName, lastName, email, age, daysInCourse)
{
	degreeProgram = NETWORKING;
}

Degree NetworkStudent::GetDegreeProgram()
{
	return NETWORKING;
}

void NetworkStudent::print() {
	this->Student::print();
		cout << "NETWORKING" << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}