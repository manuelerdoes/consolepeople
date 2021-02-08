#ifndef IO_H
#define IO_H

#include <string>
#include <sqlite3.h>
#include "clock.hpp"
#include "human.hpp"

// Error Log
template <class Errorout>
void writeToErrorLog(std::string desc, Errorout e);
// DB Stuff
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int initDB();


// Funcs

template <class Textout>
void writeToMainLog(Textout s, Human h);

// template <class Coutput>
// void coutToConsole(Coutput o, Human h);

void coutToConsole(std::string s, Human h);

int insertClockToDB(Clock c);

int updateClockAttributeToDB(Clock c, std::string s);

int updateClockToDB(Clock c);

int insertHumanToDB(Human h);

int updateHumanAttributeToDB(Human h, std::string s);

int updateHumanToDB(Human h);

std::string getHumanAttributeFromDB(Human h, std::string s);

int loadHumanFromDB(Human &h);

void ioCleanup();


#endif
