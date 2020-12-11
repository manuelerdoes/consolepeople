#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int num, int deno) {
            numerator = num;
            denominator = deno;
        }

        void divide(int divisor) {
            denominator = denominator * divisor;
        }

        void shorten() {
            int shortgcd = std::gcd(numerator, denominator);
            numerator = numerator / shortgcd;
            denominator = denominator / shortgcd;
        }

        int getNumerator() {
            return numerator;
        }

        int getDenominator() {
            return denominator;
        }

        double getOneNumber() {
            double division; 
            division = ((numerator / denominator) * 1.0);
            return division;
        }
};


#endif