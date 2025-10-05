#include <iostream>

class Fract {
    public:
    int numer;  // Числитель
    int denom;  // Знаменатель

    Fract() {
        numer = 1;
        denom = 1;
    }

    Fract(int n, int d) {
        numer = n;
        denom = d;
    }
    
    void info() {
        std::cout << numer << "\\" << denom << std::endl;
    }

    void normalize() {
        if (denom == 0) std::cout << "Знаменатель не может быть равен 0\n";
        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }

        int n = std::abs(numer);
        int d = denom;

        while (d != 0) {
            int temp = d;
            d = n % d;
            n = temp;
        }
        int nod = n;

        numer /= nod;
        denom /= nod;
    }

    void add(Fract f) {
        numer = numer * f.denom + f.numer * denom;
        denom = denom * f.denom;
        normalize();
    }

    void sub(Fract f) {
        numer = numer * f.denom - f.numer * denom;
        denom = denom * f.denom;
        normalize();
    }

    short compare(Fract f) {
        normalize();
        f.normalize();
        
        if (numer == f.numer && denom == f.denom) return 0;
        else if (numer * f.denom < f.numer * denom) return -1;
        else if (numer * f.denom > f.numer * denom) return 1;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    
    Fract a(4, 8);
    Fract b(2, 4);

    a.normalize();
    a.info();

    b.normalize();
    b.info();

    a.add(b);
    a.info();

    Fract c;

    if (c.compare(a) == 0) {
        std::cout << "Дроби равны";
    }
}
