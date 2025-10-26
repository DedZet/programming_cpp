#include<iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction f1(1, 2);
    Fraction f2 = 3;
    Fraction f3;

    f3 = f1 + f2;
    std::cout << f3 << std::endl;

    f3 = f1 + 2;
    std::cout << f3 << std::endl;

    f3 = 2 + f1;
    std::cout << f3 << std::endl;

    f3 = f1 - f2;
    std::cout << f3 << std::endl;

    f3 = f1 - 2;
    std::cout << f3 << std::endl;

    f3 = 2 - f1;
    std::cout << f3 << std::endl;

    double x = double(f3);
    std::cout << x << std::endl;
 

    return 0;
}
