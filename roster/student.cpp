//
//  student.cpp
//  roster
//
//  Created by William Gunn on 7/30/21.
//

#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student() {
    _student_id = "";
    _first_name = "";
    _last_name = "";
    _email = "";
    _age = -1;
    for (int i = 0; i < 3; i++) {
        _days[i] = -1;
    }
    _program = NONE;
}

Student::Student(string student_id, string first_name, string last_name, string email, int age, int days[], DegreeProgram program) {
    _student_id = student_id;
    _first_name = first_name;
    _last_name = last_name;
    _email = email;
    _age = age;
    for (int i = 0; i < 3; i++) {
        _days[i] = days[i];
    }
    _program = program;
}

Student::~Student() {
    
}

string Student::getStudentId() {
    return _student_id;
}

string Student::getFirstName() {
    return _first_name;
}

string Student::getLastName() {
    return _last_name;
}

string Student::getEmail() {
    return _email;
}

int Student::getAge() {
    return _age;
}

int* Student::getDays() {
    return _days;
}

DegreeProgram Student::getProgram() {
    return _program;
}

// Mutators
void Student::setStudentId(string student_id) {
    _student_id = student_id;
}

void Student::setFirstName(string first_name) {
    _first_name = first_name;
}

void Student::setLastName(string last_name) {
    _last_name = last_name;
}

void Student::setEmail(string email) {
    _email = email;
}

void Student::setAge(int age) {
    _age = age;
}

void Student::setDays(int days[]) {
    for (int i = 0; i < 3; i++) {
        _days[i] = days[i];
    }
}

void Student::setProgram(DegreeProgram program) {
    _program = program;
}

/*
 Prints the student data in the following format:
 A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
 */
void Student::print() {
    cout << left << getStudentId();
    cout << left << "\tFirst Name: " << setw(8) << getFirstName();
    cout << left << "\tLast Name: " << setw(10) << getLastName();
    cout << left << "\tAge: " << setw(3) << getAge();
    cout << left << "\tdaysInCourse: {" << getDays()[0] << ", " << getDays()[1] << ", " << getDays()[2] << "}";
    cout << left << "\tDegree Program: " << setw(8) << DEGREE_PROGRAM[getProgram()] << endl;
}
