#include <iostream>
#include "mytemplates.h"
#include "person.h"

using namespace std;

int main()
{
    Container<int> contInt;
    contInt.add(10);
    contInt.add(3);
    contInt.add(8);
    contInt.add(1);
    contInt.add(5);
    contInt.add(2);
    contInt.add(7);
    cout << contInt << endl;

    contInt.del();
    contInt.del();
    contInt.sort();
    cout << contInt << endl;

    Container<Person> contPerson;
    contPerson.add(Person("Ivan", 1984));
    contPerson.add(Person("Petr", 1988));
    contPerson.add(Person("Natasha", 2014));
    contPerson.add(Person("Olga", 2010));
    contPerson.add(Person("Vasily", 2001));
    contPerson.add(Person("Timofey", 1999));
    contPerson.add(Person("Kostya", 2005));
    cout << contPerson << endl;

    contPerson.del();
    contPerson.del();
    contPerson.sort();
    cout << contPerson << endl;

    return 0;
}