#define _USE_MATH_DEFINES
#include "Real.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace boost::multiprecision;

const double PI = M_PI;

namespace Taylor {
    constexpr double PI = M_PI;
    constexpr double TWO_PI = 2.0 * PI;
    constexpr double HALF_PI = PI / 2.0;

    constexpr double factorial(int n) {
        double result = 1.0;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    double reduce_to_half_pi(double x, int& quadrant) {
        x = std::fmod(x, TWO_PI);
        if (x < 0) x += TWO_PI;

        if (x <= HALF_PI) {
            quadrant = 1;
            return x;
        }
        else if (x <= PI) {
            quadrant = 2;
            return PI - x;
        }
        else if (x <= 3.0 * HALF_PI) {
            quadrant = 3;
            return x - PI;
        }
        else {
            quadrant = 4;
            return TWO_PI - x;
        }
    }

    double taylor_sin_core(double x) {
        const int n = 16;
        double sum = 0.0;
        double term = x;
        double x2 = x * x;

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                term = -term * x2 / ((2.0 * i) * (2.0 * i + 1.0));
            }
            sum += term;
        }
        return sum;
    }

    double my_sin(double x) {
        if (std::isnan(x) || std::isinf(x)) {
            return std::numeric_limits<double>::quiet_NaN();
        }

        int quadrant;
        double reduced_x = reduce_to_half_pi(x, quadrant);
        double result = taylor_sin_core(reduced_x);

        if (quadrant == 3 || quadrant == 4) {
            result = -result;
        }

        return result;
    }
}

void showSize() {
    std::cout << "Размер int: " << sizeof(int) << "\n";
    std::cout << "Размер long: " << sizeof(long) << "\n";
    std::cout << "Размер long long: " << sizeof(long long) << "\n";
    std::cout << "Размер double: " << sizeof(double) << "\n";
    std::cout << "Размер int64: " << sizeof(int64_t) << "\n";
    std::cout << "Размер int128: " << sizeof(int128_t) << "\n\n";
}

void test128() {
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
}

Real realAbs(Real r) {
    if (r < 0) return r * -1;
    else return r;
}

int test(double x) {
    double xd = x;
 
    Real my_sin_val = Taylor::my_sin(xd);
    Real std_sin_val = std::sin(xd);

    std::cout << "Угол: " << xd << "\n";
    std::cout << "TaylorSin: " << std::setprecision(16) << my_sin_val << "\n";
    std::cout << "StdSin:    " << std::setprecision(16) << std_sin_val << "\n";
    std::cout << "Разница: " << std::setprecision(16) << my_sin_val - std_sin_val << "\n\n";
    
    if (realAbs(my_sin_val - std_sin_val) > 1e-16) {
        return 1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");
    int cnt = 0;

    for (int i = 0; i < 100; i++) {
        double x = 1.0 + 4.0 / 100.0 * i;
        cnt += test(x);
    }

    std::cout << "Ошибка в " << cnt << " случаях из 100" << std::endl;

    return 0;
}
