#include <iostream>
#include <string>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <future>
#include <vector>
#include "clock.h"
#include "classes/human.h"
#include "humanactions.h"
#include "humanlife.h"
//#include "classes/fraction.h"
//#include "utilfuncs.h"

int runningSpeed = 10;
int computingInterval = 1000;

int main()
{
    //init
    computingInterval = computingInterval / runningSpeed;

    Clock clock1;

    Human ida("Ida", "female", "brown", clock1);
    Human manu("Manu", "male", "brown", clock1);
    Human max("Max", "male", "blonde", clock1);

    int maxeslife = liveLife(max, clock1);
    std::this_thread::sleep_for(std::chrono::milliseconds(333));
    //int manuslife = liveLife(manu, clock1);

    //uint64_t testo = clock1.timeSinceEpochMS();
    //std::cout << "testo: " << testo << std::endl;


    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        //std::cout << "shit: " << max.getShit() << std::endl;
    }
  



   



    //std::cout << "gender of the person: " << janet.getGender() << std::endl;

    return 0;
}