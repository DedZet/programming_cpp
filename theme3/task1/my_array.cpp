#include "my_array.h"
#include <iostream>

MyArray::MyArray()
{
    size = 0;
}

void MyArray::add(float x) {
    data[size] = x;
    size++;
}

void MyArray::del() {
    size--;
}

void MyArray::info() {

    for (int i = 0; i < size; i++) {
        std::cout << data[i] << ", ";
    }
    std::cout << "\n";
}

MyArray MyArray::operator+(MyArray arr2) {
    MyArray result;
    for (int i = 0; i < size; i++) {
        result.add(data[i]);
    }

    for (int i = 0; i < arr2.size; i++) {
        result.add(arr2.data[i]);
    }
    return result;
}

bool MyArray::operator%(float y) {
    for (int i = 0; i < size; i++) {
        if (data[i] == y) return true;
        else return false;
    }
}

MyArray MyArray::operator++(int) {
    MyArray result;
    for (int i = 0; i < size; i++) {
        result.add(data[i] + 1);
    }
    return result;
}