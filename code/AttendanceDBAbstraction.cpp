#include "AttendanceDBAbstraction.h"
#include <iostream>
#include <vector>

using namespace std; 

AttendanceDBAbstraction::AttendanceDBAbstraction(string pathToFile)
	: DBAbstraction(pathToFile) {

    createTables();
}

void AttendanceDBAbstraction::createTables() {
	vector<string> queries;
    string sql = "CREATE TABLE IF NOT EXISTS \"Student\" (\"studentId\"	INTEGER, \"firstName\"	TEXT, \"lastName\"	TEXT, PRIMARY KEY(\"studentId\"))";
	queries.push_back(sql);
	sql = "CREATE TABLE IF NOT EXISTS [Section] ([sectionId]	INTEGER, [coureName]	TEXT, [courseCode]	TEXT, [meetingTime]	TEXT, PRIMARY KEY([sectionId]))";
	queries.push_back(sql);
	sql = "CREATE TABLE IF NOT EXISTS [StudentEnrollsInSection] ([studentId]	INTEGER, [sectionId]	INTEGER, [seatNumber]	INTEGER, FOREIGN KEY([studentId]) REFERENCES [Student]([studentId]), FOREIGN KEY([sectionId]) REFERENCES [Section]([sectionId]), PRIMARY KEY([studentId],[sectionId]))";
	queries.push_back(sql);
	sql = "CREATE TABLE IF NOT EXISTS [AttandanceRecording] ([recordingId]	INTEGER, [date]	TEXT, [status]	TEXT, [studentId]	INTEGER, [sectionId]	INTEGER, FOREIGN KEY([studentId]) REFERENCES [Student]([studentId]), FOREIGN KEY([sectionId]) REFERENCES [Section]([sectionId]), PRIMARY KEY([recordingId]))";
	queries.push_back(sql);

    sqlite3_stmt* myStatement;

	for (int i = 0; i < queries.size(); i++) {
		if (prepareQueryWithResults(queries.at(i), myStatement)) {
			int statusOfStep = sqlite3_step(myStatement);
			if (statusOfStep == SQLITE_OK) { 
            
			}
			sqlite3_finalize(myStatement);
		}
	}
}

void AttendanceDBAbstraction::InsertStudent(string studentID, string first, string last) {
	sqlite3_stmt* myStatement;

    int statusOfPrep = sqlite3_prepare_v2(db, "INSERT INTO Student (studentId, firstName, lastName) VALUES (?, ?, ?)", -1, &myStatement, NULL);
        
	sqlite3_bind_text(myStatement, 1, studentID.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(myStatement, 2, first.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(myStatement, 3, last.c_str(), -1, SQLITE_STATIC);

        if (statusOfPrep == SQLITE_OK)
        {
            int statusOfStep = sqlite3_step(myStatement);

            if (statusOfStep == SQLITE_DONE)
            {
                cout << "Successfully inserted into the database" << endl;
            }
            else
            {
                cout << "Problem inserting into the database" << endl;
            }

            sqlite3_finalize(myStatement);
        }
        else
        {
            cout << "Problem creating a prepared statement" << endl;
        }
}
