#ifndef IO_H
#define IO_H

extern Clock clock1;

extern int computingInterval;
extern std::mutex Mutex1;
extern std::mutex Mutex2;

// Open Files
std::ofstream mainLog("main.log", mainLog.app);
std::ofstream errorLog("error.log", errorLog.app);

// Error Log
template <class Errorout>
void writeToErrorLog(std::string desc, Errorout e) {
    time_t now = time(0);
    std::string nowstr = ctime(&now);
    nowstr.pop_back();
    errorLog << "[" + nowstr + "] " + desc + ": ";
    errorLog << e << std::endl;
}

// DB Stuff
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

sqlite3* db;
char* errorMessage = 0;
int rc = sqlite3_open("cp.db", &db);

int initDB() {
    
    if (rc) { 
        writeToErrorLog("SQL ERROR", sqlite3_errmsg(db));
        return 1; 
    }

    const char* sql = "CREATE TABLE human("  \
        "name           TEXT," \
        "gender         TEXT," \
        "haircolor      TEXT," \
        "bmi            REAL, " \
        "birthday       TEXT, " \
        "ambition       INT, " \
        "humor          INT, " \
        "empathy        INT, " \
        "selfawareness  INT, " \
        "selfpity       INT, " \
        "introvert      INT, " \
        "sexuality      INT, " \
        "painsensitivity INT, " \
        "innergender    INT, " \
        "talkativity    INT, " \
        "logicscore     INT, " \
        "feelingscore   INT, " \
        "mood           INT, " \
        "eat            INT, " \
        "piss           INT, " \
        "shit           INT, " \
        "sleep          INT, " \
        "company        INT, " \
        "love           INT, " \
        "sex            INT);";

    rc = sqlite3_exec(db, sql, callback, 0, &errorMessage);
    if (rc != SQLITE_OK) { return 2; }

    return 0;
}


// Funcs

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

int saveToDB() {
    return 0;
} 

int insertHumanToDB(Human h) {
    std::string query = "INSERT INTO human " \
                "VALUES ('" + h.getName() + "', " \
                "'" + h.getGender() + "', '" + h.getHaircolor() + "', " \
                "'" + std::to_string(h.getBmi()) +  "', '" + std::to_string(h.getBirthday()) + "', " \
                "'" + std::to_string(h.getAmbition()) + "', '" + std::to_string(h.getHumor()) +  "', " \
                "'" + std::to_string(h.getEmpathy()) + "', '" + std::to_string(h.getSelfawareness()) +  "', " \
                "'" + std::to_string(h.getSelfpity()) + "', '" + std::to_string(h.getIntrovert()) +  "', " \
                "'" + std::to_string(h.getSexuality()) + "', '" + std::to_string(h.getPainsensitivity()) +  "', " \
                "'" + std::to_string(h.getInnergender()) + "', '" + std::to_string(h.getTalkativity()) +  "', " \
                "'" + std::to_string(h.getLogicscore()) + "', '" + std::to_string(h.getFeelingscore()) +  "', " \
                "'" + std::to_string(h.getMood()) + "', '" + std::to_string(h.getEat()) +  "', " \
                "'" + std::to_string(h.getPiss()) + "', '" + std::to_string(h.getShit()) +  "', " \
                "'" + std::to_string(h.getSleep()) + "', '" + std::to_string(h.getCompany()) +  "', " \
                "'" + std::to_string(h.getLove()) + "', '" + std::to_string(h.getSex()) + "');";
                        
    rc = sqlite3_exec(db, query.c_str(), callback, 0, &errorMessage);
    if (rc != SQLITE_OK) { 
        writeToErrorLog("SQL ERROR", errorMessage);
        sqlite3_free(errorMessage);
        return 2; }
    return 0;
}

int updateHumanAttributeToDB(Human h, std::string s) {
    std::string query = "UPDATE human SET " + s + " = " + h.getStringAttribute(s) + " WHERE name = '" + h.getName() + "';";
    rc = sqlite3_exec(db, query.c_str(), callback, 0, &errorMessage);
    if (rc != SQLITE_OK) { 
        writeToErrorLog("SQL ERROR", errorMessage);
        sqlite3_free(errorMessage);
        return 2; }
    return 0;
}

int updateHumanToDB(Human h) {
    int dbok = updateHumanAttributeToDB(h, "bmi");
    dbok += updateHumanAttributeToDB(h, "ambition");
    dbok += updateHumanAttributeToDB(h, "humor");
    dbok += updateHumanAttributeToDB(h, "empathy");
    dbok += updateHumanAttributeToDB(h, "selfawareness");
    dbok += updateHumanAttributeToDB(h, "selfpity");
    dbok += updateHumanAttributeToDB(h, "introvert");
    dbok += updateHumanAttributeToDB(h, "sexuality");
    dbok += updateHumanAttributeToDB(h, "painsensitivity");
    dbok += updateHumanAttributeToDB(h, "innergender");
    dbok += updateHumanAttributeToDB(h, "talkativity");
    dbok += updateHumanAttributeToDB(h, "logicscore");
    dbok += updateHumanAttributeToDB(h, "feelingscore");
    dbok += updateHumanAttributeToDB(h, "mood");
    dbok += updateHumanAttributeToDB(h, "eat");
    dbok += updateHumanAttributeToDB(h, "piss");
    dbok += updateHumanAttributeToDB(h, "shit");
    dbok += updateHumanAttributeToDB(h, "sleep");
    dbok += updateHumanAttributeToDB(h, "company");
    dbok += updateHumanAttributeToDB(h, "love");
    dbok += updateHumanAttributeToDB(h, "sex");
    if (dbok > 0) { return 1; }
    return 0;
}

