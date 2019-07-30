#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string>
#include <vector>
#include <QString>

using namespace std;

class person
{
protected:
    QString name;
    QString surname;
    QString pid;
    QString residence;

public:
    person();

    // getters
    const QString getName() const;
    const QString getSurname() const;
    const QString getPid() const;
    const QString getResidence() const;

    // setters
    void setName(QString name);
    void setSurname(QString surname);
    void setPid(QString pid);
    void setResidence(QString residence);



};

#endif // PERSON_H
