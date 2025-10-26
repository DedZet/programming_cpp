#include <iostream>
#include <string>

class real {
private:
    int m;
    int e;

    void normalize() {
        if (m == 0) {
            e = 0;
            return;
        }

        while (m % 10 == 0 && e > 0) {
            m /= 10;
            e--;
        }
    }

public:

    real() {
        m = 0; e = 0;
    }
    real(int mantissa, int exponent) {
        m = mantissa; e = exponent;
        normalize();
    }

    real(double value) {
        if (value == 0.0) {
            m = 0;
            e = 0;
            return;
        }

        e = 6;
        m = static_cast<int>(std::round(value * std::pow(10, e)));
        normalize();
    }

    double toDouble() const {
        return static_cast<double>(m) * std::pow(10, -e);
    }

    real operator+(const real& that) const {
        int common_exp = std::max(e, that.e);
        int this_mantissa = m * static_cast<int>(std::pow(10, common_exp - e));
        int that_mantissa = that.m * static_cast<int>(std::pow(10, common_exp - that.e));

        return real(this_mantissa + that_mantissa, common_exp);
    }

    real operator+(double that) const {
        return *this + real(that);
    }

    real operator*(const real& that) const {
        return real(m * that.m, e + that.e);
    }

    real operator/(const real& that) const {
        if (that.m == 0) {
            std::cout << "Division by zero";
        }

        int precision = 10;
        int new_m = m * static_cast<int>(std::pow(10, that.e + precision));
        int new_e = e + precision;

        return real(new_m / that.m, new_e);
    }

    real& operator+=(const real& that) {
        *this = *this + that;
        return *this;
    }

    real& operator*=(const real& that) {
        *this = *this * that;
        return *this;
    }

    real& operator/=(const real& that) {
        *this = *this / that;
        return *this;
    }

    bool operator==(const real& that) const {
        return toDouble() == that.toDouble();
    }

    std::string toString() const {
        if (e == 0) {
            return std::to_string(m);
        }

        std::string str = std::to_string(std::abs(m));
        if (str.length() <= e) {
            str = std::string(e - str.length() + 1, '0') + str;
        }

        int point_pos = str.length() - e;
        str.insert(point_pos, ".");

        while (str.back() == '0') {
            str.pop_back();
        }

        if (str.back() == '.') {
            str.pop_back();
        }

        if (m < 0) {
            str = "-" + str;
        }

        return str;
    }
};
