#include <iostream>
#include <string>
#include <random>
#include "utilfuncs.h"
#include "classes/human.h"

int main()
{

    Human janet("Ida", "female", "brown", 21);

    janet.printAttributes();

    //std::cout << "gender of the person: " << janet.getGender() << std::endl;

    return 0;
}