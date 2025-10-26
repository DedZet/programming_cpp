#pragma once
#include <iostream>

class Fraction {
public:
	int numerator;
	int denominator;
	Fraction();
	Fraction(int numerator, int denomnator);
	Fraction(int n);
	operator double();

	int getNum() const;
	int getDenom() const;
};
std::ostream& operator << (std::ostream& os, const Fraction& f);

Fraction operator +(Fraction f1, Fraction f2);
Fraction operator +(Fraction f1, int n);
Fraction operator +(int n, Fraction f2);

Fraction operator -(Fraction f1, Fraction f2);
Fraction operator -(Fraction f1, int n);
Fraction operator -(int n, Fraction f2);
