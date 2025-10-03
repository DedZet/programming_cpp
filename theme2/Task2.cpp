#include <iostream>
#include "MyTime.h"


int main() {
    MyTime t1, t2(3,15,30);

    MyTime t3(2, 3, 4);


    t3.info();
    t2.info();

    t1 = t2.mtAdd(t3);
    t1.info();
    return 0;

}
