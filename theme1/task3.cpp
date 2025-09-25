#include <iostream>
#include <math.h>
#include <clocale>
#include <string.h>

struct Point2 {
    double x;
    double y;
};

void printPoint(Point2 p) {
    std::cout << "(" << p.x << " ; " << p.y << ")" << std::endl;
}

enum eTrType {
    РАВНОСТОРОННИЙ,
    РАВНОБЕДРЕННЫЙ,
    ОБЩЕГО_ВИДА
};

double getTrPerimeter(Point2 a, Point2 b, Point2 c) {
    double ab = sqrt(abs(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y))));
    double bc = sqrt(abs(((c.x - b.x) * (c.x - b.x)) + ((c.y - b.y) * (c.y - b.y))));
    double ac = sqrt(abs(((c.x - a.x) * (c.x - a.x)) + ((c.y - a.y) * (c.y - a.y))));

    return ab + bc + ac;
}

eTrType getTrType(Point2 a, Point2 b, Point2 c) {
    double ab = sqrt(abs(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y))));
    double bc = sqrt(abs(((c.x - b.x) * (c.x - b.x)) + ((c.y - b.y) * (c.y - b.y))));
    double ac = sqrt(abs(((c.x - a.x) * (c.x - a.x)) + ((c.y - a.y) * (c.y - a.y))));
    
    if ((ab == bc) && (bc == ac) && (ab == ac)) return РАВНОСТОРОННИЙ;
    else if (ab == bc || bc == ac || ab == ac) return РАВНОБЕДРЕННЫЙ;
    else return ОБЩЕГО_ВИДА;
}

int main() {
    setlocale(LC_ALL, "rus");

    Point2 a = { 1,2 };
    Point2 b = { 2,3 };
    Point2 c = { 4,6 };

    printPoint(a);
    printPoint(b);
    printPoint(c);

    std::cout << "\nP = " << getTrPerimeter(a, b, c) << std::endl;

    switch (getTrType(a, b, c)) {
        case 0: std::cout << "Треугольник равносторонний\n"; break;
        case 1: std::cout << "Треугольник равнобедренный\n"; break;
        case 2: std::cout << "Треугольник общего вида\n"; break;
    }
}
