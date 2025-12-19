/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fifth task
*/
#include "Rational.h"
#include <stdexcept>
#include <numeric>

Rtl Rtl::operator+(const Rtl& other) const
{
    return Rtl(other._denominator * _numerator + other._numerator * _denominator, other._denominator * _denominator);
}

Rtl Rtl::operator-(const Rtl& other) const
{
    return Rtl(other._denominator * _numerator - other._numerator * _denominator, other._denominator * _denominator);
}

Rtl Rtl::operator*(const Rtl& other) const
{
    return Rtl(other._numerator * _numerator, other._denominator * _denominator);
}

Rtl Rtl::operator/(const Rtl& other) const
{
    return *this * Rtl(other._denominator, other._numerator);
}

bool Rtl::operator!=(const Rtl& other) const
{
    return _numerator != other._numerator || _denominator != other._denominator;
}

bool Rtl::operator==(const Rtl& other) const
{
    return _numerator == other._numerator && _denominator == other._denominator;
}

std::ostream& operator<<(std::ostream& os, const Rtl& rtl_number)
{
    os << rtl_number._numerator << "/" << rtl_number._denominator;
    return os;
}

int Rtl::getNumerator() const
{
    return _numerator;
}
int Rtl::getDenominator() const
{
    return _denominator;
}

Rtl::Rtl(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("denominator cant be zero!");
    }
    _numerator = numerator / std::gcd(std::abs(numerator), std::abs(denominator));
    _denominator = denominator / std::gcd(std::abs(numerator), std::abs(denominator));
    if (_denominator < 0)
    {
        _numerator *= -1;
        _denominator *= -1;
    }
}