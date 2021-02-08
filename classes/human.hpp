#ifndef HUMAN_H
#define HUMAN_H


class Human {
    private:
        std::string name;
        std::string gender;
        std::string haircolor;
        float bmi;
        uint64_t birthday; //in ms since epoch

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
        Human(std::string n, std::string g, std::string h, Clock c);

        void printAttributes();

// outside functions
        void doPiss(void);
        void doShit(void);
        void doCalc(void);

// getters & setters
        std::string getName();
        std::string getGender();
        void setGender(std::string g);
        std::string getHaircolor();
        void setHaircolor(std::string hc);
        float getBmi();
        void setBmi(float b);
        uint64_t getBirthday();
        void setBirthday(uint64_t b);
        int getAmbition();
        void setAmbition(int a);
        int getHumor();
        void setHumor(int hu);
        int getEmpathy();
        void setEmpathy(int e);
        int getSelfawareness();
        void setSelfawareness(int s);
        int getSelfpity();
        void setSelfpity(int s);
        int getIntrovert();
        void setIntrovert(int i);
        int getSexuality();
        void setSexuality(int s);
        int getPainsensitivity();
        void setPainsensitivity(int p);
        int getInnergender();
        void setInnergender(int i);
        int getTalkativity();
        void setTalkativity(int t);
        int getLogicscore();
        void setLogicscore(int l);
        int getFeelingscore();
        void setFeelingscore(int f);
        int getMood();
        void setMood(int m);
        int getEat();
        void setEat(int e);
        int getPiss();
        void setPiss(int p);
        int getShit();
        void setShit(int s);
        int getSleep();
        void setSleep(int s);
        int getCompany();
        void setCompany(int c);
        int getLove();
        void setLove(int l);
        int getSex();
        void setSex(int s);

        std::string getStringAttribute(std::string s);



};



#endif