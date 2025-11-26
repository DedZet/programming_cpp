#define _USE_MATH_DEFINES
#include "Real.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace boost::multiprecision;

const double PI = M_PI;

class Taylor {
private:
    static Real factorial(int n) {
        Real result(1, 0);
        for (int i = 2; i <= n; ++i) {
            result = result * Real(i);
        }
        return result;
    }
    static Real power(const Real& x, int n) {
        if (n == 0) return Real(1, 0);

        Real result(1, 0);
        Real base = x;
        int exponent = n;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exponent /= 2;
        }
        return result;
    }

public:
    static Real sin(const Real& x, int terms = 50) {
        Real result(0, 0);
        Real x_squared = x * x;
        Real term = x;
        int sign = 1;

        for (int n = 0; n < terms; ++n) {
            int k = 2 * n + 1;

            Real current_term = term;
            if (sign == -1) {
                current_term = -current_term;
            }

            result = result + current_term;

            term = term * x_squared;
            term = term / Real((2 * n + 2) * (2 * n + 3));

            sign = -sign;
        }

        return result;
    }
};

// перевод в радианы диапозона (-pi, pi)
Real normalize_angle(const Real& x) {
    Real pi = Real(M_PI);
    //Real pi = Real(314159265358979323846264338327950288419716939937510LL, 50);
    Real two_pi = pi * Real(2);

    Real normalized = x;
    while (normalized < Real(0)) {
        normalized = normalized + two_pi;
    }
    while (normalized >= two_pi) {
        normalized = normalized - two_pi;
    }

    if (normalized > pi) {
        normalized = normalized - two_pi;
    }

    return normalized;
}

void showSize() {
    std::cout << "Размер int: " << sizeof(int) << "\n";
    std::cout << "Размер long: " << sizeof(long) << "\n";
    std::cout << "Размер long long: " << sizeof(long long) << "\n";
    std::cout << "Размер double: " << sizeof(double) << "\n";
    std::cout << "Размер int64: " << sizeof(int64_t) << "\n";
    std::cout << "Размер int128: " << sizeof(int128_t) << "\n\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    i128 A, B, C;
    A = 1;
    A <<= 64;
    C = 1;
    C <<= 31;
    B = A;
    B += C;
    C <<= 1;
    A += C;

    C = A + B;
    std::cout << A << " + " << B << " = " << C << "\r\n";
    int mvb = most_valuable_bit_pos(C);
    int lvb = least_valuable_bit_pos(C);
    std::cout << mvb << " mvb " << lvb << " lvb " << "\r\n";

    Real x = 180;
    Real nx = normalize_angle(x);
    Real result = Taylor::sin(nx, 60);

    std::cout << "Угол: " << x.toDouble() << " градусов\n";
    std::cout << "TaylorSin: " << result.toDouble() << std::endl;
    std::cout << "StdSin: " << std::sin(x.toDouble()) << std::endl;
    
    return 0;
}
