#pragma once
#include "student.h"

class SoftwareStudent:public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], Degree degreeProgram);

	Degree GetDegreeProgram() override;
	void print();

	~SoftwareStudent();

};