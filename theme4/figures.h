#include "Figure2.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#pragma once

class Triangle : public Figure2 {
private:
    double a, b, c;

public:
    Triangle(double s1, double s2, double s3);

    double square() const override;
    double perim() const override;
    void print(std::ostream& os) const override;
};

class Circle : public Figure2 {
private:
    double r;

public:
    Circle(double r);

    double square() const override;
    double perim() const override;
    void print(std::ostream& os) const override;
};

class Rectangle : public Figure2 {
private:
    double w, h;

public:
    Rectangle(double width, double height);

    double square() const override;
    double perim() const override;
    void print(std::ostream& os) const override;
};