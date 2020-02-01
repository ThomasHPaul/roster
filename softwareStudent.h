#pragma once
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{
protected:
	Degree degreeType = SOFTWARE;

public:
	using Student::Student;
	Degree getDegreeType() override;
};
