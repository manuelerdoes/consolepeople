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

    // load humans from DB
    // if (std::filesystem::exists("cp.db")) {
    //     if(loadHumanFromDB(ida)) { std::cout << "db entries for ida are not compliant" << std::endl; exit(EXIT_FAILURE); }
    //     if(loadHumanFromDB(manu)) { std::cout << "db entries for manu are not compliant" << std::endl; exit(EXIT_FAILURE); }
    //     if(loadHumanFromDB(max)) { std::cout << "db entries for max are not compliant" << std::endl; exit(EXIT_FAILURE); }
    // }


    // save humans in DB
    int insi = insertHumanToDB(ida);
    insi += insertHumanToDB(manu);
    insi += insertHumanToDB(max);
    if (insi > 0) { exit(EXIT_FAILURE); } 

    // start threads for each human
    std::thread maxeslife = liveLife(max, clock1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::thread manuslife = liveLife(manu, clock1);
    std::thread idaslife = liveLife(ida, clock1);

    std::cout << "manuburz: " << manu.getBirthday() << std::endl;

    // main thread waiting and updating DB
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
        int upi = updateHumanToDB(ida);
        upi += updateHumanToDB(manu);
        upi += updateHumanToDB(max);
        // std::string teste99 = getHumanAttributeFromDB(manu, "piss");
        // std::cout << "tescht: " << teste99 << std::endl;
        if (upi > 0) { std::cout << "problem with saving Humans to DB. See error.log" << std::endl; }
    }
  
    // cleanup
    maxeslife.join();
    manuslife.join();
    idaslife.join();
    sqlite3_close(db);
    mainLog.close();

    return 0;
}