#include "Figure3.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#pragma once

class Sphere : public Figure3 {
private:
    double r;

public:
    Sphere(double radius);

    double volume() const override;
    double surface() const override;
    void print(std::ostream& os) const override;
};

class Cube : public Figure3 {
private:
    double a;

public:
    Cube(double side);

    double volume() const override;
    double surface() const override;
    void print(std::ostream& os) const override;
};

class Cylinder : public Figure3 {
private:
    double r, h;

public:
    Cylinder(double radius, double height);

    double volume() const override;
    double surface() const override;
    void print(std::ostream& os) const override;
};