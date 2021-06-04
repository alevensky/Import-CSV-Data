#include <iostream>
#include <string>
using namespace std;

#include "student.h"

//Getters

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int Student::getDay1() {
	return days[0];
}

int Student::getDay2() {
	return days[1];
}

int Student::getDay3() {
	return days[2];
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//Setters

void Student::setStudentID(string newID) {
	studentID = newID;
	return;
}

void Student::setFirstName(string newFirstName) {
	firstName = newFirstName;
	return;
}

void Student::setLastName(string newLastName) {
	lastName = newLastName;
	return;
}

void Student::setEmailAddress(string newEmail) {
	emailAddress = newEmail;
	return;
}

void Student::setAge(int newAge) {
	age = newAge;
	return;
}

void Student::setDays(int newDays0, int newDays1, int newDays2) {
	days[0] = newDays0;
	days[1] = newDays1;
	days[2] = newDays2;
	return;
}

void Student::setDegreeProgram(DegreeProgram newProgram) {
	degreeProgram = newProgram;
	return;
}

//Convert enum to string for printing
string Student::convertToString(DegreeProgram toString) {
	if (toString == DegreeProgram::SECURITY) {
		return "SECURITY";
	}
	else if (toString == DegreeProgram::NETWORK) {
		return "NETWORK";
	}
	else {
		return "SOFTWARE";
	}
}

//Reset student object to default values
void Student::resetToDefault() {
	studentID = "Not Defined";
	firstName = "Not Defined";
	lastName = "Not Defined";
	emailAddress = "notapplicable@wgu.edu";
	age = 0;
	days[0] = 0;
	days[1] = 0;
	days[2] = 0;
	degreeProgram = DegreeProgram::SECURITY;
}

//Constructor
Student::Student() {
	studentID = "Not Defined";
	firstName = "Not Defined";
	lastName = "Not Defined";
	emailAddress = "notapplicable@wgu.edu";
	age = 0;
	days[0] = 0;
	days[1] = 0;
	days[2] = 0;
	degreeProgram = DegreeProgram::SECURITY;
}

//Print Functions
void Student::printID() {
	cout <<  studentID << "\t";
}

void Student::printFirstName() {
	cout << "First Name: " << firstName << "\t";
}

void Student::printLastName() {
	cout << "Last Name: " << lastName << "\t";
}

void Student::printEmailAddress() {
	cout << "Email: " << emailAddress << "\t";
}

void Student::printAge() {
	cout << "Age: " << age << "\t";
}

void Student::printDays() {
	cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "}" << "\t";
}

void Student::printDegreeProgram() {
	cout << "Degree Program: " << convertToString(degreeProgram) << "\t";
}