#pragma once
#include <iostream>

class Figure2 {
public:
	virtual double perim() const = 0;
	virtual double square() const = 0;

	virtual void print(std::ostream& os) const = 0;

};

std::ostream& operator<<(std::ostream& os, const Figure2& figure);
