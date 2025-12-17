#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rtl
{
public:
    Rtl operator+(const Rtl& other) const;
    Rtl operator-(const Rtl& other) const;
    Rtl operator*(const Rtl& other) const;
    Rtl operator/(const Rtl& other) const;
    bool operator!=(const Rtl& other) const;
    bool operator==(const Rtl& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rtl& r);

    int getNumerator() const;
    int getDenominator() const;

    Rtl(int numerator = 0, int denominator = 1);

private:
    int _numerator;
    int _denominator;
};

#endif