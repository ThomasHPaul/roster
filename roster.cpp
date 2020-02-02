#include <array>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
int sizeOfRoster = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType)
{

    for (int i = 0; i < sizeOfRoster; ++i)
    {
        if (classRosterArray[i] == nullptr)
        {
            switch (degreeType)
            {
            case NETWORK:
            {
                classRosterArray[i] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
                std::cout << "Network student initialized\n";
                return;
            }
            case SECURITY:
            {
                classRosterArray[i] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
                std::cout << "Security student initialized\n";
                return;
            }
            case SOFTWARE:
            {
                classRosterArray[i] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
                std::cout << "Software student initialized\n";
                return;
            }
            // No default defined because enum type will only allow one of the 3 choices above
            }
        }
    }
}

void Roster::remove(std::string studentId)
{
    for (int i = 0; i < sizeOfRoster; ++i)
    {
        if (classRosterArray[i] == nullptr)
        {
            continue;
        }
        else
        {
            if (studentId == classRosterArray[i]->getStudentId())
            {
                classRosterArray[i] = nullptr;
                std::cout << "Student removed\n";
                return;
            }
            else
            {
                continue;
                //std::cout << "A student with this ID was not found\n";
            }
        }

    }
    std::cout << "\n";
}

void Roster::printAll()
{
    for (int i = 0; i < sizeOfRoster; ++i)   // FIXME : incorporate the following sizeof fruit/sizeof fruit[0];
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
    std::cout << "\n";
}

void Roster::printDaysInCourse(std::string studentId)
{
    int* daysInCourse;
    double sum = 0.0;
    int length = 0;
    int course1 = 0;
    int course2 = 0;
    int course3 = 0;
    int ave = 0;

    for (int i = 0; i < sizeOfRoster; ++i)
    {
        if (studentId == classRosterArray[i]->getStudentId())
        {
            daysInCourse = classRosterArray[i]->getDaysToComplete3Courses();
            sum += daysInCourse[0];
            sum += daysInCourse[1];
            sum += daysInCourse[2];

            ave = sum / 3;
        }
    }

    std::cout << "This student has an average of " << ave << " days to finish 3 courses\n";
}

void Roster::printInvalidEmails()
{
    int atPosition = 0;
    int periodPosition = 0;

    for (int i = 0; i < sizeOfRoster; ++i)
    {
        std::string emailAddress = classRosterArray[i]->getEmailAddress();

        
        for (const char character : emailAddress)
        {
            // check for spaces, if present then print email address
            if (character == ' ')
            {
                std::cout << emailAddress << "\n";
                break;
            }

            // if no spaces then check that both "@" & "." is present
            else
            {
                atPosition = emailAddress.find('@');
                periodPosition = emailAddress.find('.');

                if (atPosition < 0 || periodPosition < 0)
                {
                    std::cout << emailAddress << "\n";
                    break;
                }

            }
        }
    }
    std::cout << "\n";
}

void Roster::printByDegreeProgram(int degreeProgram)
{
    for (int i = 0; i < sizeOfRoster; ++i)
    {
        if (degreeProgram == classRosterArray[i]->getDegreeType())
        {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster()
{
    std::cout << "Instance destroyed\n";
}

int main()
{
    const int NUMOFCOMMAS = 8; // Also index of last position in array

    std::string tempId;
    std::string tempFirstName;
    std::string tempLastName;
    std::string tempEmail;
    int tempAge;
    int tempCourse1Days;
    int tempCourse2Days;
    int tempCourse3Days;
    int tempIntDegreeType;
    int tempDaysToComplete3Courses[3];
    std::string tempStringDegreeType;

    std::string tempStudentData[NUMOFCOMMAS];
    Degree tempDegreeType;

    int oldCommaPosition = 0;
    int currentCommaPosition = 0;

    const std::string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Thomas,Paul,tpaul9@wgu.edu,25,30,15,15,SOFTWARE"
    };

    std::cout << "Course: C867 \nLanguage: C++ \nStudent Id: #000917547 \nName: Thomas Paul\n\n";

    Roster classRoster;

    for (std::string student : studentData)
    {
        for (int i = 0; i < NUMOFCOMMAS; ++i)
        {
            if (i == 0)
            {
                oldCommaPosition = currentCommaPosition;
            }
            else
            {
                oldCommaPosition = currentCommaPosition + 1;
            }


            currentCommaPosition = student.find(",", oldCommaPosition);
            //std::cout << "\n" << i << ": " << student.substr(oldCommaPosition, currentCommaPosition - oldCommaPosition);
            tempStudentData[i] = student.substr(oldCommaPosition, currentCommaPosition - oldCommaPosition);


            if (i == 7)
            {
                tempStringDegreeType = student.substr(currentCommaPosition + 1);

                if (tempStringDegreeType == "NETWORK")
                {
                    tempDegreeType = NETWORK;
                }

                else if (tempStringDegreeType == "SECURITY")
                {
                    tempDegreeType = SECURITY;
                }

                else
                {
                    tempDegreeType = SOFTWARE;
                }

                
                tempId = tempStudentData[0];
                tempFirstName = tempStudentData[1];
                tempLastName = tempStudentData[2];
                tempEmail = tempStudentData[3];
                tempAge = std::stoi(tempStudentData[4]);
                tempDaysToComplete3Courses[0] = std::stoi(tempStudentData[5]);
                tempDaysToComplete3Courses[1] = std::stoi(tempStudentData[6]);
                tempDaysToComplete3Courses[2] = std::stoi(tempStudentData[7]);

                
                classRoster.add(tempId, 
                                tempFirstName, 
                                tempLastName, 
                                tempEmail, 
                                tempAge, 
                                tempDaysToComplete3Courses[0], 
                                tempDaysToComplete3Courses[1], 
                                tempDaysToComplete3Courses[2], 
                                tempDegreeType);
            }
        }

        
        oldCommaPosition = 0;
        currentCommaPosition = 0;

    }
    std::cout << "\n";

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < sizeOfRoster; ++i)
    {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }

    std::cout << "\n";

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    classRoster.~Roster();

    return 0;
}