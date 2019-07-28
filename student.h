#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Student:public person
{

    string registration;
    int subjects;

public:

    // constructors
    Student();
    Student(string name, string surname, string pid, string residence, string registration, int subjects);

    // destructor
    ~Student();

    // getters
    const string getReg() const;
    const int getSubjects() const;

    // setters
    void setReg(string registration);
    void setSubjects(int subjects);

    void addStudent(string &name, string &surname, string &pid, string &residence, vector<Student *> &students);
};

#endif // STUDENT_H
