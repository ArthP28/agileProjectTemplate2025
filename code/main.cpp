#include <iostream>
#include "AttendanceDBAbstraction.h"
using namespace std;

int main()
{
    AttendanceDBAbstraction db("./StudentAttendance.sqlite");
	// db.InsertStudent("201204", "firt", "lad");
	// db.InsertSection("Mahoney Baloney", "49", "SMTWRF");
	db.InsertStudentEnroll("firt", "lad", "49");
    return 0;
}
