#pragma once
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{
protected:
	Degree degreeType = SECURITY;
public:
	using Student::Student;
	Degree getDegreeType() override;
};
