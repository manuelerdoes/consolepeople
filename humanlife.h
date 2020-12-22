#ifndef HUMANLIFE_H
#define HUMANLIFE_H

extern int computingInterval;

int liveLife(Human h) {
    //h.printAttributes();
    pid_t pid = fork();
    if (pid == 0) { 
        std::cout << "starting life of " << h.getName() << std::endl;
        int counter = 0;
        while (true) {
            // print age
            if (h.getAge() != 0 && h.getAge() != 1 && h.getAge() % 60 == 0) { 
                std::cout << h.getName() << " is " << h.getAge() / 60 << " minute(s) old" << std::endl; 
            }

            if (h.getPiss() == 100) { h.doPiss(); }
            if (h.getShit() == 100) { h.doShit(); }


            // end of second-cycle
            std::this_thread::sleep_for(std::chrono::milliseconds(computingInterval));
            h.setAge(counter);
            counter++;          
        }

    }

    return 0;
}

#endif