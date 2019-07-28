#include "teacher.h"

teacher::teacher()
{

}

const string teacher::getQual() const
{
    return qualification;
}

const string teacher::getExp() const
{
    return exp;
}

const string teacher::getSubject() const
{
    return subject;
}

void teacher::setQual(string qualification)
{
    this->qualification = qualification;
}

void teacher::setExp(string exp)
{
    this->exp = exp;
}

void teacher::setSubject(string subject)
{
    this->subject = subject;
}
