#include <mutex>
#include "../include/io.hpp"
#include "../include/humanlife.hpp"

extern int computingInterval;
extern std::mutex Mutex1;
extern std::mutex Mutex2;

void lifeThread(Human h, Human* hptr, Clock c, std::string &rf) {
    coutToConsole("starting life", h);

    unsigned long counter = 0;
    while (rf != "stop") {
        // print age

        uint64_t age = c.elapsedS(h.getBirthday());
        if (age >= 600 && age < 3600 && counter % 600 == 0) { 
            int mins = age / 60;
            coutToConsole(std::to_string(mins) + " minute(s) old", h);
        }
        if (age >= 3600 && age < 86400 && counter % 3600 == 0) { 
            int hours = age / 3600;
            coutToConsole(std::to_string(hours) + " hour(s) old", h);
        }
        if (age >= 86400 && age < 31536000 && counter % 86400 == 0) { 
            int days = age / 86400;
            coutToConsole(std::to_string(days) + " day(s) old", h);
        }
        if (age >= 31536000 && counter % 31536000 == 0) { 
            int years = age / 31536000;
            coutToConsole(std::to_string(years) + " year(s) old", h);
        }

        if (h.getPiss() == 100) { h.doPiss(); *hptr = h; }
        if (h.getShit() == 100) { h.doShit(); *hptr = h; }


        // end of second-cycle
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
        counter++;   
    }
    updateHumanToDB(h);
    coutToConsole("bye", h);
}

std::thread liveLife(Human &h, Clock c, std::string &rf) {
    Human* hpointer = &h;

    std::thread t(&lifeThread, h, hpointer, c, std::ref(rf));
    
    return t;
}

void autoSave(Human &h, std::string &rf) {
    while (rf != "stop") {
        updateHumanToDB(h);
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    }
}

std::thread saveLife(Human &h, std::string &rf) {

    std::thread t(&autoSave, std::ref(h), std::ref(rf));
    
    return t;
}

