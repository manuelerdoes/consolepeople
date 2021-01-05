#ifndef HUMANLIFE_H
#define HUMANLIFE_H

extern int computingInterval;

void lifeThread(Human h, Human* hptr, Clock c) {
    std::cout << "starting life of " << h.getName() << std::endl;

    unsigned long counter = 0;
    while (true) {
        // print age
        int age = c.elapsedS(h.getBirthday());
        if (age >= 600 && age < 3600 && counter % 600 == 0) { 
            std::cout << h.getName() << " is " << age / 60 << " minute(s) old" << std::endl;
        }
        if (age >= 3600 && age < 86400 && counter % 3600 == 0) { 
            std::cout << h.getName() << " is " << age / 3600 << " hour(s) old" << std::endl; 
        }
        if (age >= 86400 && age < 31536000 && counter % 86400 == 0) { 
            std::cout << h.getName() << " is " << age / 86400 << " day(s) old" << std::endl; 
        }
        if (age >= 31536000 && counter % 31536000 == 0) { 
            std::cout << h.getName() << " is " << age / 31536000 << " year(s) old" << std::endl; 
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