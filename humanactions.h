#ifndef HUMANACTIONS_H
#define HUMANACTIONS_H

extern int computingInterval;

void Human::doPiss() {
    std::cout << name << " is pissing" << std::endl;
    int maxPiss = piss;
    for (int i = 1; i <= maxPiss; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
        piss--;
    }
    std::cout << name << " finished pissing" << std::endl;
    piss = 0;
}

void Human::doShit() {
    std::cout << name << " is shitting" << std::endl;
    int maxShit = shit;
    for (int i = 1; i <= maxShit; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval*9));
        shit--;
    }
    std::cout << name << " finished shitting" << std::endl;
    shit = 0;
}




#endif