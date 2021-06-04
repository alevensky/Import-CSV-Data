#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {
	public:	

		//Constructor
		Roster();
		//Destructor
		~Roster();

		Student* classRosterArray[5];

		//Utility class to convert string data to integer data
		int toInt(string toConvert);

		DegreeProgram findEnum(string toSearch);

		void parseTableData(string dataToParse[]);

		//Add new student data to roster and student class instance variables
		void add(string studentID, string firstName, string lastName, string emailAddress, 
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, 
			DegreeProgram degreeProgram);

		//Remove student by ID if they exist, otherwise print an error
		void remove(string studentID);

		void printAll();

		void printAverageDaysInCourse(string studentID);

		void printInvalidEmails();

		void printByDegreeProgram(DegreeProgram degreeProgram);

};

#endif