#include <iostream>
#include <string>
#include "roster.h"
using namespace std;



Roster::Roster()
{
	this->rosterSize = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize)
{
	this->rosterSize = rosterSize;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[rosterSize];
}



void Roster::parse(string dataString)
{
	if (lastIndex < rosterSize)
	{
		lastIndex++;
	}
	for (int i = 0; i < rosterSize; ++i)
	{
		int rhs = dataString.find(",");
		string sID = dataString.substr(0, rhs);

		int	lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		string sFirstName = dataString.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		string sLastName = dataString.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		string sEmail = dataString.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		int sAge = stoi(dataString.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		int sCourse1 = stoi(dataString.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		int sCourse2 = stoi(dataString.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		int sCourse3 = stoi(dataString.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = dataString.find(",", lhs);
		string sDegree = dataString.substr(lhs, rhs - lhs);

		Degree degreeProgram;
		if (sDegree == "SECURITY")
		{
			degreeProgram = SECURITY;
		}
		else if (sDegree == "NETWORK")
		{
			degreeProgram = NETWORKING;
		}
		else
		{
			degreeProgram = SOFTWARE;
		}
		add(sID, sFirstName, sLastName, sEmail, sAge, sCourse1, sCourse2, sCourse3, degreeProgram);
		
	}

}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sCourse1, int sCourse2, int sCourse3, Degree degreeProgram)
{
	int daysInCourse[Student::arraySize];
	daysInCourse[0] = sCourse1;
	daysInCourse[1] = sCourse2;
	daysInCourse[2] = sCourse3;

	if (degreeProgram == SECURITY)
	{
		classRosterArray[lastIndex] = new SecurityStudent(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, degreeProgram);
	}
	else if (degreeProgram == NETWORKING)
	{
		classRosterArray[lastIndex] = new NetworkStudent(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, degreeProgram);
	}
	else
	{
		classRosterArray[lastIndex] = new SoftwareStudent(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, degreeProgram);
	}

}

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; ++i)
	{
		this->classRosterArray[i]->print();
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		string emailTest = classRosterArray[i]->GetStudentEmail();
		if (emailTest.find("@") == string::npos || (emailTest.find(".") == string::npos) || (emailTest.find(" ") != string::npos))
		{
			cout << "Student Email: " << classRosterArray[i]->GetStudentEmail() << endl;
		}
	}
}

Student* Roster::GetStudentAt(int index)
{
	return classRosterArray[index];
}

void Roster::PrintAverageDaysInCourse(string studentID)
{
	int averageDays = 0;
	
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			int* daysArray = classRosterArray[i]->GetDaysInCourse();
			averageDays = (daysArray[0] + daysArray[1] + daysArray[2]) / 3;
			cout << "For Student " << studentID << ": Average Days in Course: " << averageDays << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram)
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram)
		{
			this->classRosterArray[i]->print();
		}
	}
}

bool Roster::remove(string studentID)
{
	bool foundStudent = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			foundStudent = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return foundStudent;
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}


int main()
{
	cout << "C867: Scripting and Programming Applications" << endl;
	cout << "Written in C++" << endl;
	cout << "Student ID: #001035593" << endl;
	cout << "Michael Loadholdt" << endl;

	int numStudents = 5;

	const string studentData[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Michael,Loadholdt,mloadho@wgu.edu,30,15,37,25,SOFTWARE"
	};

	cout << "Adding Student Data" << endl;

	Roster* classRoster = new Roster(numStudents);
	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->parse(studentData[i]);
	}
	
	cout << "Add Complete." << endl << "Printing All Student Data:" << endl;
	classRoster->printAll();

	cout << "Printing Invalid Emails." << endl;
	classRoster->printInvalidEmails();

	cout << "Printing Average Days in Course." << endl;
	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->PrintAverageDaysInCourse(classRoster->GetStudentAt(i)->GetStudentID());
	}

	cout << "Printing by Degree Program." << endl;
	for (int i = 0; i < 3; ++i)
	{
		classRoster->printByDegreeProgram((Degree)i);
	}

	cout << "Removing Student." << endl;
	if (!classRoster->remove("A3"))
	{
		cout << "Error: Student not found" << endl;
	}
	
	cout << "Removing Student." << endl;
	if (!classRoster->remove("A3"))
	{
		cout << "Error: Student not found." << endl;
	}

	system("pause");

	return 0;
}