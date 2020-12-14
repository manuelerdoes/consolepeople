#include <iostream>
#include <string>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include "classes/human.h"
//#include "classes/fraction.h"
//#include "utilfuncs.h"

unsigned int runningSpeed = 1;
unsigned int computingInterval = 1000;
computingInterval = computingInterval / runningSpeed;

int main()
{
    //init
    Human ida("Ida", "female", "brown", 21);
    //ida.printAttributes();

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
    }
  



   



    return 0;
}