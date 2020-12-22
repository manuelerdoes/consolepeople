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

        unsigned long long clockAge() {
            unsigned long long rightNow = timeSinceEpochS();
            return ((rightNow - startTime) * runningSpeed);
        }

        unsigned long long elapsedMS(unsigned long long s) {
            unsigned long long rightNow = timeSinceEpochMS();
            return ((rightNow - s) * runningSpeed);
        }


        unsigned long long elapsedS(unsigned long long s) {
            unsigned long long rightNow = timeSinceEpochS();

            return ((rightNow - s) * runningSpeed);
        }


        unsigned long long timeSinceEpochMS() {
            using namespace std::chrono;
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }

            unsigned long long timeSinceEpochS() {
            using namespace std::chrono;
            return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
        }

};

#endif