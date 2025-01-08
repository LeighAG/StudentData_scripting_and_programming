#include <iostream>
#include <string>
#include <iomanip> 
#include "student.h"

using namespace std;

//constructor list to set default values
Student::Student() : studentID(""), firstName(""), lastName(""), email(""), age(0), daysInCourse(new int[COURSES_NUM]), degreeprogram(SOFTWARE) {
	for (int i = 0; i < COURSES_NUM; i++) {
		this->daysInCourse[i] = 0;
	}
}

//parameterized full constructor 
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeprogram) :
	studentID(studentID),
	firstName(firstName),
	lastName(lastName),
	email(email),
	age(age),
	degreeprogram(degreeprogram) {
	this->daysInCourse = new int[COURSES_NUM];//Allocates memory needed to store the array and the pointer will store the address to this block of memory.
	for (int i = 0; i < COURSES_NUM; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

//full getters
string Student::getID() const { 
	return studentID; 
}
string Student::getFirstName() const { 
	return firstName; 
}
string Student::getLastName() const { 
	return lastName; 
}

string Student::getEmail() const { 
	return email; 
}

int Student::getAge() const { 
	return age; 
}

int* Student::getDaysInCourse() {
	return this->daysInCourse; 
}

DegreeProgram Student::getDegreeprogram() {
	return degreeprogram;
}

//full setters
void Student::setID(string ID) { 
	this->studentID = ID; 
}

void Student::setFirstName(string first) { 
	this->firstName = first; 
}

void Student::setLastName(string last) { 
	this->lastName = last; 
}
void Student::setEmail(string email) { 
	this->email = email; 
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	this-> daysInCourse = new int[COURSES_NUM];
	for(unsigned i=0; i<COURSES_NUM; i++){
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setddegreeprogram(DegreeProgram degreeprogram) {
	this->degreeprogram = degreeprogram;
}

void Student::print(){
	cout << studentID;
	cout << "\tFirst Name: " << left << setw(2) << firstName;
	cout << "\tLast Name: " << left << setw(2) << lastName;
	cout << "\tEmail: " << left << setw(2) << email;
	cout << "\tAge:" << left << setw(2) << age;
	cout << "\tDays in course:{" << left << setw(1) << daysInCourse[0]<<", ";
	cout << left << setw(1) << daysInCourse[1] << ", ";
	cout << left << setw(1) << daysInCourse[2]<<"} ";
	if (getDegreeprogram()==0){
		cout << "\tDegree Program: "<< setw(2) << "SECURITY"<<endl;
	}
	else if (getDegreeprogram() == 1) {
		cout << "\tDegree Program: " << setw(2) << "NETWORK" << endl;
	} 
	else if (getDegreeprogram() == 2) {
		cout << "\tDegree Program: " << setw(2) << "SOFTWARE" << endl;
	}
}

//destructor 
Student::~Student() {}


