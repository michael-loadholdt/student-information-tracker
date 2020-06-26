#pragma once
#include "student.h"
#include "networkstudent.h"
#include "securitystudent.h"
#include "softwarestudent.h"


class Roster
{
private:
	int lastIndex;
	int rosterSize;
	Student** classRosterArray;

public:
	Roster();
	Roster(int rosterSize);

	void parse(string dataString);
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sCourse1, int sCourse2, int sCourse3, Degree degreeProgram);
	void printAll();
	void printInvalidEmails();
	void PrintAverageDaysInCourse(string studentID);
	void printByDegreeProgram(Degree degreeProgram);
	bool remove(string studentID);
	Student* GetStudentAt(int index);

	~Roster();

};