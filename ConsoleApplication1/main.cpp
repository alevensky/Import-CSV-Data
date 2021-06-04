#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

int main()
{
    cout << "Scripting and Programming - Applications C867\n";
    cout << "Programming language used: C++\n";
    cout << "StudentID: 001370228\n";
    cout << "Andrew Levensky" << endl;

    string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Andrew,Levensky,alevens@wgu.edu,27, 35,40,40,SOFTWARE" };

    Roster classRoster;
    classRoster.parseTableData(studentData);
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
}