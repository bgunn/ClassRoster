//
//  student.h
//  roster
//
//  Created by William Gunn on 7/30/21.
//

#ifndef student_h
#define student_h

#include "degree.h"
#include <string>
using namespace std;

class Student {
    
private:
    
    string _student_id;
    string _first_name;
    string _last_name;
    string _email;
    int _age;
    int _days[3];
    DegreeProgram _program;

public:

    Student();
    Student(string student_id, string first_name, string last_name, string email, int age, int days[], DegreeProgram program);
    Student(const Student& origClass);
    ~Student();
    
    // Accessors
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getProgram();
    
    // Mutators
    void setStudentId(string student_id);
    void setFirstName(string first_name);
    void setLastName(string last_name);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setProgram(DegreeProgram program);
    
    void print();
};


#endif
