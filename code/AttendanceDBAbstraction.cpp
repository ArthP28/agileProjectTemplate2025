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
	sql = "CREATE TABLE IF NOT EXISTS [Section] ([sectionId]	INTEGER, [courseName]	TEXT, [courseCode]	TEXT, [meetingTime]	TEXT, PRIMARY KEY([sectionId]))";
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

void AttendanceDBAbstraction::InsertSection(string name, string code, string meetingTime) {
	sqlite3_stmt* myStatement;

    int statusOfPrep = sqlite3_prepare_v2(db, "INSERT INTO Section (courseName, courseCode, meetingTime) VALUES (?, ?, ?)", -1, &myStatement, NULL);
        
	sqlite3_bind_text(myStatement, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 2, code.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 3, meetingTime.c_str(), -1, SQLITE_STATIC);

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

void AttendanceDBAbstraction::InsertStudentEnroll(string firstName, string lastName, string courseCode) {
	sqlite3_stmt* myStatement;

    int statusOfPrep = sqlite3_prepare_v2(db, "WITH studentId AS (SELECT studentId FROM Student WHERE firstName = ? AND lastName = ?),"
			   "sectionId AS (SELECT sectionId FROM Section WHERE courseCode = ?) INSERT INTO [StudentEnrollsInSection] ([studentId],"
										  "[sectionId], [seatNumber]) SELECT studentId, sectionId, 1 FROM studentId, sectionId", -1, &myStatement, NULL);
        
	sqlite3_bind_text(myStatement, 1, firstName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 2, lastName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 3, courseCode.c_str(), -1, SQLITE_STATIC);

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

void AttendanceDBAbstraction::InsertAttendance(string firstName, string lastName, string courseCode, string date, string status) {
	sqlite3_stmt* myStatement;

    int statusOfPrep = sqlite3_prepare_v2(db, "WITH studentId AS (SELECT studentId FROM Student WHERE firstName = ? AND lastName = ?),"
										  "sectionId AS (SELECT sectionId FROM Section WHERE courseCode = ?)"
										  "INSERT INTO [AttendanceRecording] ([date], [status], [studentId], [sectionId])"
										  "SELECT ?, ?, studentId, sectionId FROM studentId, sectionId", -1, &myStatement, NULL);
        
	sqlite3_bind_text(myStatement, 1, firstName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 2, lastName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 3, courseCode.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(myStatement, 4, date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(myStatement, 5, status.c_str(), -1, SQLITE_STATIC);

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


vector<Student> AttendanceDBAbstraction::GetAllStudentsBySection(string courseCode) {
    sqlite3_stmt* myStatement;

    vector<Student> retval;

    int statusOfPrep = sqlite3_prepare_v2(db, "SELECT Student.firstName, Student.lastName FROM Student JOIN StudentEnrollsInSection ON Student.studentId = StudentEnrollsInSection.studentId JOIN Section ON StudentEnrollsInSection.sectionId = Section.sectionId WHERE Section.courseCode = ? ORDER BY Student.lastName ASC;", -1, &myStatement, NULL);
    sqlite3_bind_text(myStatement, 1, courseCode.c_str(), -1, SQLITE_STATIC);


    if (statusOfPrep == SQLITE_OK) {
        int statusOfStep = sqlite3_step(myStatement);

        while (statusOfStep == SQLITE_ROW) {
            string firstName = ((char*)sqlite3_column_text(myStatement, 0));
            string lastName = ((char*)sqlite3_column_text(myStatement, 1));

            Student newStudent;
            newStudent.firstName = firstName;
            newStudent.lastName = lastName;
            // cout << firstName << endl;
            // cout << lastName << endl;

            retval.push_back(newStudent);
            statusOfStep = sqlite3_step(myStatement);
        }

        sqlite3_finalize(myStatement);
    }

    return retval;
}
