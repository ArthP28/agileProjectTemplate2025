#include <iostream>
#include "AttendanceDBAbstraction.h"
using namespace std;

int main()
{
    AttendanceDBAbstraction db("StudentAttendance.sqlite");
	db.InsertStudent("201204", "firt", "lad");
    return 0;
}
