#pragma once 
#include <string> 
#include "sqlite3.h" 
#include "DBAbstraction.h"

using namespace std;

class AttendanceDBAbstraction : DBAbstraction {
public:
    AttendanceDBAbstraction(string pathToFile);

private:
    void createTables();
};