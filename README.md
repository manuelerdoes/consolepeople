# consolepeople
## What is ConsolePeople
It's a primitive human simulator. It starts very primitive, but should grow more complex over time. The humans have a set of attributes which describes their personality and their virtual physique. I want the humans to interact with eachother and take certain actions based on their attribute values. In a more sophisticated stadium of the project, the environment should be of importance too. It will influence the life of the humans with it's partly random events.

## How to run
Minimum C++ standard: c++17.  
Needs following libs: pthread, sqlite3

e.g. g++ -std=c++17 -lpthread -lsqlite3 -g main.cpp -o consolepeople

It runs on Linux and MacOS. Should run on Windows too, but I didn't check.