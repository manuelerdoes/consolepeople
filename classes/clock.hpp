#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {
    private:
        uint64_t startTime;
        uint64_t endTime;
        uint64_t firstStart;


    public:
        Clock();

        uint64_t clockAge();

        uint64_t elapsedMS(uint64_t s);


        uint64_t elapsedS(uint64_t s);

        uint64_t timeSinceEpochMS();

        uint64_t timeSinceEpochS();

        uint64_t getStartTime();

        uint64_t getEndTime();

        uint64_t getFirstStart();

        std::string getStringAttribute(std::string s);

};

#endif