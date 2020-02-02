#include <string>
#include <array>
#include <iostream>
#include "student.h"


Student::Student()
{	}

Student::Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete3Courses[0] = daysInCourse1;
	this->daysToComplete3Courses[1] = daysInCourse2;
	this->daysToComplete3Courses[2] = daysInCourse3;
	this->degreeType = degreeType;
}
void Student::setStudentId(std::string studentId)
{
	this->studentId = studentId;
}
void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Student::setEmailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}
void Student::setAge(int age)
{
	this->age = age;
}
void Student::setDaysToComplete3Courses(int course0Days, int course1Days, int course2Days)
{
	this->daysToComplete3Courses[0] = course0Days;
	this->daysToComplete3Courses[1] = course1Days;
	this->daysToComplete3Courses[2] = course2Days;
}
void Student::setDegreeType(Degree degree)
{
	this->degreeType = degreeType;
}

std::string Student::getStudentId()
{
	return studentId;
}
std::string Student::getFirstName()
{
	return firstName;
}
std::string Student::getLastName()
{
	return lastName;
}
std::string Student::getEmailAddress()
{
	return emailAddress;
}
int Student::getAge()
{
	return age;
}
int* Student::getDaysToComplete3Courses()
{
	return daysToComplete3Courses;
}
Degree Student::getDegreeType()
{
	return degreeType;
}
void Student::print()
{
	// FIXME: write a print function for the student data
	std::cout << "Student Id: " << getStudentId() << "\tStudent Name: " << getFirstName() << " " << getLastName() << "\tEmail: " << getEmailAddress() << "\tAge: " << getAge() << "\tDays to complete 3 courses: " << daysToComplete3Courses[0] << " " << daysToComplete3Courses[1] << " " << daysToComplete3Courses[2] << "\tDegree Type: " << getDegreeType() << "\n";
}
Student::~Student()
{
}





