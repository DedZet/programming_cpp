#pragma once
#include <iostream>

class Figure3 {
public:
	virtual double volume() const = 0;
	virtual double surface() const = 0;

	virtual void print(std::ostream& os) const = 0;

	bool operator<(Figure3& figure);
	bool operator>(Figure3& figure);
	bool operator==(Figure3& figure);

};

std::ostream& operator<<(std::ostream& os, const Figure3& figure);
