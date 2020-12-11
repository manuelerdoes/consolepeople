#ifndef UTILFUNCS_H
#define UTILFUNCS_H

#include "classes/human.h"
#include "classes/fraction.h"

int randomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to); // distribution in range [1, 6]

    return dist6(rng);
}

int tripleLCM(int a, int b, int c) {
    return std::lcm(std::lcm(a,b),c);
}

int quadrupleLCM(int a, int b, int c, int d) {
    return std::lcm(std::lcm(std::lcm(a,b),c),d);
}

int tripleProbabilityRandom(int fullRange, int range1, int range2, int range3, int prob1, int prob2, int prob3) {
    int superRange, rangeNum1, rangeNum2, rangeNum3, randomNum, start, result, forRange;
    Fraction fraction1(prob1, 100); 
    Fraction fraction2(prob2, 100);
    Fraction fraction3(prob3, 100);

    fraction1.divide(range1);
    fraction1.shorten();
    fraction2.divide(range2);
    fraction2.shorten();
    fraction3.divide(range3);
    fraction3.shorten();

    superRange = tripleLCM(fraction1.getDenominator(), fraction2.getDenominator(), fraction3.getDenominator());
    rangeNum1 = (superRange / fraction1.getDenominator() * fraction1.getNumerator());
    rangeNum2 = (superRange / fraction2.getDenominator() * fraction2.getNumerator());
    rangeNum3 = (superRange / fraction3.getDenominator() * fraction3.getNumerator());

    //std::cout << superRange << " " << rangeNum1 << " " << rangeNum2 << " " << rangeNum3 << std::endl;

    randomNum = randomNumber(0,superRange);

    start = 1;
    forRange = rangeNum1;    
    for (int i = 1; i <= range1; i++) {
        if (randomNum >= start && randomNum <= forRange) { result = i; };
        start += rangeNum1;
        forRange += rangeNum1;
    }

    start = 1;
    forRange = rangeNum2;
    for (int i = 1; i <= range2; i++) {
        if (randomNum >= start && randomNum <= forRange) { result = i; };
        start += rangeNum2;
        forRange += rangeNum2;
    }

    start = 1;
    forRange = rangeNum3;
    for (int i = 1; i <= range3; i++) {
        if (randomNum >= start && randomNum <= forRange) { result = i; };
        start += rangeNum3;
        forRange += rangeNum3;
    }

    return result;
}

#endif