//
//  roster.h
//  roster
//
//  Created by William Gunn on 7/30/21.
//

#ifndef roster_h
#define roster_h

#include <string>
#include "student.h"
using namespace std;

class Roster {
    
private:
    
    Student** classRosterArray;
    int students;
    int rosterSize;
    
public:
    
    Roster();
    Roster(int numStudents);
    Roster(const Roster& origClass);
    ~Roster();
    
    int getRosterSize();
    Student** getClassRoster();
    
    // Mutators
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};


#endif
