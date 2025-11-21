#include "person.h"

Person::Person()
{
    name = "NO NAME";
    birthYear = 0;
}

Person::Person(std::string name, int birthYear)
{
    this->name = name;
    this->birthYear = birthYear;
}

bool Person::operator<(const Person& p) const
{
    return (this->birthYear < p.birthYear);
}

bool Person::operator>(const Person& p) const
{
    return (this->birthYear > p.birthYear);
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << " (" << p.birthYear << ")";
    return os;
}

Person Person::operator*(int n) const {
    Person result;
    result.birthYear = this->birthYear * n;
    return result;
}