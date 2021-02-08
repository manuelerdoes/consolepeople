#include <numeric>
#include "../include/fraction.hpp"


Fraction::Fraction(int num, int deno) {
    numerator = num;
    denominator = deno;
}

void Fraction::divide(int divisor) {
    denominator = denominator * divisor;
}

void Fraction::shorten() {
    int shortgcd = std::gcd(numerator, denominator);
    numerator = numerator / shortgcd;
    denominator = denominator / shortgcd;
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

double Fraction::getOneNumber() {
    double division; 
    division = ((numerator / denominator) * 1.0);
    return division;
}

