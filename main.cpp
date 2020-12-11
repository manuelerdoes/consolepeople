#include <iostream>
#include <string>
#include <random>
#include <numeric>
#include <iomanip>
#include "classes/human.h"
#include "classes/fraction.h"
#include "utilfuncs.h"


int main()
{

    Human janet("Ida", "female", "brown", 21);

    //janet.printAttributes();

    int huhu = tripleProbabilityRandom(10, 3, 4, 3, 70, 20, 10);
    std::cout << huhu << std::endl;



    return 0;
}