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

int main()
{
    //init
    computingInterval = computingInterval / runningSpeed;
    Human ida("Ida", "female", "brown", 21);
    //ida.printAttributes();

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
    }
  



   



    //std::cout << "gender of the person: " << janet.getGender() << std::endl;

    return 0;
}