#include<iostream>
#include "my_array.h"

using namespace std;

int main()
{
    MyArray arr1;
    MyArray arr2, arr3;

    arr1.add(3);
    arr1.add(4);
    arr1.add(5);
    arr1.del();

    arr1.info();

    arr2.add(5);
    arr2.add(3);

    arr2.info();
    arr3 = arr1 + arr2;
    std::cout << std::endl;
    arr3.info();

    MyArray arr4;

    arr4 = arr3++;
    arr4.info();

    return 0;
}
