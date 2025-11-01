#include <iostream>
#include "mytemplates.h"
#include "person.h"
#include <string>

class Complex {
public:
	double re;
	double im;
	Complex() {
		re = 0; im = 0;
	}

	Complex(double re_, double im_ = 0) {
		re = re_; im = im_;
	}

	std::string info() {
		if (im > 0)			return std::to_string(re) + " + i*" + std::to_string(im);
		else if (im < 0)	return std::to_string(re) + " - i*" + std::to_string(im);
		else				return std::to_string(re);
	}

	Complex operator+(const Complex& other) const {
		return Complex(re + other.re, im + other.im);
	}

	Complex& operator+=(const Complex& other) {
		re += other.re;
		im += other.im;
		return *this;
	}

	Complex operator/(int div) const {
		return Complex(re / div, im / div);
	}

};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << c.re;
	if (c.im >= 0)
		os << " + " << c.im << "i";
	else
		os << " - " << -c.im << "i";
	return os;
}

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int size = 5;
    
    int arrInt[5] = { 10, 5, -3, 8, 15 };
    for (int i = 0; i < size ; i++) cout << arrInt[i] << ", ";
    cout << "\nСумма элементов массива: " << sum(arrInt, size);
    cout << "\nСр арифметическое массива: " << medium(arrInt, size) << endl << endl;

    Complex arrComplex[5] = {
        Complex(2, -2),
        Complex(3, -5),
        Complex(5, 4),
        Complex(5, 3),
        Complex(3, 2)
    };

    for (int i = 0; i < size - 1; i++) cout << arrComplex[i].info() << ", ";
    cout << "\nСумма элементов массива arrPerson: " << sum(arrComplex, size) << "\n";
    cout << "\nСр арифметическое массива: " << medium(arrComplex, size) << "\n";


    return 0;
}

