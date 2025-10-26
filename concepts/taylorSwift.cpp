#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

//typedef double real;

class real
{
public:
    real() { v = 0.; };
    real(real& that) { this->v = that.v; }
    real(double that) { v = that; }
    double ToDouble() { return v; }
    bool operator ==(real& that) { return v==that.v; }
    real operator +(real& that) { real res; res.v = v + that.v; return res; }
    real operator +(double  that) { real res; res.v = v + that; return res;}
    real operator *(real& that) { real res; res.v = v * that.v; return res;}
    real operator /(real& that) { real res; res.v = v / that.v; return res;}
    real& operator +=(real& that) { v = v + that.v; return *this; }
    real& operator *=(real& that) { v = v * that.v; return *this; }
    real& operator /=(real& that) { v = v / that.v; return *this; }

public:
    double v;
};
const double PI = M_PI;

long long ___factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double TaylorSin(real ix) {
    real x = ix;
    real result = 0;
    real term = x;
    real last = 0;

    //double* arr = (double*)malloc(rows * sizeof(double*));

    for (int n = 1; n <= 10000; n += 2) {
        last = result;
        result += term;

        if (last == result) {
            break;
        }

        term *= (x * x) / real((n + 1) * (n + 2))*(-1);
        
    }

    return result.ToDouble();
}

int main() {
    setlocale(LC_ALL, "rus");

    double angle = 6; // 45 градусов

    std::cout << "Угол: " << angle << " радиан\n";

    double tsin= TaylorSin(angle);
    double msin = std::sin(angle);

    printf("\ntsin: %g\nmsin: %g\ndiff: %g\r\n", tsin,msin,tsin-msin);


    return 0;
}
