#include "Decart.h"
#include "Polar.h"

#include <iostream>

int main()
{
    Decart a(2, 3);
    Polar b(3, 2);

    std::cout << "Decart point A:" << a << std::endl;
    std::cout << "Polar point A:" << Polar(a) << "\n\n";

    std::cout << "Polar point B:" << b << std::endl;
    std::cout << "Decart point B:" << Decart(b) << "\n\n";

    Decart c(b);
    Polar d(a);

    std::cout << "init C:" << c << std::endl;
    std::cout << "init D:" << d << std::endl;

    return 0;
}
