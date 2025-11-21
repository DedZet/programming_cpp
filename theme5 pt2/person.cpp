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

bool Person::operator <(Person p) const
{
    return (this->birthYear < p.birthYear);
}
bool Person::operator >(Person p) const
{
    return (this->birthYear > p.birthYear);
}
bool Person::operator ==(Person p) const {
    return (this->birthYear == p.birthYear);
}

void Person::info()
{
    std::cout << name << "\t" << birthYear << "\n";
}

Person::operator char* ()
{
    std::stringstream result;
    result << name << " " << birthYear;
    return (char*)result.str().c_str();
}

std::ostream& operator<<(std::ostream & os, const Person& p) {
    os << "(" << p.name << "\t" << p.birthYear << ")";
    return os;
}

