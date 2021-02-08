#ifndef HUMANLIFE_H
#define HUMANLIFE_H

#include <thread>
#include <string>
#include "classes/clock.hpp"
#include "classes/human.hpp"

void lifeThread(Human h, Human* hptr, Clock c, std::string &rf);

std::thread liveLife(Human &h, Clock c, std::string &rf);

void autoSave(Human &h, std::string &rf);

std::thread saveLife(Human &h, std::string &rf);

#endif