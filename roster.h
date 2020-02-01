#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

class Roster
{

public:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysIncourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void remove(std::string studentId);
	void printAll();
	void printDaysInCourse(std::string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	~Roster();
};