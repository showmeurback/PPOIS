#include "SignedFraction.h"

int SignedFraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void SignedFraction::reduce() {
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

SignedFraction::SignedFraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

int SignedFraction::getNumerator() const { return numerator; }
int SignedFraction::getDenominator() const { return denominator; }
int SignedFraction::getWholePart() const { return numerator / denominator; }

SignedFraction SignedFraction::operator+(const SignedFraction& other) const {
    return SignedFraction(numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator);
}

SignedFraction& SignedFraction::operator+=(const SignedFraction& other) {
    *this = *this + other;
    return *this;
}

SignedFraction SignedFraction::operator+(int integer) const {
    return *this + SignedFraction(integer * denominator, denominator);
}

SignedFraction& SignedFraction::operator+=(int integer) {
    *this = *this + integer;
    return *this;
}

SignedFraction SignedFraction::operator-(const SignedFraction& other) const {
    return SignedFraction(numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator);
}

SignedFraction& SignedFraction::operator-=(const SignedFraction& other) {
    *this = *this - other;
    return *this;
}

SignedFraction SignedFraction::operator-(int integer) const {
    return *this - SignedFraction(integer * denominator, denominator);
}

SignedFraction& SignedFraction::operator-=(int integer) {
    *this = *this - integer;
    return *this;
}

SignedFraction SignedFraction::operator*(const SignedFraction& other) const {
    return SignedFraction(numerator * other.numerator, denominator * other.denominator);
}

SignedFraction& SignedFraction::operator*=(const SignedFraction& other) {
    *this = *this * other;
    return *this;
}

SignedFraction SignedFraction::operator*(int integer) const {
    return SignedFraction(numerator * integer, denominator);
}

SignedFraction& SignedFraction::operator*=(int integer) {
    *this = *this * integer;
    return *this;
}

SignedFraction SignedFraction::operator/(const SignedFraction& other) const {
    return SignedFraction(numerator * other.denominator, denominator * other.numerator);
}

SignedFraction& SignedFraction::operator/=(const SignedFraction& other) {
    *this = *this / other;
    return *this;
}

SignedFraction SignedFraction::operator/(int integer) const {
    return SignedFraction(numerator, denominator * integer);
}

SignedFraction& SignedFraction::operator/=(int integer) {
    *this = *this / integer;
    return *this;
}

SignedFraction& SignedFraction::operator++() {
    numerator += denominator;
    return *this;
}

SignedFraction SignedFraction::operator++(int) {
    SignedFraction temp = *this;
    ++(*this);
    return temp;
}

SignedFraction& SignedFraction::operator--() {
    numerator -= denominator;
    return *this;
}

SignedFraction SignedFraction::operator--(int) {
    SignedFraction temp = *this;
    --(*this);
    return temp;
}

bool SignedFraction::operator>(const SignedFraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool SignedFraction::operator>=(const SignedFraction& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}

bool SignedFraction::operator<(const SignedFraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool SignedFraction::operator<=(const SignedFraction& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

SignedFraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}
