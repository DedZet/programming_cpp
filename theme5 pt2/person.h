#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <sstream>
#include <cstring>

class Person
{
    public:
    std::string name = " ";
    int birthYear;

    Person();
    Person(std::string name, int birthYear);

    void info();
    operator char* ();

    bool operator <(Person p) const;
    bool operator >(Person p) const;
    bool operator ==(Person p) const;
 
};

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
