#include <iostream>
#include <fstream>
#include <string>
//#include <filesystem>
#include <random>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <future>
#include <vector>
#include <mutex>
#include <ctime>
#include <sqlite3.h>
#include "clock.h"
#include "classes/human.h"
#include "io.h"
#include "humanactions.h"
#include "humanlife.h"
//#include "bgsaving.h"
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
    int initdb = initDB();
    if (initdb == 1) { exit(EXIT_FAILURE); }

    computingInterval = computingInterval / runningSpeed;

    // create human objects
    Human ida("Ida", "female", "brown", clock1);
    Human manu("Manu", "male", "brown", clock1);
    Human max("Max", "male", "blonde", clock1);

    // load humans from DB or create them
    if (getHumanAttributeFromDB(ida, "name") == ida.getName()) {
        std::cout << "humans found in DB. loading them." << std::endl;
        if(loadHumanFromDB(ida)) { std::cout << "db entries for ida were not compliant" << std::endl; }
        if(loadHumanFromDB(manu)) { std::cout << "db entries for manu were not compliant" << std::endl; }
        if(loadHumanFromDB(max)) { std::cout << "db entries for max were not compliant" << std::endl; }
    } else {
        std::cout << "no DB entries found. creating new ones." << std::endl;
        int insi = insertHumanToDB(ida);
        insi += insertHumanToDB(manu);
        insi += insertHumanToDB(max);
        if (insi > 0) { exit(EXIT_FAILURE); } 
    }

    // save humans in DB
    int upi = updateHumanToDB(ida);
    upi += updateHumanToDB(manu);
    upi += updateHumanToDB(max);
    if (upi > 0) { std::cout << "problem with saving Humans to DB. See error.log" << std::endl; }

    // start threads for each human
    std::thread maxeslife = liveLife(max, clock1);
    std::thread maxessave = saveLife(max);
    std::thread manuslife = liveLife(manu, clock1);
    std::thread manussave = saveLife(manu);
    std::thread idaslife = liveLife(ida, clock1);
    std::thread idassave = saveLife(ida);

    // main thread waiting and updating DB
    while (true) {
        std::string input;
        std::cout << "what: "; 
        std::cin >> input;
        //std::cout << "wort 1: " << input[0] << " wort 2: " << input[1] << std::endl;


        //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        // int upi = updateHumanToDB(ida);
        // upi += updateHumanToDB(manu);
        // upi += updateHumanToDB(max);
        // if (upi > 0) { std::cout << "problem with saving Humans to DB. See error.log" << std::endl; }
    }
  
    // cleanup
    maxeslife.join();
    manuslife.join();
    idaslife.join();
    maxessave.join();
    manussave.join();
    idassave.join();
    sqlite3_close(db);
    mainLog.close();

    return 0;
}