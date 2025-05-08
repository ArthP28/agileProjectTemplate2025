#pragma once 
#include <string> 
#include "sqlite3.h" 
#include "DBAbstraction.h"

using namespace std;

class AttendanceDBAbstraction : DBAbstraction {
public:
    AttendanceDBAbstraction(string pathToFile);
	void InsertStudent(string studentID, string first, string last);
	void InsertSection(string name, string code, string meetingTime);
	void InsertStudentEnroll(string firstName, string lastName, string courseCode);
private:
    void createTables();
};
