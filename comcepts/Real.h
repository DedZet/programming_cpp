#pragma once

#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int128_t i128;
typedef int64_t i64;
typedef int32_t i32;


int most_valuable_bit_pos(uint64_t value);
int most_valuable_bit_pos(i128 value);
int least_valuable_bit_pos(uint64_t value);
int least_valuable_bit_pos(i128 value);


class Real {
private:
    i32 m;
    i64 e;

    void normalize();
    static i128 power_of_ten(i128 exponent);

public:
    Real();
    Real(i64 mantissa, i32 exponent);
    Real(double value);
    Real(int value);

    double toDouble() const;
    std::string toString() const;

    Real operator+(Real that) const;
    Real operator+(double that) const;
    Real operator-(Real that) const;
    Real operator-(double that) const;
    Real operator*(Real that) const;
    Real operator/(const Real& that) const;
    Real& operator+=(const Real& that);
    Real& operator-=(const Real& that);
    Real& operator*=(const Real& that);
    Real& operator/=(const Real& that);
    bool operator==(const Real& that) const;
    bool operator<(const Real& that) const;
    bool operator>(const Real& that) const;
    bool operator<=(const Real& that) const;
    bool operator>=(const Real& that) const;
    bool operator!=(const Real& that) const;

    friend std::ostream& operator<<(std::ostream& os, const Real& r);

    Real operator-() const;

    i32 getMantissa() const { return m; }
    i64 getExponent() const { return e; }
};

