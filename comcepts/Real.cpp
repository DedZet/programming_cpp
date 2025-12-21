#define _USE_MATH_DEFINES
#include "Real.h"
#include <iostream>
#include <sstream>
#include <iomanip>

std::ostream& operator << (std::ostream& os, const Real& r) {
    return os << r.toDouble();
}

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

    int exp_double;
    double mantissa = std::frexp(value, &exp_double);

    const int mantissa_bits = 31;

    i64 scaled = static_cast<i64>(std::ldexp(mantissa, mantissa_bits));

    int shift = 0;
    while ((scaled & 1) == 0 && scaled != 0) {
        scaled >>= 1;
        shift++;
    }

    m = static_cast<i32>(scaled);
    e = exp_double - mantissa_bits + shift;
}
Real::Real(int value) {
    if (value == 0) {
        m = 0;
        e = 0;
        return;
    }

    bool negative = value < 0;
    i64 abs_value = std::llabs(static_cast<i64>(value));

    int shift = 0;
    while ((abs_value & 1) == 0 && abs_value != 0) {
        abs_value >>= 1;
        shift++;
    }

    const int max_bits = 31;
    int bits_needed = 0;
    i64 temp = abs_value;
    while (temp > 0) {
        temp >>= 1;
        bits_needed++;
    }

    if (bits_needed > max_bits) {
        int extra_shift = bits_needed - max_bits;
        abs_value >>= extra_shift;
        shift += extra_shift;
    }

    m = static_cast<i32>(negative ? -abs_value : abs_value);
    e = shift;
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
    {
        newE += mvb - 63;
        res >>= mvb - 63;
    }
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
    {
        newE += mvb - 63;
        res >>= mvb - 63;
    }
    return Real((i64)res, newE);
}
Real Real::operator/(const Real& that) const {
    i128 res = m;
    res << 64;
    i128 op2 = that.m;
    res /= op2;
    i32 newE = e - that.e - 64;
    int mvb = most_valuable_bit_pos(res);
    if (mvb > 63) {
        newE += mvb - 63;
        res >>= mvb - 63;
    }
       
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
    return std::ldexp(static_cast<double>(m), static_cast<int>(e));
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

    int lvb = least_valuable_bit_pos(m);
    if (lvb > 0)
    {
        e -= lvb;
        m >>= lvb;
    }
}