#include <iostream>
#include "roster.h"
#include <string>

using namespace std;

void Roster::parse(string studentData) {
	//parses StudentID
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	//parses first name
	size_t lhs = (rhs + 1);
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	//parses last name
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	//parses email
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	//parses age
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	//parses days to complete class 1
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	//parses days to complete class 2
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	//parses days to complete class 3
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	//parse degree program
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	DegreeProgram degreeprogram;
	if ((studentData.substr(lhs, rhs - lhs)) == "SECURITY") {
		degreeprogram = SECURITY;
	}
	else if ((studentData.substr(lhs, rhs - lhs)) == "NETWORK") {
		degreeprogram = NETWORK;
	}
	else if ((studentData.substr(lhs, rhs - lhs)) == "SOFTWARE") {
		degreeprogram = SOFTWARE;
	}

	//add student object to roster.
	Roster::add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

//add student object to the class roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	int tempArrayDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };//create array to put in new student object

	lastIndex++;

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, tempArrayDays, degreeprogram);	//create new student object, build rosterIndex
}

//print all function
void Roster::printAll() {
	cout << "\nDisplaying all Students: \n" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		classRosterArray[i]->Student::print();
	}
}

//remove function
void Roster::remove(string studentID) {
	bool match = false;
	string student_ID = studentID;
	for (int i = 0; i <= lastIndex; i++) {
		//match entry with ID
		if ((classRosterArray[i]->Student::getID()) == studentID) {
			match = true;
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];//Reassign the memory pointer
			lastIndex--;//remove last index because it is a duplicate
		}
	}
	if (match) { cout << "\nRemoved student with ID of " << student_ID << endl; }
	else { cout << "\nStudent with ID " << student_ID << " was not found" << endl; }
}

//print average days in class from student ID
void Roster::printAverageDaysInCourse(string studentID) {
	//run loop to find entry with matching ID
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if ((classRosterArray[i]->Student::getID()) == studentID) {
			found = true;
			//create new array in function to easily access integers
			int* avgDays = classRosterArray[i]->getDaysInCourse();
			cout << "Student ID: " << classRosterArray[i]->Student::getID() << ", average days in course is: " << ((avgDays[0] + avgDays[1] + avgDays[2]) / 3) << endl;
		}
	}
	if (!found) {
		cout << "\nStudent ID not found." << endl;
	}
}

void Roster::printInvalidEmails() {
	cout << "\nDisplaying invalid emails.\n" << endl;
	//loop through all entries, get emails and add to a temp array
	for (int i = 0; i <= lastIndex; i++) {
		bool atSymbol = false;
		bool period = false;
		bool space = false;
		string email = classRosterArray[i]->Student::getEmail();
		//loop through temp array to check each email 
		for (unsigned j = 0; j < email.size(); ++j) {
			if (email.at(j) == ' ') {
				space = true;
			}
		}
		for (unsigned j = 0; j < email.size(); ++j) {
			if (email.at(j) == '@') {
				atSymbol = true;
			}
		}
		for (unsigned j = 0; j < email.size(); ++j) {
			if (email.at(j) == '.') {
				period = true;
			}
		}
		if (!atSymbol || space || !period) {
			cout << email << "- is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	if (degreeprogram == 0) {
		cout << "\nList of students in degree program: SECURITY\n" << endl;
	}
	else if (degreeprogram == 1) {
		cout << "\nList of students in degree program: NETWORK\n" << endl;
	}
	else if (degreeprogram == 2) {
		cout << "\nList of students in degree program: SOFTWARE\n" << endl;
	}
	for (int i = 0; i <= lastIndex; i++) {
		if (degreeprogram == classRosterArray[i]->Student::getDegreeprogram()) {
			classRosterArray[i]->Student::print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < lastIndex; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
