#include <iostream>
#include <string>
#include <random>
#include "utilfuncs.h"
#include "classes/human.h"

int main()
{

    Human janet("Ida", "female", "brown", 21);

    janet.printAttributes();

    return 0;
}