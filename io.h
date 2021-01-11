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
    std::string query =   "INSERT INTO human " \
                        "VALUES ('" + h.getName() + "', " \
                        "'" + h.getGender() + "', " \
                        "'" + h.getHaircolor() + "', '" + h.getBmi() +  "', " \
                        "'" + std::to_string(h.getBirthday()) + "', " \
                        "'" + h.getAmbition() + "', '" + h.getHumor() +  "', " \
                        "'" + h.getEmpathy() + "', '" + h.getSelfawareness() +  "', " \
                        "'" + h.getSelfpity() + "', '" + h.getIntrovert() +  "', " \
                        "'" + h.getSexuality() + "', '" + h.getPainsensitivity() +  "', " \
                        "'" + h.getInnergender() + "', '" + h.getTalkativity() +  "', " \
                        "'" + h.getLogicscore() + "', '" + h.getFeelingscore() +  "', " \
                        "'" + h.getMood() + "', '" + h.getEat() +  "', " \
                        "'" + h.getPiss() + "', '" + h.getShit() +  "', " \
                        "'" + h.getSleep() + "', '" + h.getCompany() +  "', " \
                        "'" + h.getLove() + "', '" + h.getSex() + "');";
                        
    rc = sqlite3_exec(db, query.c_str(), callback, 0, &errorMessage);
    if (rc != SQLITE_OK) { 
        writeToErrorLog("SQL ERROR", errorMessage);
        sqlite3_free(errorMessage);
        return 2; }
    return 0;
}





#endif