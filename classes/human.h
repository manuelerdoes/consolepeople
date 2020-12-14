#ifndef HUMAN_H
#define HUMAN_H

#include "../utilfuncs.h"

class Human {
    private:
        std::string name;
        std::string gender;
        std::string haircolor;
        float bmi;

        int mood;

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

    public:
        Human(std::string name1, std::string gender1, std::string haircolor1, float bmi1) {
            name = name1;
            gender = gender1;
            haircolor = haircolor1;
            bmi = bmi1;

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
        }
};

#endif