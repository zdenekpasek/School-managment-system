#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <QString>

using namespace std;

class teacher:public person
{

    QString qualification;
    QString exp;
    QString subject;

public:
    // constructors
    teacher();

    // destructor
    ~teacher();

    // getters
    const QString getQual() const;
    const QString getExp() const;
    const QString getSubject() const;

    // setters
    void setQual(QString qualification);
    void setExp(QString exp);
    void setSubject(QString subject);

};

#endif // TEACHER_H
