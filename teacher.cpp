#include "teacher.h"

teacher::teacher()
{

}

const QString teacher::getQual() const
{
    return qualification;
}

const QString teacher::getExp() const
{
    return exp;
}

const QString teacher::getSubject() const
{
    return subject;
}

void teacher::setQual(QString qualification)
{
    this->qualification = qualification;
}

void teacher::setExp(QString exp)
{
    this->exp = exp;
}

void teacher::setSubject(QString subject)
{
    this->subject = subject;
}
