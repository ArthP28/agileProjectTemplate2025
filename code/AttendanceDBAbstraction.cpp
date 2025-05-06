#include "AttendanceDBAbstraction.h"
#include <iostream>

using namespace std; 

AttendanceDBAbstraction::AttendanceDBAbstraction(string pathToFile)
	: DBAbstraction(pathToFile) {

    createTables();
}

void AttendanceDBAbstraction::createTables() {
    string sql = "CREATE TABLE IF NOT EXISTS \"Student\" (\"studentId\"	INTEGER, \"firstName\"	TEXT, \"lastName\"	TEXT, PRIMARY KEY(\"studentId\"))";
    sql += "CREATE TABLE IF NOT EXISTS [Section] ([sectionId]	INTEGER, [coureName]	TEXT, [courseCode]	TEXT, [meetingTime]	TEXT, PRIMARY KEY([sectionId]));";
    sql += "";
    sql += "";

    sqlite3_stmt* myStatement;

    if (prepareQueryWithResults(sql, myStatement)) {
        int statusOfStep = sqlite3_step(myStatement);

        if (statusOfStep == SQLITE_OK) { 
            
        }
        sqlite3_finalize(myStatement);
    }
}