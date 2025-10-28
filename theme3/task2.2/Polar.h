#ifndef POLAR_H
#define POLAR_H

#include <cmath>
#include <iostream>

class Decart;

class Polar {
public:
	double r;
	double fi;

	Polar();
	Polar(double x_, double y_);
	Polar(Decart& p);

	operator Decart();
};

std::ostream& operator << (std::ostream& os, const Polar& p);

#endif