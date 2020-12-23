#ifndef CLOCK_H
#define CLOCK_H

extern int computingInterval;
extern int runningSpeed;

class Clock {
    private:
        unsigned long long startTime;


    public:
        Clock() {
            startTime = timeSinceEpochS();
        }

        uint64_t clockAge() {
            uint64_t rightNow = timeSinceEpochS();
            return ((rightNow - startTime) * runningSpeed);
        }

        uint64_t elapsedMS(uint64_t s) {
            uint64_t rightNow = timeSinceEpochMS();
            return ((rightNow - s) * runningSpeed);
        }


        uint64_t elapsedS(uint64_t s) {
            uint64_t rightNow = timeSinceEpochMS();
            return (((rightNow - s) * runningSpeed)/1000);
        }


        uint64_t timeSinceEpochMS() {
            using namespace std::chrono;
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }

        uint64_t timeSinceEpochS() {
            using namespace std::chrono;
            return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
        }

};

#endif