std::string getHumanAttributeFromDB(Human h, std::string s) {
    std::string query = "SELECT " + s + " FROM human WHERE name = '" + h.getName() + "';";
    sqlite3_stmt * stmt;
    std::string result;
    sqlite3_prepare(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    result = (char *)sqlite3_column_text(stmt, 0);
    return result;
}

int loadHumanFromDB(Human h) {
    int sumus = 0;
    std::vector<std::string> haircolors {"brown", "black", "blonde", "white", "grey"};

    h.setGender(getHumanAttributeFromDB(h, "gender"));
    if (h.getGender() == "male" || h.getGender() == "female") { sumus++; }
    h.setHaircolor(getHumanAttributeFromDB(h, "haircolor"));
    for (int i = 0; i < haircolors.size(); i++) {
        if (h.getHaircolor() == haircolors[i]) { sumus++; }
    }
    h.setBmi(std::stof(getHumanAttributeFromDB(h, "bmi")));
    if (h.getBmi() >= 0 && h.getBmi() <= 100) { sumus++ ;}
    h.setBirthday(std::stoi(getHumanAttributeFromDB(h, "birthday")));
    if (h.getBirthday() >= 100000 && h.getBirthday() <= 9999611651931323) { sumus++; }
    h.setAmbition(std::stoi(getHumanAttributeFromDB(h, "ambition")));
    if (h.getAmbition() >= 0 && h.getAmbition() <= 100) { sumus++; }
    h.setHumor(std::stoi(getHumanAttributeFromDB(h, "humor")));
    if (h.getHumor() >= 0 && h.getHumor() <= 100) { sumus++; }
    h.setEmpathy(std::stoi(getHumanAttributeFromDB(h, "empathy")));
    if (h.getEmpathy() >= 0 && h.getEmpathy() <= 100) { sumus++; }
    h.setSelfawareness(std::stoi(getHumanAttributeFromDB(h, "selfawareness")));
    if (h.getSelfawareness() >= 0 && h.getSelfawareness() <= 100) { sumus++; }
    h.setSelfpity(std::stoi(getHumanAttributeFromDB(h, "selfpity")));
    if (h.getSelfpity() >= 0 && h.getSelfpity() <= 100) { sumus++; }
    h.setIntrovert(std::stoi(getHumanAttributeFromDB(h, "introvert")));
    if (h.getIntrovert() >= 0 && h.getIntrovert() <= 100) { sumus++; } 
    h.setSexuality(std::stoi(getHumanAttributeFromDB(h, "sexuality")));
    if (h.getSexuality() >= 0 && h.getSexuality() <= 10) { sumus++; }
    h.setPainsensitivity(std::stoi(getHumanAttributeFromDB(h, "painsensitivity")));
    if (h.getPainsensitivity() >= 0 && h.getPainsensitivity() <= 100) { sumus++; }
    h.setInnergender(std::stoi(getHumanAttributeFromDB(h, "innergender")));
    if (h.getInnergender() >= 0 && h.getInnergender() <= 10) { sumus++; }
    h.setTalkativity(std::stoi(getHumanAttributeFromDB(h, "talkativity")));
    if (h.getTalkativity() >= 0 && h.getTalkativity() <= 100) { sumus++; }
    h.setLogicscore(std::stoi(getHumanAttributeFromDB(h, "logicscore")));
    if (h.getLogicscore() >= 0 && h.getLogicscore() <= 100) { sumus++; }
    h.setFeelingscore(std::stoi(getHumanAttributeFromDB(h, "feelingscore")));
    if (h.getFeelingscore() >= 0 && h.getFeelingscore() <= 100) { sumus++; }
    h.setMood(std::stoi(getHumanAttributeFromDB(h, "mood")));
    if (h.getMood() >= 0 && h.getMood() <= 100) { sumus++; }
    h.setEat(std::stoi(getHumanAttributeFromDB(h, "eat")));
    if (h.getEat() >= 0 && h.getEat() <= 100) { sumus++; }
    h.setPiss(std::stoi(getHumanAttributeFromDB(h, "piss")));
    if (h.getPiss() >= 0 && h.getPiss() <= 100) { sumus++; }
    h.setShit(std::stoi(getHumanAttributeFromDB(h, "shit")));
    if (h.getShit() >= 0 && h.getShit() <= 100) { sumus++; }
    h.setSleep(std::stoi(getHumanAttributeFromDB(h, "sleep")));
    if (h.getSleep() >= 0 && h.getSleep() <= 100) { sumus++; }
    h.setCompany(std::stoi(getHumanAttributeFromDB(h, "company")));
    if (h.getCompany() >= 0 && h.getCompany() <= 100) { sumus++; }
    h.setLove(std::stoi(getHumanAttributeFromDB(h, "love")));
    if (h.getLove() >= 0 && h.getLove() <= 100) { sumus++; }
    h.setSex(std::stoi(getHumanAttributeFromDB(h, "sex")));
    if (h.getSex() >= 0 && h.getSex() <= 100) { sumus++; }

    if (sumus != 24) { return 1; }
    return 0;
}



#endif
