#pragma once 
#include <string> 
#include "sqlite3.h" 
#include "DBAbstraction.h"

using namespace std;

class AttendanceDBAbstraction : DBAbstraction {
public:
    AttendanceDBAbstraction(string pathToFile);
	void InsertStudent(string studentID, string first, string last);
private:
    void createTables();
};
