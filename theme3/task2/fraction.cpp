#include "fraction.h"
#include <iostream>

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
}

Fraction::Fraction(int n) {
	numerator = n;
	denominator = 1;
}

Fraction operator+(Fraction f1, Fraction f2) {
	Fraction result;
	result.denominator = f1.denominator * f2.denominator;
	result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	return result;
}

Fraction operator+(Fraction f1, int n) {
	Fraction result;
	result.denominator = f1.denominator;
	result.numerator = f1.numerator + n * f1.denominator;
	return result;
}

Fraction operator+(int n, Fraction f2) {
	Fraction result;
	result.denominator = f2.denominator;
	result.numerator = f2.numerator + n * f2.denominator;
	return result;
}

Fraction operator-(Fraction f1, Fraction f2) {
	Fraction result;
	result.denominator = f1.denominator * f2.denominator;
	result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	return result;
}

Fraction operator-(Fraction f1, int n) {
	Fraction result;
	result.denominator = f1.denominator;
	result.numerator = f1.numerator - n * f1.denominator;
	return result;
}

Fraction operator-(int n, Fraction f2) {
	Fraction result;
	result.denominator = f2.denominator;
	result.numerator = n * f2.denominator - f2.numerator;
	return result;
}

std::ostream& operator << (std::ostream &os, const Fraction &f) {
	return os << f.getNum() << "/" << f.getDenom();
}

Fraction::operator double() {
	return (double)numerator / (double)denominator;
}

int Fraction::getNum() const {
	return numerator;
}
int Fraction::getDenom() const {
	return denominator;
}
