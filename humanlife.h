#ifndef HUMANLIFE_H
#define HUMANLIFE_H

extern int computingInterval;

void lifeThread(Human h, Human* hptr, Clock c) {
    coutToConsole("starting life", h);

    unsigned long counter = 0;
    while (true) {
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
}

std::thread liveLife(Human &h, Clock c) {
    Human* hpointer = &h;

    std::thread t(&lifeThread, h, hpointer, c);
    
    return t;
}



#endif