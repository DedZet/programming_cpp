#include "volumetric_figures.h"
#include <cmath>

Sphere::Sphere(double radius) {
    r = radius;
}

double Sphere::volume() const {
    return (4 / 3) * M_PI * r * r * r;
}

double Sphere::surface() const {
    return 4 * M_PI * r * r;
}

void Sphere::print(std::ostream& os) const {
    os << "Sphere(" << r << ')';
}

//////////////////////////////////////////////////////

Cube::Cube(double side) {
    a = side;
}

double Cube::volume() const {
    return a*a*a;
}

double Cube::surface() const {
    return 6 * a * a;
}

void Cube::print(std::ostream& os) const {
    os << "Cube(" << a << ')';
}

//////////////////////////////////////////////////////

Cylinder::Cylinder(double radius, double height) {
    r = radius; h = height;
}

double Cylinder::volume() const {
    return M_PI * r * r * h;
}

double Cylinder::surface() const {
    return 2 * M_PI * r * (h + r);
}

void Cylinder::print(std::ostream& os) const {
    os << "Cylinder(" << r << ", " << h << ')';
}