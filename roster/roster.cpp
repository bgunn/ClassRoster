//
//  roster.cpp
//  roster
//
//  Created by William Gunn on 7/30/21.
//

#include <iostream>
#include <iomanip>
#include "roster.h"
using namespace std;

Roster::Roster() {
    students = -1;
    rosterSize = 0;
    classRosterArray = nullptr;
}

Roster::Roster(int numStudents) {
    students = numStudents;
    rosterSize = 0;
    classRosterArray = new Student* [numStudents];
}

Roster::~Roster() {
    
    for (int i = 0; i < rosterSize; i++) {
        delete classRosterArray[i];
    }
    
    delete[] classRosterArray;
}

int Roster::getRosterSize() {
    return rosterSize;
}

Student** Roster::getClassRoster() {
    return classRosterArray;
}

void Roster::add(
     string studentID,
     string firstName,
     string lastName,
     string emailAddress,
     int age,
     int daysInCourse1,
     int daysInCourse2,
     int daysInCourse3,
     DegreeProgram degreeProgram
) {
    
    if (rosterSize < students) {
        int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        classRosterArray[rosterSize] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
        rosterSize++;
    }
}

/*
 Removes a student from the roster by student ID
 */
void Roster::remove(string studentID) {
    
    bool f = false;
    
    for (int i = 0; i < rosterSize; i++) {
        if ((classRosterArray)[i]->getStudentId() == studentID) {
            
            // Delete the specified student from the roster
            delete classRosterArray[i];
            
            // Shif all remaining elements left
            for (int x = i; x < rosterSize; x++) {
                classRosterArray[x] = classRosterArray[x+1];
            }
            
            // Decerese the rosterSize size by 1
            rosterSize--;
            
            f = true;
            
            break;
        }
    }
    
    if (!f) {
        cout << "Student " << studentID << " was not found in the roster!" << endl;
    }
}

/*
 Loop through the classRosterArray and call the print()
 function for each student.
 */
void Roster::printAll() {
    
    for (int i = 0; i < rosterSize; i++) {
        classRosterArray[i]->print();
    }
    
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    
    bool f = false;
    
    for (int i = 0; i < rosterSize; i++) {
        if ((classRosterArray)[i]->getStudentId() == studentID) {
            
            int sum = 0;
            int* days = (classRosterArray)[i]->getDays();
            
            for (int x = 0; x < 3; x++) {
                sum += days[x];
            }
            
            float average = sum / 3.0;
            
            cout << fixed;
            cout << setprecision(2);
            cout << "Average days in course for " << studentID << ": " << average << endl;
            
            f = true;
            
            break;
        }
    }
    
    if (!f) {
        cout << "Student " << studentID << " was not found in the roster!" << endl;
    }
}

void Roster::printInvalidEmails() {
    
    size_t found;
    
    for (int i = 0; i < rosterSize; i++) {
        
        string email = classRosterArray[i]->getEmail();
        
        string invalid = "Invalid email for student " + classRosterArray[i]->getStudentId() + ": " + email;
        
        // Verify no for spaces
        found = email.find(' ');
        if (found != string::npos) {
            cout << invalid << endl;
        }
        
        // Verify email contains '@'
        found = email.find('@');
        if (found == string::npos) {
            cout << invalid << endl;
        }
        
        // Verify email contains '.'
        found = email.find('.');
        if (found == string::npos) {
            cout << invalid << endl;
        }
    }
    
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    
    for (int i = 0; i < rosterSize; i++) {
        if ((classRosterArray)[i]->getProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }

    cout << endl;
}
