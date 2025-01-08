#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

const static string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Leigh,Grover,lgrov45@wgu.edu,40, 30, 25, 35,SOFTWARE" };

int main() {

	cout << "Name of Class: Scripting and Programming C867\nLanguage Used: C++\nWGU ID: 009689385\nName: Leigh Grover" << endl;

	Roster classRoster;

	for(unsigned i=0; i< NUM_STUDENTS; i++){
		classRoster.parse(studentData[i]);//feeding the parse function each line of the student data roster
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	cout << "\nDisplaying average days in courses:\n" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++) { 
		//loop through classRosterArray and for each element:
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->Student::getID());
	};

	classRoster.printByDegreeProgram(SOFTWARE);
	
	classRoster.remove("A3");

	classRoster.printAll();

	cout << "\nRemove A3 again:" << endl;

	classRoster.remove("A3");

	return 0;

}