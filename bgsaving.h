#ifndef BGSAVING_H
#define BGSAVING_H

void autoSave(Human h, Human* hptr) {
    while (true) {
        updateHumanToDB(h);
    }
}

std::thread startAutoSave(Human &h) {
    Human* hpointer = &h;

    std::thread t(&autoSave, h, hpointer);
    
    return t;
}

#endif