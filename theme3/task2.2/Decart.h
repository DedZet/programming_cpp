#ifndef DECART_H
#define DECART_H

#include <cmath>
#include <iostream>

class Polar;

class Decart {
public:
	double x;
	double y;

	Decart();
	Decart(double x_, double y_);
	Decart(Polar& p);

	operator Polar();

};

std::ostream& operator << (std::ostream& os, const Decart& p);



#endif