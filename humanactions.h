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




#endif