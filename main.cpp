#include <iostream>
#include <string>
#include <random>
#include "utilfuncs.h"
#include "classes/human.h"

int main()
{

    Human janet("Janet", "female", "brown", 21);

    janet.printAttributes();

    return 0;
}