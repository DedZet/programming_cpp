#include "Real.h"
#include <iostream>
#include <sstream>
#include <iomanip>
int most_valuable_bit_pos(uint64_t value)
{
    if (value==0)
        return 0;
    int pos;
    uint64_t mask1 = -1;
    for (pos = 63;pos > 0;pos--)
    {
        mask1 = mask1 >> 1;
        if (value > mask1)
            return pos;
        uint64_t mask = 1 << pos;
        if ((value & mask) > 0)
            return pos;
    }
    return pos;
}
int most_valuable_bit_pos(i128 value)
{
    if (value == 0)
        return 0;
    int pos;
    for (pos = 127;pos > 0;pos--)
    {
        i128 mask = 1;
        mask <<= pos;
        if ((value & mask) > 0)
            return pos;
    }
    return pos;
}
int least_valuable_bit_pos(i128 value)
{
    if (value == 0)
        return 0;
    int pos;
    for (pos = 0;pos < 127;pos++)
    {
        i128 mask = 1;
        mask <<= pos;
        if ((value & mask) > 0)
            return pos;
    }
    return pos;
}
int least_valuable_bit_pos(uint64_t value)
{
    if (value == 0)
        return 0;
    int pos;
    for (pos = 0;pos < 63;pos++)
    {
        uint64_t mask = 1 << pos;
        if ((value & mask) > 0)
            return pos;
    }
    return pos;
}

Real::Real() {
    m = 0; e = 0;
}
Real::Real(i64 mantissa, i32 exponent) {
    m = mantissa; e = exponent;
    normalize();
}
Real::Real(double value) {
    if (value == 0.0) {
        m = 0;
        e = 0;
        return;
    }
   // мантисса должна содержать все значимые знаки
    // число с плавающими знаками получается как мантисса * 2 ^ экспонента
    double pw=floor(log(abs(value))); // точность
    double scaled_value = value * std::pow(2, 63-pw);
    m = scaled_value;
    e=pw-63;
    //normalize();
}
Real::Real(int value) {
    m = value;
    e = 0;
    normalize();
}

Real Real::operator+(Real that) const {

    if (e > that.e + 64)
        return *this;
    i32 newE ;
    i128 res ;
    i128 op2 ;

    if (that.e > e )
    {
        if (that.e > e + 64)
            return that;
        newE = that.e;
        res = that.m;
        op2 = m;
        op2 <<= that.e - e;
    }
    else
    {
        newE = e;
        res = m;
        op2 = that.m;
        op2 <<= e - that.e;
    }
    res += op2;
    int mvb = most_valuable_bit_pos(res);
    if (mvb > 63)
        newE += mvb - 63;
    res >>= mvb - 63;
    return Real((i64)res, newE);

}
Real Real::operator+(double that) const {
    return *this + Real(that);
}
Real Real::operator-(Real that) const {

    that.m *= -1;
    return (*this) + that;

}
Real Real::operator-(double that) const {
    return *this - Real(that);
}
Real Real::operator*(Real that) const {
    i128 res = m;
    i128 op2 = that.m;
    res *= op2;
    i32 newE = e + that.e;
    int mvb = most_valuable_bit_pos(res);
    if (mvb > 63)
        newE += mvb - 63;
    res >>= mvb - 63;
    return Real((i64)res, newE);
}
Real Real::operator/(const Real& that) const {
    i128 res = m;
    res << 64;
    i128 op2 = that.m;
    res /= op2;
    i32 newE = e - that.e - 64;
    int mvb = most_valuable_bit_pos(res);
    if (mvb > 63)
        newE += mvb - 63;
    res >>= mvb - 63;
    return Real((i64)res, newE);

}
Real& Real::operator+=(const Real& that) {
    *this = *this + that;
    return *this;
}
Real& Real::operator-=(const Real& that) {
    *this = *this - that;
    return *this;
}
Real& Real::operator*=(const Real& that) {
    *this = *this * that;
    return *this;
}
Real& Real::operator/=(const Real& that) {
    *this = *this / that;
    return *this;
}
bool Real::operator==(const Real& that) const {
    if (m == 0 && that.m == 0) return true;
    i128 common_exp = std::max(e, that.e);
    i128 this_mantissa = m * power_of_ten(common_exp - e);
    i128 that_mantissa = that.m * power_of_ten(common_exp - that.e);
    return this_mantissa == that_mantissa;
}
bool Real::operator<(const Real& that) const {
    i128 common_exp = std::max(e, that.e);
    i128 this_mantissa = m * power_of_ten(common_exp - e);
    i128 that_mantissa = that.m * power_of_ten(common_exp - that.e);
    return this_mantissa < that_mantissa;
}
bool Real::operator>(const Real& that) const {
    return that < *this;
}
bool Real::operator<=(const Real& that) const {
    return !(*this > that);
}
bool Real::operator>=(const Real& that) const {
    return !(*this < that);
}
bool Real::operator!=(const Real& that) const {
    return !(*this == that);
}
Real Real::operator-() const {
    return Real(-m, e);
}

double Real::toDouble() const {
    if (m == 0) return 0.0;
    return static_cast<double>(m) * std::pow(10.0, -static_cast<double>(e));
}
std::string Real::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(20) << toDouble();
    return ss.str();
}

i128 Real::power_of_ten(i128 n) {
    if (n == 0) return 1;
    if (n < 0) {
        return 1;
    }

    i128 result = 1;
    for (i128 i = 0; i < n; ++i) {
        result *= 10;
        if (result < 0) {
            std::cout << "Overflow err" << std::endl;
            break;
        }
    }
    return result;
}

void Real::normalize() {
    if (m == 0) {
        e = 0;
        return;
    }

    while (m % 10 == 0 && m != 0 && e > 0) {
        m /= 10;
        e--;
    }
}
