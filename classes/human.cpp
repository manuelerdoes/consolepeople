#include "../utilfuncs.cpp"
#include "human.hpp"


        Human::Human(std::string n, std::string g, std::string h, Clock c) {
            name = n;
            gender = g;
            haircolor = h;
            bmi = 21;
            birthday = c.timeSinceEpochMS();

            mood = 0;
            eat = 50;
            piss = 100;
            shit = 100;
            sleep = 50;
            company = 0;
            love = 0;
            sex = 0;

            ambition = randomNumber(1,100);
            humor = randomNumber(30,100);  
            empathy = randomNumber(30,100); 
            selfawareness = randomNumber(10,40);    
            selfpity = randomNumber(30,100);
            introvert = randomNumber(0,100);
            sexuality = tripleProbabilityRandom(10, 3, 4, 3, 70, 20, 10); // 0 -> hetero, 5 -> bi, 10 -> gay
            innergender = tripleProbabilityRandom(10, 3, 4, 3, 75, 10, 15); // 0 -> physical gender, 5 -> both, 10 -> other gender
            painsensitivity = randomNumber(0,100);
            talkativity = randomNumber(0,100);
            logicscore = tripleProbabilityRandom(100, 30, 50, 20, 20, 70, 10);
            feelingscore = randomNumber(0,100);
        }

        void Human::printAttributes() {
            std::cout << "name: " << name << std::endl;
            std::cout << "gender: " << gender << std::endl;
            std::cout << "haircolor: " << haircolor << std::endl;
            std::cout << "BMI: " << bmi << std::endl << std::endl;

            std::cout << "mood: " << mood << std::endl;
            std::cout << "eat: " << eat << std::endl;
            std::cout << "piss: " << piss << std::endl;
            std::cout << "shit: " << shit << std::endl;
            std::cout << "sleep: " << sleep << std::endl;
            std::cout << "company: " << company << std::endl;
            std::cout << "love: " << love << std::endl;
            std::cout << "sex: " << sex << std::endl << std::endl;
            
            std::cout << "ambition: " << ambition << std::endl;
            std::cout << "humor: " << humor << std::endl;
            std::cout << "empathy: " << empathy << std::endl;
            std::cout << "selfawareness: " << selfawareness << std::endl;
            std::cout << "selfpity: " << selfpity << std::endl;
            std::cout << "introvert: " << introvert << std::endl;
            std::cout << "sexuality: " << sexuality;
            std::string sexDescription;
            if (sexuality <= 3) { sexDescription = "hetero"; };
            if (sexuality > 3 && sexuality < 8) { sexDescription = "bi"; };
            if (sexuality >= 8) { sexDescription = "gay"; };
            std::cout << " (" << sexDescription << ")" << std::endl;
            std::cout << "innergender: " << innergender << std::endl;
            std::cout << "painsensitivity: " << painsensitivity << std::endl;
            std::cout << "talkativity: " << talkativity << std::endl;
            std::cout << "logicscore: " << logicscore << std::endl;
            std::cout << "feelingscore: " << feelingscore << std::endl;
        }

// getters & setters
        std::string Human::getName() { return name; }
        std::string Human::getGender() { return gender; }
        void Human::setGender(std::string g) { gender = g; }
        std::string Human::getHaircolor() { return haircolor; }
        void Human::setHaircolor(std::string hc) { haircolor = hc; }
        float Human::getBmi() { return bmi; }
        void Human::setBmi(float b) { bmi = b; }
        uint64_t Human::getBirthday() { return birthday; }
        void Human::setBirthday(uint64_t b) { birthday = b; }
        int Human::getAmbition() { return ambition; }
        void Human::setAmbition(int a) { ambition = a; }
        int Human::getHumor() { return humor; }
        void Human::setHumor(int hu) { humor = hu; }
        int Human::getEmpathy() { return empathy; }
        void Human::setEmpathy(int e) { empathy = e; }
        int Human::getSelfawareness() { return selfawareness; }
        void Human::setSelfawareness(int s) { selfawareness = s; }
        int Human::getSelfpity() { return selfpity; }
        void Human::setSelfpity(int s) { selfpity = s; }
        int Human::getIntrovert() { return introvert; }
        void Human::setIntrovert(int i) { introvert = i; }
        int Human::getSexuality() { return sexuality; }
        void Human::setSexuality(int s) { sexuality = s; }
        int Human::getPainsensitivity() { return painsensitivity; }
        void Human::setPainsensitivity(int p) { painsensitivity = p; }
        int Human::getInnergender() { return innergender; }
        void Human::setInnergender(int i) { innergender = i; }
        int Human::getTalkativity() { return talkativity; }
        void Human::setTalkativity(int t) { talkativity = t; }
        int Human::getLogicscore() { return logicscore; }
        void Human::setLogicscore(int l) { logicscore = l; }
        int Human::getFeelingscore() { return feelingscore; }
        void Human::setFeelingscore(int f) { feelingscore = f; }
        int Human::getMood() { return mood; }
        void Human::setMood(int m) { mood = m; }
        int Human::getEat() { return eat; }
        void Human::setEat(int e) { eat = e; }
        int Human::getPiss() { return piss; }
        void Human::setPiss(int p) { piss = p; }
        int Human::getShit() { return shit; }
        void Human::setShit(int s) { shit = s; }
        int Human::getSleep() { return sleep; }
        void Human::setSleep(int s) { sleep = s; }
        int Human::getCompany() { return company; }
        void Human::setCompany(int c) { company = c; }
        int Human::getLove() { return love; }
        void Human::setLove(int l) { love = l; }
        int Human::getSex () { return sex; }
        void Human::setSex(int s) { sex = s; }

        std::string Human::getStringAttribute(std::string s) {
            if (s == "name") { return name; }
            if (s == "gender") { return gender; }
            if (s == "haircolor" ) { return haircolor; }
            if (s == "bmi" ) { return std::to_string(bmi); }
            if (s == "birthday" ) { return std::to_string(birthday); }
            if (s == "ambition" ) { return std::to_string(ambition); }
            if (s == "humor" ) { return std::to_string(humor); }
            if (s == "empathy" ) { return std::to_string(empathy); }
            if (s == "selfawareness" ) { return std::to_string(selfawareness); }
            if (s == "selfpity" ) { return std::to_string(selfpity); }
            if (s == "introvert" ) { return std::to_string(introvert); }
            if (s == "sexuality" ) { return std::to_string(sexuality); }
            if (s == "painsensitivity" ) { return std::to_string(painsensitivity); }
            if (s == "innergender" ) { return std::to_string(innergender); }
            if (s == "talkativity" ) { return std::to_string(talkativity); }
            if (s == "logicscore" ) { return std::to_string(logicscore); }
            if (s == "feelingscore" ) { return std::to_string(feelingscore); }
            if (s == "mood" ) { return std::to_string(mood); }
            if (s == "eat" ) { return std::to_string(eat); }
            if (s == "piss" ) { return std::to_string(piss); }
            if (s == "shit" ) { return std::to_string(shit); }
            if (s == "sleep" ) { return std::to_string(sleep); }
            if (s == "company" ) { return std::to_string(company); }
            if (s == "love" ) { return std::to_string(love); }
            if (s == "sex" ) { return std::to_string(sex); }
            return "nada";
        }
