#include <iostream>
#include <string>
#include "mytemplates.h"

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

	friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
		os << c.re;
		if (c.im >= 0)
			os << " + " << c.im << "i";
		else
			os << " - " << -c.im << "i";
		return os;
	}

};

class Fraction {
public:
	int numerator;
	int denominator;

	Fraction() {
		numerator = 0;
		denominator = 1;
	}
	Fraction(int num, int denom) {
		numerator = num;
		denominator = denom;
	}
	Fraction(int n) {
		numerator = n;
		denominator = 1;
	}
	operator double() {
		return (double)numerator / (double)denominator;
	}

	std::string info() {
		return std::to_string(numerator) + "/" + std::to_string(denominator);
	}

	friend Fraction operator+(Fraction f1, Fraction f2) {
		Fraction result;
		result.denominator = f1.denominator * f2.denominator;
		result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		return result;
	}
	friend Fraction operator+(Fraction f1, int n) {
		Fraction result;
		result.denominator = f1.denominator;
		result.numerator = f1.numerator + n * f1.denominator;
		return result;
	}
	friend Fraction operator+(int n, Fraction f2) {
		Fraction result;
		result.denominator = f2.denominator;
		result.numerator = f2.numerator + n * f2.denominator;
		return result;
	}


	friend Fraction operator-(Fraction f1, Fraction f2) {
		Fraction result;
		result.denominator = f1.denominator * f2.denominator;
		result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		return result;
	}
	friend Fraction operator-(Fraction f1, int n) {
		Fraction result;
		result.denominator = f1.denominator;
		result.numerator = f1.numerator - n * f1.denominator;
		return result;
	}
	friend Fraction operator-(int n, Fraction f2) {
		Fraction result;
		result.denominator = f2.denominator;
		result.numerator = n * f2.denominator - f2.numerator;
		return result;
	}

	bool operator<(const Fraction& f2) const {
		bool result = (numerator * f2.denominator) < (f2.numerator * denominator);
		return result;
	}
	bool operator>(const Fraction& f2) const {
		bool result = (numerator * f2.denominator) > (f2.numerator * denominator);
		return result;
	}

	friend std::ostream& operator << (std::ostream& os, const Fraction& f) {
		return os << f.numerator << "/" << f.denominator;
	}
};

using namespace std;

void testComplex(int size = 5) {
	Complex arrComplex[5] = {
		Complex(2, -2),
		Complex(3, -5),
		Complex(5, 4),
		Complex(5, 3),
		Complex(3, 2)
	};

	cout << "\n\narrComplex [";
	for (int i = 0; i < size - 1; i++) cout << arrComplex[i].info() << ", ";
	cout << "] \nСумма элементов: " << sum(arrComplex, size);
	cout << "\nСр арифметическое: " << medium(arrComplex, size);
}

void testFraction(int size = 5) {

	Fraction arrFraction[5] = {
		Fraction(2, 3),
		Fraction(3, 6),
		Fraction(2, 4),
		Fraction(15, 3),
		Fraction(4, 5)
	};

	cout << "\n\narrFraction [";
	for (int i = 0; i < size - 1; i++) cout << arrFraction[i].info() << ", ";

	Fraction a(2, 3), b(1, 2);
	cout << "] \nКол-во элементов больше заданного: " << amountMore(arrFraction, size, b);
	cout << "\nКол-во элементов меньше заданного: " << amountLess(arrFraction, size, a);
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size = 5;

	int arrInt[5] = { 10, 5, -3, 8, 15 };	cout << "arrInt [";

	for (int i = 0; i < size; i++) cout << arrInt[i] << ", ";

	cout << "] \nСумма элементов: " << sum(arrInt, size);
	cout << "\nСр арифметическое: " << medium(arrInt, size);
	cout << "\nКол-во элементов больше заданного: " << amountMore(arrInt, size, 2);
	cout << "\nКол-во элементов меньше заданного: " << amountLess(arrInt, size, 3);

	testComplex();
	testFraction();
	cout << endl;
	

	return 0;
}

