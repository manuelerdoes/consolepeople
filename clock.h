#ifndef CLOCK_H
#define CLOCK_H

class Clock {
    private:
        unsigned long long startTime;


    public:
        Clock() {
            startTime = timeSinceEpoch();
        }
        
        unsigned long long elapsed() {
            unsigned long long rightNow = timeSinceEpoch();
            return (rightNow - startTime) / 1000;
        }

        unsigned long long timeSinceEpoch() {
            using namespace std::chrono;
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }

};

#endif