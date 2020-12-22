#ifndef HUMAN_H
#define HUMAN_H

#include "../utilfuncs.h"

class Human {
    private:
        std::string name;
        std::string gender;
        std::string haircolor;
        float bmi;
        unsigned long age; //in seconds -> 32bit -> 136 years max

// character and stuff
        int ambition;
        int humor;
        int empathy;
        int selfawareness;
        int selfpity;
        int introvert;
        int sexuality;
        int painsensitivity;
        int innergender;
        int talkativity;
        int logicscore;
        int feelingscore;

// state
    // musts
        int mood;
        int eat;
        int piss;
        int shit;
        int sleep;
    // wants
        int company;
        int love;
        int sex;
        //int recognition;
        //int friendship;

    public:
        Human(std::string n, std::string g, std::string h, unsigned long a) {
            name = n;
            gender = g;
            haircolor = h;
            bmi = 21;
            age = a;

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

        void printAttributes() {
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

// outside functions
        void doPiss(void);
        void doShit(void);

// getters & setters
        std::string getName() { return name; }
        std::string getGender() { return gender; }
        std::string getHaircolor() { return haircolor; }
        float getBmi() { return bmi; }
        int getAge() { return age; }
        void setAge(unsigned long a) { age = a; }
        int getAmbition() { return ambition; }
        int getHumor() { return humor; }
        int getEmpathy() { return empathy; }
        int getSelfawareness() { return selfawareness; }
        int getSelfpity() { return selfpity; }
        int getIntrovert() { return introvert; }
        int getSexuality() { return sexuality; }
        int getPainsensitivity() { return painsensitivity; }
        int getInnergender() { return innergender; }
        int getTalkativity() { return talkativity; }
        int getLogicscore() { return logicscore; }
        int getFeelingscore() { return feelingscore; }
        int getMood() { return mood; }
        int getEat() { return eat; }
        int getPiss() { return piss; }
        void setPiss(int p) { piss = p; }
        int getShit() { return shit; }
        int getSleep() { return sleep; }
        int getCompany() { return company; }
        int getLove() { return love; }
        int getSex () { return sex; }


};



#endif