#include "student.h"

Student::Student()
{

}

Student::Student(QString &name, QString &surname, QString &pid, QString &residence, QString &registration, int subjects)
{
    this->name = name;
    this->surname = surname;
    this->pid = pid;
    this->residence = residence;
    this->registration = registration;
    this->subjects = subjects;

}

const QString Student::getReg() const
{
    return registration;
}

const int Student::getSubjects() const
{
    return subjects;
}

void Student::setReg(QString registration)
{
    this->registration = registration;
}

void Student::setSubjects(int subjects)
{
    this->subjects = subjects;
}

void Student::addStudentToVector(QString &name, QString &surname, QString &pid, QString &residence, QString &registration, int &subjects, vector<Student *> &students)
{
    students.push_back(new Student(name, surname, pid, residence, registration, subjects));
}



