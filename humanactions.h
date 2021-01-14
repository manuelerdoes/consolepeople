#ifndef HUMANACTIONS_H
#define HUMANACTIONS_H

extern int computingInterval;
extern std::mutex Mutex1;

void Human::doPiss() {
    coutToConsole("is pissing", *this);
    int maxPiss = piss;
    for (int i = 1; i <= maxPiss; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
        piss--;
    }
    coutToConsole("finished pissing", *this);
    piss = 0;
}

void Human::doShit() {
    coutToConsole("is shitting", *this);
    int maxShit = shit;
    for (int i = 1; i <= maxShit; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval*9));
        shit--;
    }
    coutToConsole("finished shitting", *this);
    shit = 0;
}

void Human::doCalc() {
    uint64_t mumu = 1;
    int pepe;
    for (unsigned long i = 90000000000; i >= 0; i--) {
        pepe = 0;
        for (int c = 1; c <= mumu; c++) {
            if (mumu % c == 0) { pepe++; }
        }

        if (pepe <= 2) {
            coutToConsole("found a prime -> " + std::to_string(mumu), *this);
        }
        mumu++;
    }
}




#endif