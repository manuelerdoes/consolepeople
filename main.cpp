#include <iostream>
#include <unistd.h>
#include "include/clock.hpp"
#include "include/human.hpp"
#include "include/io.hpp"
#include "include/humanlife.hpp"

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
    std::string runflag = "run";
    std::thread maxeslife = liveLife(max, clock1, runflag);
    std::thread maxessave = saveLife(max, runflag);
    std::thread manuslife = liveLife(manu, clock1, runflag);
    std::thread manussave = saveLife(manu, runflag);
    std::thread idaslife = liveLife(ida, clock1, runflag);
    std::thread idassave = saveLife(ida, runflag);

    // main thread console
    while (true) {
        std::string input;
        std::cout << "what: "; 
        std::cin >> input;
        if (input == "exit") {
            break;
        }
    }
  
    // cleanup
    runflag = "stop";
    maxeslife.join();
    manuslife.join();
    idaslife.join();
    maxessave.join();
    manussave.join();
    idassave.join();
    ioCleanup();

    return 0;
}