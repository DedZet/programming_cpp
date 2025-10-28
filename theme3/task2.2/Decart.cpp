#include "Decart.h"
#include "Polar.h"

#include <iostream>
#include <cmath>

Decart::Decart() {
    x = 0;
    y = 0;
}

Decart::Decart(double x_, double y_) {
    x = x_;
    y = y_;
}

Decart::Decart(Polar& p) {
    x = p.r * cos(p.fi);
    y = p.r * sin(p.fi);
}

Decart::operator Polar() {
    double r = sqrt(x * x + y * y), fi;
    if (r > 0) fi = atan2(y, x);
    else fi = 0;
    return Polar(r, fi);
}

std::ostream& operator << (std::ostream& os, const Decart& p) {
    return os << '[' << p.x << ';' << p.y << ']';
}
