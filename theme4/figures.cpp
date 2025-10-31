#include "figures.h"
#include <cmath>

Triangle::Triangle(double s1, double s2, double s3) {
    a = s1; b = s2, c = s3;
}

double Triangle::square() const {
    double p = perim() / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perim() const {
    return a + b + c;
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle(" << a << ", " << b << ", " << c << ')';
}

//////////////////////////////////////////////////////

Circle::Circle(double radius) {
    r = radius;
}

double Circle::square() const {
    return M_PI * r * r;
}

double Circle::perim() const {
    return 2 * M_PI * r;
}

void Circle::print(std::ostream& os) const {
    os << "Circle(" << r << ')';
}

//////////////////////////////////////////////////////

Rectangle::Rectangle(double width, double height) {
    w = width; h = height;
}

double Rectangle::square() const {
    return w * h;
}

double Rectangle::perim() const {
    return (w + h) * 2;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle(" << w << ", " << h << ')';
}