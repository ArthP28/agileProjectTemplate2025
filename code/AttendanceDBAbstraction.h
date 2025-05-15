#pragma once 
#include <string> 
#include "sqlite3.h" 
#include "DBAbstraction.h"
#include <vector>

using namespace std;

struct Student {
	string firstName = "";
	string lastName = "";
	int onTimeFrequency = 0;
	int absentFrequency = 0;
	int lateFrequency = 0;
	string courseName;
};

class AttendanceDBAbstraction : DBAbstraction {
public:
    AttendanceDBAbstraction(string pathToFile);
	void InsertStudent(string studentID, string first, string last);
	void InsertSection(string name, string code, string meetingTime);
	void InsertStudentEnroll(string firstName, string lastName, string courseCode);
	void InsertAttendance(string firstName, string lastName, string courseCode, string date, string status);
	void getCourses();
	vector<Student> GetAllStudentsBySection(string courseCode);
private:
    void createTables();
};
