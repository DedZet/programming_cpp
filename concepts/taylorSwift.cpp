#include <iostream>
#include <cmath>

const double PI = 3.1415;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double TaylorSin(double x, int rows = 10) {
    
    x = fmod(x, 2 * PI); // остаток от деления
    if (x > PI) x -= 2 * PI;
    if (x < -PI) x += 2 * PI;

    double result = 0.0;
    double firstMem = x;
    int sign = 1;

    for (int n = 1; n <= rows * 2; n += 2) {
        result += sign * firstMem;
        firstMem *= (x * x) / ((n + 1) * (n + 2));
        sign *= -1;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "rus");

    double angle = PI / 4; // 45 градусов

    std::cout << "Угол: " << angle << " радиан\n";
    std::cout << "TaylorSin: " << TaylorSin(angle) << std::endl;
    std::cout << "std::sin: " << std::sin(angle) << std::endl;

    return 0;
}
