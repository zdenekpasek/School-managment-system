#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string>
#include <vector>
#include "person.h"
#include <QString>

using namespace std;

class Student:public person
{

    QString registration;
    int subjects;

public:

    // constructors
    Student();
    Student(QString &name, QString &surname, QString &pid, QString &residence, QString &registration, int subjects);

    // destructor
    ~Student();

    // getters
    const QString getReg() const;
    const int getSubjects() const;

    // setters
    void setReg(QString registration);
    void setSubjects(int subjects);

    void addStudentToVector(QString &name, QString &surname, QString &pid, QString &residence, QString &registration, int &subjects, vector<Student *> &students);
};

#endif // STUDENT_H
