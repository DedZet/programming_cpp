#define _USE_MATH_DEFINES
#include "real.cpp"

const double PI = M_PI;

long long ___factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

real TaylorSin(real ix) {
    real x = ix;
    real result = 0;
    real term(x);
    real last(0);

    for (int n = 1; n <= 10000; n += 2) {
        last = result;
        result += term;

        if (last == result) {
            break;
        }

        term *= (x * x) / real((n + 1) * (n + 2)) * (-1);

    }

    return result.toDouble();
}


int main() { setlocale(LC_ALL, "rus");
     
    double angle = 6; // 45 градусов
    
    std::cout << "Угол: " << angle << " радиан\n";
    
    real tsin = TaylorSin(angle);
    double msin = std::sin(angle);
    
    printf("\ntsin: %g\nmsin: %g\ndiff: %g\r\n", tsin, msin, tsin.toDouble() - msin);

    return 0;
}
