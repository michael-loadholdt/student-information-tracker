#pragma once
#include "degree.h"
using namespace std;

class Student {
public:
	const static int arraySize = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[arraySize];
	Degree degreeProgram;

public:
	string GetStudentID();
	string GetStudentFirstName();
	string GetStudentLastName();
	string GetStudentEmail();
	int GetStudentAge();
	int* GetDaysInCourse();

	void SetStudentID(string studentID);
	void SetStudentFirstName(string firstName);
	void SetStudentLastName(string lastName);
	void SetStudentEmail(string email);
	void SetStudentAge(int age);
	void SetDaysInCourse(int daysInCourse[]);


	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[]);

	virtual void print() = 0;
	
	virtual Degree GetDegreeProgram() = 0;

	~Student();

};