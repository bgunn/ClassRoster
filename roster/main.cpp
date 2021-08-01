//
//  main.cpp
//  roster
//
//  Created by William Gunn on 7/29/21.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"
using namespace std;

// Global constants
const string COURSE = "Scripting and Programming - Applications – C867";
const string STUDENT_NAME = "William Gunn";
const string STUDENT_ID = "#001521978";
const string LANGUAGE = "C++14";

const int NUM_STUDENTS = 5;
const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,William,Gunn,wgunn@my.wgu.edu,49,10,20,14,SOFTWARE"
};

DegreeProgram degreeProgramFromString(string program) {
    if (program == "SECURITY") return SECURITY;
    else if (program == "NETWORK") return NETWORK;
    else if (program == "SOFTWARE") return SOFTWARE;
    else return NONE;
}

vector<string> parseCSV(string row) {
    
    stringstream ss(row);
    vector<string> result;

    while( ss.good() )
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }
    
    return result;
}

int main() {
    
    cout << endl;
    cout << COURSE << endl;
    cout << STUDENT_NAME << " " << STUDENT_ID << endl;
    cout << "Language: " << LANGUAGE << endl << endl;
    
    Roster* classRoster = new Roster(NUM_STUDENTS);

    for (const string &row : studentData) {
        
        vector<string> parsed = parseCSV(row);
        
        classRoster->add(
            parsed[0],
            parsed[1],
            parsed[2],
            parsed[3],
            stoi(parsed[4]),
            stoi(parsed[5]),
            stoi(parsed[6]),
            stoi(parsed[7]),
            degreeProgramFromString(parsed[8])
        );
    }
    
    cout << "Class Roster:" << endl;
    classRoster->printAll();
    
    cout << "Invalid Emails:" << endl;
    classRoster->printInvalidEmails();
    
    cout << "Average Days In Course:" << endl;
    Student** classRosterArray = classRoster->getClassRoster();
    
    for (int i = 0; i < classRoster->getRosterSize(); i++) {
        classRoster->printAverageDaysInCourse((classRosterArray)[i]->getStudentId());
    }
    
    cout << endl << "Software Degree Program Roster:" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    
    cout << "Removing Student A3" << endl;
    classRoster->remove("A3");
    
    cout << endl << "Updated Class Roster:" << endl;
    classRoster->printAll();
    
    cout << "Removing Student A3" << endl;
    classRoster->remove("A3");
    
    cout << endl;
}
