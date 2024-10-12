#ifndef SIGNEDFRACTION_H
#define SIGNEDFRACTION_H

#include <iostream>
#include <stdexcept>

class SignedFraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);
    void reduce();

public:
    SignedFraction(int num = 0, int denom = 1);

    int getNumerator() const;
    int getDenominator() const;
    int getWholePart() const;

    SignedFraction operator+(const SignedFraction& other) const;
    SignedFraction& operator+=(const SignedFraction& other);
    SignedFraction operator+(int integer) const;
    SignedFraction& operator+=(int integer);
    SignedFraction operator-(const SignedFraction& other) const;
    SignedFraction& operator-=(const SignedFraction& other);
    SignedFraction operator-(int integer) const;
    SignedFraction& operator-=(int integer);
    SignedFraction operator*(const SignedFraction& other) const;
    SignedFraction& operator*=(const SignedFraction& other);
    SignedFraction operator*(int integer) const;
    SignedFraction& operator*=(int integer);
    SignedFraction operator/(const SignedFraction& other) const;
    SignedFraction& operator/=(const SignedFraction& other);
    SignedFraction operator/(int integer) const;
    SignedFraction& operator/=(int integer);
    SignedFraction& operator++();
    SignedFraction operator++(int);
    SignedFraction& operator--();
    SignedFraction operator--(int);
    bool operator>(const SignedFraction& other) const;
    bool operator>=(const SignedFraction& other) const;
    bool operator<(const SignedFraction& other) const;
    bool operator<=(const SignedFraction& other) const;
    operator double() const;
};

#endif // SIGNEDFRACTION_H
