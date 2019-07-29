#include "person.h"

person::person()
{

}

const QString person::getName() const
{
    return name;
}

const QString person::getSurname() const
{
    return surname;
}

const QString person::getPid() const
{
    return pid;
}

const QString person::getResidence() const
{
    return residence;
}

void person::setName(QString name)
{
    this->name = name;
}

void person::setSurname(QString surname)
{
    this->surname = surname;
}

void person::setPid(QString pid)
{
    this->pid = pid;
}

void person::setResidence(QString residence)
{
    this->residence = residence;
}
