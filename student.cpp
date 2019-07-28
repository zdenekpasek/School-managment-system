#include "student.h"

Student::Student()
{

}

Student::Student(string name, string surname, string pid, string residence, string registration, int subjects)
{
    this->name = name;
    this->surname = surname;
    this->pid = pid;
    this->residence = residence;
    this->registration = registration;
    this->subjects = subjects;

}

const string Student::getReg() const
{
    return registration;
}

const int Student::getSubjects() const
{
    return subjects;
}

void Student::setReg(string registration)
{
    this->registration = registration;
}

void Student::setSubjects(int subjects)
{
    this->subjects = subjects;
}



/*
void Student::addStudent(string &name, string &surname, string &pid, string &residence, vector<Student *> &students)
{
    students.push_back(new Student(name, surname, pid, residence));
}
*/
