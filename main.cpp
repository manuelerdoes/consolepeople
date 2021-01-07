#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <future>
#include <vector>
#include <mutex>
#include <sqlite3.h>
#include "clock.h"
#include "classes/human.h"
#include "io.h"
#include "humanactions.h"
#include "humanlife.h"
//#include "classes/fraction.h"
//#include "utilfuncs.h"

int runningSpeed = 10;
int computingInterval = 1000;

Clock clock1;

std::mutex Mutex1;
std::mutex Mutex2;

int main()
{
    //init
    computingInterval = computingInterval / runningSpeed;

    Human ida("Ida", "female", "brown", clock1);
    Human manu("Manu", "male", "brown", clock1);
    Human max("Max", "male", "blonde", clock1);


    std::thread maxeslife = liveLife(max, clock1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::thread manuslife = liveLife(manu, clock1);

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
  

    maxeslife.join();
    manuslife.join();
    mainLog.close();

    return 0;
}