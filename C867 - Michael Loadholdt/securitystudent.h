#pragma once
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], Degree degreeProgram);

	Degree GetDegreeProgram() override;
	void print();

	~SecurityStudent();

};
