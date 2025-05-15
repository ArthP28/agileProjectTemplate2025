#include <iostream>
#include "AttendanceDBAbstraction.h"
using namespace std;

int main()
{
    AttendanceDBAbstraction db("./StudentAttendance.sqlite");
	// db.InsertStudent("201203", "Andrew", "Del Real");
	// db.InsertSection("Mahoney Baloney", "49", "SMTWRF");
	// db.InsertStudentEnroll("Andrew", "Del Real", "49");
    vector<Student> students = db.GetAllStudentsBySection("49");

    for (auto student : students) {
        cout << student.firstName << endl;
        cout << student.lastName << endl;
    }

    return 0;
}
