#ifndef IO_H
#define IO_H

extern Clock clock1;

extern int computingInterval;
extern std::mutex Mutex1;
extern std::mutex Mutex2;

std::ofstream mainLog("main.log", mainLog.app);

template <class Textout>
void writeToMainLog(Textout s, Human h) {
    std::lock_guard<std::mutex> guard(Mutex2);
    uint64_t cage = clock1.clockAge();
    mainLog << "[" + std::to_string(cage) + "]";
    mainLog << "[" + h.getName() + "] ";
    mainLog << s;
    mainLog << std::endl;
}

template <class Coutput>
void coutToConsole(Coutput o, Human h) {
    std::lock_guard<std::mutex> guard(Mutex1);
    writeToMainLog(o, h);
    std::cout << h.getName() << ": " << o << std::endl;
}





#endif