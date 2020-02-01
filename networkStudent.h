#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
protected:
	Degree degreeType = NETWORK;

public:
	using Student::Student;
	Degree getDegreeType() override;
};

