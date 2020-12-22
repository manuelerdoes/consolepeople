#include <iostream>
#include <string>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <unistd.h>
#include "clock.h"
#include "classes/human.h"
#include "humanactions.h"
#include "humanlife.h"
//#include "classes/fraction.h"
//#include "utilfuncs.h"

int runningSpeed = 1;
int computingInterval = 1000;

int main()
{
    //init
    computingInterval = computingInterval / runningSpeed;
    Human ida("Ida", "female", "brown", 0);
    Human manu("Manu", "male", "brown", 0);
    Human max("Max", "male", "blonde", 0);


    //int maxeslife = liveLife(max);

    Clock clock1;




    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
        std::cout << "time: " << clock1.elapsed() << std::endl;
    }
  



   



    //std::cout << "gender of the person: " << janet.getGender() << std::endl;

    return 0;
}