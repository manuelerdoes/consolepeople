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
    //std::cout << h.getName() << ": " << o << std::endl;
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
    std::lock_guard<std::mutex> guard(Mutex2);
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
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = (char *)sqlite3_column_text(stmt, 0);
    } else { result = "empty"; }
    return result;
}

int loadHumanFromDB(Human &h) {
    int sumus = 0;
    std::vector<std::string> haircolors {"brown", "black", "blonde", "white", "grey"};

    std::string gender = getHumanAttributeFromDB(h, "gender");
    if (gender == "male" || gender == "female") { sumus++; } else {
        gender = "nonbinary";
    }
    h.setGender(gender);

    std::string haircolor = getHumanAttributeFromDB(h, "haircolor");
    for (int i = 0; i < haircolors.size(); i++) {
        if (haircolor == haircolors[i]) { sumus++; }
    }
    if (sumus != 2) { haircolor = "transparent"; }
    h.setHaircolor(haircolor);

    float bmi = std::stof(getHumanAttributeFromDB(h, "bmi"));
    if (bmi >= 0 && bmi <= 100) { sumus++; } else { bmi = 55; } 
    h.setBmi(bmi);

    uint64_t birthday = std::stoull(getHumanAttributeFromDB(h, "birthday"));
    if (birthday >= 100000 && birthday <= 9999611651931323) { sumus++; } else { birthday = 1511651931323; }
    h.setBirthday(birthday);

    int ambition = std::stoi(getHumanAttributeFromDB(h, "ambition"));
    if (ambition >= 0 && ambition <= 100) { sumus++; } else { ambition = 0; }
    h.setAmbition(ambition);
    
    int humor = std::stoi(getHumanAttributeFromDB(h, "humor"));
    if (humor >= 0 && humor <= 100) { sumus++; } else { humor = 0; }
    h.setHumor(humor);

    int empathy = std::stoi(getHumanAttributeFromDB(h, "empathy"));
    if (empathy >= 0 && empathy <= 100) { sumus++; } else { empathy = 0; }
    h.setEmpathy(empathy);

    int selfawareness = std::stoi(getHumanAttributeFromDB(h, "selfawareness"));
    if (h.getSelfawareness() >= 0 && h.getSelfawareness() <= 100) { sumus++; } else { selfawareness = 0; }
    h.setSelfawareness(selfawareness);

    int selfpity = std::stoi(getHumanAttributeFromDB(h, "selfpity"));
    if (selfpity >= 0 && selfpity <= 100) { sumus++; } else { selfpity = 0; }
    h.setSelfpity(selfpity);

    int introvert = std::stoi(getHumanAttributeFromDB(h, "introvert"));
    if (introvert >= 0 && introvert <= 100) { sumus++; } else { introvert = 0; }
    h.setIntrovert(introvert);

    int sexuality = std::stoi(getHumanAttributeFromDB(h, "sexuality"));
    if (sexuality >= 0 && sexuality <= 10) { sumus++; } else { sexuality = 0; }
    h.setSexuality(sexuality);

    int painsensitivity = std::stoi(getHumanAttributeFromDB(h, "painsensitivity"));
    if (painsensitivity >= 0 && painsensitivity <= 100) { sumus++; } else { painsensitivity = 0; }
    h.setPainsensitivity(painsensitivity);

    int innergender = std::stoi(getHumanAttributeFromDB(h, "innergender"));
    if (innergender >= 0 && innergender <= 10) { sumus++; } else { innergender = 0; }
    h.setInnergender(innergender);

    int talkativity = std::stoi(getHumanAttributeFromDB(h, "talkativity"));
    if (talkativity >= 0 && talkativity <= 100) { sumus++; } else { talkativity = 0; }
    h.setTalkativity(talkativity);

    int logicscore = std::stoi(getHumanAttributeFromDB(h, "logicscore"));
    if (logicscore >= 0 && logicscore <= 100) { sumus++; } else { logicscore = 0; }
    h.setLogicscore(logicscore);
    
    int feelingscore = std::stoi(getHumanAttributeFromDB(h, "feelingscore"));
    if (feelingscore >= 0 && feelingscore <= 100) { sumus++; } else { feelingscore = 0; }
    h.setFeelingscore(feelingscore);

    int mood = std::stoi(getHumanAttributeFromDB(h, "mood"));
    if (mood >= 0 && mood <= 100) { sumus++; } else { mood = 0; }
    h.setMood(mood);
    
    int eat = std::stoi(getHumanAttributeFromDB(h, "eat"));
    if (eat >= 0 && eat <= 100) { sumus++; } else { eat = 0; }
    h.setEat(eat);

    int piss = std::stoi(getHumanAttributeFromDB(h, "piss"));
    if (piss >= 0 && piss <= 100) { sumus++; } else { piss = 0; }
    h.setPiss(piss);

    int shit = std::stoi(getHumanAttributeFromDB(h, "shit"));
    if (shit >= 0 && shit <= 100) { sumus++; } else { shit = 0; }
    h.setShit(shit);
    
    int sleep = std::stoi(getHumanAttributeFromDB(h, "sleep"));
    if (sleep >= 0 && sleep <= 100) { sumus++; } else { sleep = 0; }
    h.setSleep(sleep);
    
    int company = std::stoi(getHumanAttributeFromDB(h, "company"));
    if (company >= 0 && company <= 100) { sumus++; } else { company = 0; }
    h.setCompany(company);
    
    int love = std::stoi(getHumanAttributeFromDB(h, "love"));
    if (love >= 0 && love <= 100) { sumus++; } else { love = 0; }
    h.setLove(love);
    
    int sex = std::stoi(getHumanAttributeFromDB(h, "sex"));
    if (sex  >= 0 && sex <= 100) { sumus++; } else { sex = 0; }
    h.setSex(sex);
    
    if (sumus != 24) { return 1; }
    return 0;
}


#endif
