#include <chrono>
#include "../include/clock.hpp"

extern int computingInterval;
extern int runningSpeed;


        Clock::Clock() {
            startTime = timeSinceEpochMS();
        }

        uint64_t Clock::clockAge() {
            uint64_t rightNow = timeSinceEpochMS();
            return (((rightNow - startTime) * runningSpeed)/1000);
        }

        uint64_t Clock::elapsedMS(uint64_t s) {
            uint64_t rightNow = timeSinceEpochMS();
            return ((rightNow - s) * runningSpeed);
        }


        uint64_t Clock::elapsedS(uint64_t s) {
            uint64_t rightNow = timeSinceEpochMS();
            uint64_t fedisch = (((rightNow - s) * runningSpeed)/1000);
            return fedisch;
        }

        uint64_t Clock::timeSinceEpochMS() {
            using namespace std::chrono;
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }

        uint64_t Clock::timeSinceEpochS() {
            using namespace std::chrono;
            return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
        }

        uint64_t Clock::getStartTime() {
            return startTime;
        }

        uint64_t Clock::getEndTime() {
            return endTime;
        }

        uint64_t Clock::getFirstStart() {
            return firstStart;
        }

        std::string Clock::getStringAttribute(std::string s) {
            if (s == "starttime" ) { return std::to_string(startTime); }
            if (s == "endtime" ) { return std::to_string(endTime); }
            if (s == "firststart" ) { return std::to_string(firstStart); }
            return "nada";
        }

