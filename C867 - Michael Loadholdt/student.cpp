#include <iostream>
#include<iomanip>
#include <string>
#include "student.h"
using namespace std;

string Student::GetStudentID()
{
	return studentID;
}
string Student::GetStudentFirstName()
{
	return firstName;
}
string Student::GetStudentLastName()
{
	return lastName;
}
string Student::GetStudentEmail()
{
	return email;
}
int Student::GetStudentAge()
{
	return age;
}
int* Student::GetDaysInCourse()
{
	return daysInCourse;
}

void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}
void Student::SetStudentFirstName(string firstName)
{
	this->firstName = firstName;
}
void Student::SetStudentLastName(string lastName)
{
	this->lastName = lastName;
}
void Student::SetStudentEmail(string email)
{
	this->email = email;
}
void Student::SetStudentAge(int age)
{
	this->age = age;
}
void Student::SetDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < arraySize; ++i)
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
}

Student::Student()
{
	this->studentID = " ";
	this->firstName = " ";
	this->lastName = " ";
	this->email = " ";
	this->age = 0;
	for (int i = 0; i < arraySize; ++i)
	{
		this->daysInCourse[i] = 0;
	}
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[])
{
	SetStudentID(studentID);
	SetStudentFirstName(firstName);
	SetStudentLastName(lastName);
	SetStudentEmail(email);
	SetStudentAge(age);
	SetDaysInCourse(daysInCourse);

}

void Student::print()
{
	cout << left << setw(5)  << Student::GetStudentID();
	cout << left << setw(10) << Student::GetStudentFirstName();
	cout << left << setw(12) << Student::GetStudentLastName();
	cout << left << setw(25) << Student::GetStudentEmail();
	cout << left << setw(5)  << Student::GetStudentAge();
	for (int i = 0; i < arraySize; ++i)
	{
		cout << left << setw(5) << daysInCourse[i];
	}
	cout << left << setw(2)  << " ";
}

Student::~Student()
{
}
