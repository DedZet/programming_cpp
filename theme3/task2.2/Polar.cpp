#include "Polar.h"
#include "Decart.h"

#include <iostream>
#include <cmath>

Polar::Polar() {
    r = 0;
    fi = 0;
}

Polar::Polar(double r_, double fi_) {
    r = r_;
    fi = fi_;
}

Polar::Polar(Decart& p) {
    r = sqrt(p.x * p.x + p.y * p.y);
    if (r > 0) fi = atan2(p.y, p.x);
    else fi = 0;
}

Polar::operator Decart() {
    return Decart(r * cos(fi), r * sin(fi));
}

std::ostream& operator << (std::ostream& os, const Polar& p) {
    return os << '[' << p.r << ';' << p.fi << ']';
}