#include "person.h"

person::person()
{

}

const string person::getName() const
{
    return name;
}

const string person::getSurname() const
{
    return surname;
}

const string person::getPid() const
{
    return pid;
}

const string person::getResidence() const
{
    return residence;
}

void person::setName(string name)
{
    this->name = name;
}

void person::setSurname(string surname)
{
    this->surname = surname;
}

void person::setPid(string pid)
{
    this->pid = pid;
}

void person::setResidence(string residence)
{
    this->residence = residence;
}
