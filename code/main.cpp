#include <iostream>
#include "AttendanceDBAbstraction.h"
using namespace std;

int main()
{
    AttendanceDBAbstraction db("StudentAttendance.sqlite");
	string in = "y";
	while (in != "n") {
		string id;
		string first;
		string last;
		cout << "id\n";
		cin >> id;
		cout << "first\n";
		cin >> first;
		cout << "last\n";
		cin >> last;
		db.InsertStudent(id, first, last);
		cout << "Continue?\n";
		cin >> in;
	}
	// db.InsertStudent("201204", "firt", "lad");
	// db.InsertSection("Mahoney Baloney", "49", "SMTWRF");
/* 	db.InsertStudentEnroll("stu", "do", "49"); */
    return 0;
}
