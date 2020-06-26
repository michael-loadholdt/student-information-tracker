#pragma once
#include "student.h"
#include <string>
using namespace std;
class NetworkStudent : public Student
{
public:
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string emailAddr, int age, int daysInCourse[], Degree degreeProgram);
	
	Degree GetDegreeProgram() override;
	void print();

	~NetworkStudent();

};