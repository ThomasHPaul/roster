#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
	using Student::Student;

protected:
	Degree degreeType = NETWORK;

public:

	 Degree getDegreeType() override;
};


