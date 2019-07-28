#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class person
{
protected:
    string name;
    string surname;
    string pid;
    string residence;

public:
    person();

    // getters
    const string getName() const;
    const string getSurname() const;
    const string getPid() const;
    const string getResidence() const;

    // setters
    void setName(string name);
    void setSurname(string surname);
    void setPid(string pid);
    void setResidence(string residence);
};

#endif // PERSON_H
