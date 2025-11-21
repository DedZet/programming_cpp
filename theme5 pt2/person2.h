#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
public:
    std::string name;
    int birthYear;
    Person();
    Person(std::string name, int birthYear);
    bool operator<(const Person& p) const;
    bool operator>(const Person& p) const;
    Person operator*(int n) const;
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif // PERSON_H