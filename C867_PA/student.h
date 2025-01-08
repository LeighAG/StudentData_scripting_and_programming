#ifndef STUDENT
#define STUDENT
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	//attributes
	const static int COURSES_NUM = 3;
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysInCourse;//create memory to dynamically build array
	DegreeProgram degreeprogram;

	//methods
	Student(); //empty constructor
	Student(string ID, string first, string last, string email, int age, int daysInCourse[], DegreeProgram degree);//parameterized constructor

	//getters
	string getID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge() const;
	int *getDaysInCourse();
	DegreeProgram getDegreeprogram();
	
	//setters
	void setID(string ID);
	void setFirstName(string first);
	void setLastName(string last);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int days[]);
	void setddegreeprogram(DegreeProgram degreeprogram);

	void print();//print function

	~Student();//destructor
};
#endif

