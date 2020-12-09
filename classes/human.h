#ifndef HUMAN_H
#define HUMAN_H

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
            sexuality = randomNumber(0,10); // 0 -> hetero, 5 -> bi, 10 -> gay
            innergender = randomNumber(0,10); // 0 -> physical gender, 5 -> both, 10 -> other gender
            painsensitivity = randomNumber(0,100);
            talkativity = randomNumber(0,100);
            logicscore = randomNumber(0,100);
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

        }
};

#endif