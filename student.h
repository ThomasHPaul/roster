#pragma once

#include <string>
#include <array>
#include "degree.h"

class Student
{

public:
	Student();
	Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void setStudentId(std::string studentId);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysToComplete3Courses(int course1Days, int course2Days, int course3Days);
	void setDegreeType(Degree degree);

	std::string getStudentId();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int* getDaysToComplete3Courses();
	virtual Degree getDegreeType();
	virtual void print();
	~Student();


private:
	std::string studentId;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int* daysToComplete3Courses;
	Degree degreeType;

};
