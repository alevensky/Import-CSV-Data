#include <iostream>
#include <vector>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;

//Constructor
Roster::Roster() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i] = new Student();
	}
}

//Destructor
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
	delete classRosterArray[i];
	}
}

//Convert string data to integer data
int Roster::toInt(string toConvert) {
	int stringConversion = 0;
	stringstream newStringStream(toConvert);
	newStringStream >> stringConversion;
	return stringConversion;
}

//Take string data and use it to find related enum
DegreeProgram Roster::findEnum(string toSearch) {
	if (toSearch == "SECURITY") {
		return DegreeProgram::SECURITY;
	}
	else if (toSearch == "NETWORK") {
		return DegreeProgram::NETWORK;
	}
	else {
		return DegreeProgram::SOFTWARE;
	}
}

//Parse and create objects from data in studentData table
void Roster::parseTableData(string dataToParse[]) {
	//Get large strings from data and separate into individual strings
	for (int i = 0; i < 5; i++) {
		string studentConvertedData[9];
		istringstream stringStream(dataToParse[i]);
		for (int k = 0; k < 9; k++) {
			getline(stringStream, studentConvertedData[k], ',');
		}
		
		//Add data to Student objects
		classRosterArray[i]->setStudentID(studentConvertedData[0]);
		classRosterArray[i]->setFirstName(studentConvertedData[1]);
		classRosterArray[i]->setLastName(studentConvertedData[2]);
		classRosterArray[i]->setEmailAddress(studentConvertedData[3]);
		classRosterArray[i]->setAge(toInt(studentConvertedData[4]));
		classRosterArray[i]->setDays(toInt(studentConvertedData[5]), toInt(studentConvertedData[6]), toInt(studentConvertedData[7]));
		classRosterArray[i]->setDegreeProgram(findEnum(studentConvertedData[8]));
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeProgram) {
	Student newStudent;
	newStudent.setStudentID(studentID);
	newStudent.setFirstName(firstName);
	newStudent.setLastName(lastName);
	newStudent.setEmailAddress(emailAddress);
	newStudent.setAge(age);
	newStudent.setDays(daysInCourse1, daysInCourse2, daysInCourse3);
	newStudent.setDegreeProgram(degreeProgram);

	//Look for empty slot in roster and place new student into it
	int result = 0;
	for (int i = 0; i < 5; i++) {
		string iD = classRosterArray[i]->getStudentID();
		if (iD == "Not Defined") {
			*classRosterArray[i] = newStudent;
		}
		else {
			result++;
			continue;
		}
	}
	//If no empty slots were found in roster, update
	//the first slot with the new student
	if (result == 5) {
		*classRosterArray[0] = newStudent;
	}
}

void Roster::remove(string studentID) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			classRosterArray[i]->resetToDefault();
		}
		else {
			counter++;
			continue;
		}
	}
	if (counter == 5) {
		cout << "Error: no student in the roster matches the given ID!";
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() != "Not Defined") {
			classRosterArray[i]->printID();
			classRosterArray[i]->printFirstName();
			classRosterArray[i]->printLastName();
			classRosterArray[i]->printAge();
			classRosterArray[i]->printEmailAddress();
			classRosterArray[i]->printDays();
			classRosterArray[i]->printDegreeProgram();
			cout << endl;
		}
		else {
			continue;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int studentDays[3];
	for (int i = 0; i < 5; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			studentDays[0] = classRosterArray[i]->getDay1();
			studentDays[1] = classRosterArray[i]->getDay2();
			studentDays[2] = classRosterArray[i]->getDay3();
		}
	}
	int average = (studentDays[0] + studentDays[1] + studentDays[2]) / 3;
	cout << "The average number of days for student of ID: " << studentID 
		<< " to complete their courses is " << average << " days." << endl;
}

void Roster::printInvalidEmails() {
	cout << "Invalid email addresses: " << endl;
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find("@") == string::npos) {
			cout << email << endl;
		}
		else if (email.find(".") == string::npos) {
			cout << email << endl;
		}
		else if (email.find(" ") != string::npos) {
			cout << email << endl;
		}
		else {
			counter++;
			continue;
		}
	}
	if (counter == 5) {
		cout << "No invalid email addresses found." << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in the specified degree program:" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			string firstName = classRosterArray[i]->getFirstName();
			string lastName = classRosterArray[i]->getLastName();
			cout << firstName << " " << lastName << endl;
		}
	}
}