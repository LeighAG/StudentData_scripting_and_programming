#ifndef ROSTER
#define ROSTER
#include <string>
#include "student.h"

using namespace std;

const static int NUM_STUDENTS = 5;

class Roster {
public:
	
	int lastIndex=-1;//index of the last student in roster

	Student* classRosterArray[NUM_STUDENTS];//Create an array of pointers for five students
	
	void parse(string studentData);//Parse each set of data identified in the “studentData Table.”/ Add each student to classRosterArray array.
	
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);//sets the instance variables and updates the roster.
	
	void remove(string studentID);//removes students from the roster by student ID
	
	void printAll();//prints all entries
	
	void printAverageDaysInCourse(string studentID);//prints avg number of days in course from student ID
	
	void printInvalidEmails();//prints invalid emails
	
	void printByDegreeProgram(DegreeProgram degree);//prints by degree topic
	
	~Roster();
};

#endif

