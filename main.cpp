#include <iostream>
#include <string>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>
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
    ida.printAttributes();
    pid_t pid = fork();

    if (pid == 0) {
        std::cout << "starting life of " << ida.getName() << std::endl;
        int counter = 0;
        while (true) {
            std::cout << "living " << counter << " seconds" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
            counter++;
            
        }

    }



    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
    }
  



   



    //std::cout << "gender of the person: " << janet.getGender() << std::endl;

    return 0;
}