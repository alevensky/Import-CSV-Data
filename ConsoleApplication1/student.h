#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student {
    public:
        //Getters
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int getDay1();
        int getDay2();
        int getDay3();
        DegreeProgram getDegreeProgram();

        //Print Functions
        void printID();
        void printFirstName();
        void printLastName();
        void printEmailAddress();
        void printAge();
        void printDays();
        void printDegreeProgram();

        //Constructor
        Student();

        //Setters
        void setStudentID(string newID);
        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setEmailAddress(string newEmail);
        void setAge(int newAge);
        void setDays(int newDays0, int newDays1, int newDays2);
        void setDegreeProgram(DegreeProgram newProgram);

        string convertToString(DegreeProgram toString);
        void resetToDefault();

    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int days[3];
        DegreeProgram degreeProgram;
};

#endif