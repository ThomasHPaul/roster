#include "roster.h"

Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysIncourse1, int daysInCourse2, int daysInCourse3, Degree degreeType)
{
    // initialize student
        // Student(pass params)
    
    // assign student pointer to spot first empty spot in array
        // assign student pointer into variable
        // determine first nullptr position
        // assign student pointer var into first nullptr position
}

void Roster::remove(std::string studentId)
{
    
}

void Roster::printAll()
{
    //for (Student& student : classRosterArray)
    //{
    //    student.print();
    //}
}

void Roster::printDaysInCourse(std::string studentId)
{

}

void Roster::printInvalidEmails()
{

}

void Roster::printByDegreeProgram(int degreeProgram)
{

}

Roster::~Roster()
{

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

    //Roster classRoster;

    // FIXME: add each student to classRoster


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


                tempId = tempStudentData[0];
                tempFirstName = tempStudentData[1];
                tempLastName = tempStudentData[2];
                tempEmail = tempStudentData[3];
                tempAge = std::stoi(tempStudentData[4]);
                tempDaysToComplete3Courses[0] = std::stoi(tempStudentData[5]);
                tempDaysToComplete3Courses[1] = std::stoi(tempStudentData[6]);
                tempDaysToComplete3Courses[2] = std::stoi(tempStudentData[7]);

                if (tempStringDegreeType == "NETWORK")
                {
                    std::cout << "Network student initialized\n";
                    /*
                        NetworkStudent student = new NetworkStudent(
                            tempId,
                            tempFirstName,
                            tempLastName,
                            tempEmail,
                            tempAge,
                            tempDaysToComplete3Courses,
                            NETWORK);
                    */
                }

                else if (tempStringDegreeType == "SECURITY")
                {
                    std::cout << "Security student initialized\n";
                    /*
                        NetworkStudent student = new NetworkStudent(
                            tempId,
                            tempFirstName,
                            tempLastName,
                            tempEmail,
                            tempAge,
                            tempDaysToComplete3Courses,
                            SECURITY);
                    */
                }

                else
                {
                    std::cout << "Software student initialized\n";
                    /*
                        NetworkStudent student = new NetworkStudent(
                            tempId,
                            tempFirstName,
                            tempLastName,
                            tempEmail,
                            tempAge,
                            tempDaysToComplete3Courses,
                            SOFTWARE);
                    */
                }





            }
        }

        // add student
        oldCommaPosition = 0;
        currentCommaPosition = 0;

    }


    return 0;
}