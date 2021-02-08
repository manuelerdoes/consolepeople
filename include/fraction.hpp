#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int num, int deno);

        void divide(int divisor);

        void shorten();

        int getNumerator();

        int getDenominator();

        double getOneNumber();
};


#endif