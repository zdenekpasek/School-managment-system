#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

using namespace std;

class teacher:public person
{

    string qualification;
    string exp;
    string subject;

public:
    // constructors
    teacher();

    // destructor
    ~teacher();

    // getters
    const string getQual() const;
    const string getExp() const;
    const string getSubject() const;

    // setters
    void setQual(string qualification);
    void setExp(string exp);
    void setSubject(string subject);

};

#endif // TEACHER_H
