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


    std::thread maxeslife = liveLife(max, clock1);
    std::thread manuslife = liveLife(manu, clock1);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        //std::cout << "shit: " << max.getShit() << std::endl;
    }
  

    maxeslife.join();
    manuslife.join();

    return 0;
}