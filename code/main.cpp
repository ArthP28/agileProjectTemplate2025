// For Sys(Clear) which is currently experimental
#ifdef _WIN32
#include <stdlib.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <vector>

#include "AttendanceDBAbstraction.h"
using namespace std;

//
void printMainMenu();
void printTakeAttendanceMenu();
void printViewAttendanceMenu();
void enrollNewStudent();
Student constructStudent(string name, string surname, int onTimeNum, int absentNum, int lateNum, string course);
AttendanceDBAbstraction db("./StudentAttendance.sqlite");
vector<Student> students = db.GetAllStudentsBySection("49");

int main()
{
    db.InsertStudent("279979", "Comet", "Albright");
    db.InsertStudent("997744", "Michael", "Mars");
    db.InsertStudent("419472", "Pollie", "Kilburn");
    db.InsertStudent("334455", "Ivy", "Brown");
    db.InsertStudentEnroll("Michael", "Mars", "49");
    db.InsertStudentEnroll("Comet", "Albright", "49");
    db.InsertStudentEnroll("Pollie", "Kilburn", "49");
    db.InsertStudentEnroll("Ivy", "Brown", "49");
	// db.InsertStudent("201203", "Andrew", "Del Real");
	// db.InsertSection("Mahoney Baloney", "49", "SMTWRF");
	// db.InsertStudentEnroll("Andrew", "Del Real", "49");

    students = db.GetAllStudentsBySection("49");

    for (auto student : students) {
        cout << student.firstName << endl;
        cout << student.lastName << endl;
    }
    cout<<"Agile Project"<<endl;
    
    printMainMenu();
    

	db.getCourses();

    // string in = "y";
	// while (in != "n") {
	// 	string id;
	// 	string first;
	// 	string last;
	// 	cout << "id\n";
	// 	cin >> id;
	// 	cout << "first\n";
	// 	cin >> first;
	// 	cout << "last\n";
	// 	cin >> last;
	// 	db.InsertStudent(id, first, last);
	// 	cout << "Continue?\n";
	// 	cin >> in;
	// }

    return 0;
}

void printMainMenu(){
    
    string input;
    cout<<"Please type number cooresponding to the option you want: "<<endl;
    cout<<"1: Take attendance"<<endl;
    cout<<"2: View attendance"<<endl;
    cout<<"3: Enroll New Student"<<endl;
    cout<<"4: Add New Course"<<endl;
    
    
    cin>>input;
    
    if(input == "1"){
        printTakeAttendanceMenu();
    }
    else if(input == "2"){
        printViewAttendanceMenu();
    }
    else if(input == "3"){
        enrollNewStudent();
    }
    else if(input == "4"){
        cout << "Adding New Course goes here" << endl;
    }
    else{
        cout<<"Please enter a valid number!"<<endl;
        printMainMenu();
    }
}

void printTakeAttendanceMenu(){
    string input;
    vector<Student> students;
    
    cout<<"Please enter number1 of course you want to take attendance for: "<<endl;
    
    cin>>input;
    
    students = db.GetAllStudentsBySection(input);
    
    cout<<"For each name type one of the following options: "<<endl;
    cout<<" present"<<endl;
    cout<<" excused absent"<<endl;
    cout<<" not excused absent"<<endl;
    cout<<" late"<<endl;
    cout<<endl;
    cout<<"Or type return to return to the main menu"<<endl;
    cout<<endl;
    
    //for each student in global vector
    for (int i = 0; i < students.size(); i++) {
        cout<<students.at(i).firstName<<" "<<students.at(i).lastName<<": "<<endl;
        cin>>input;
        cout<<endl;
        
        if(input == "present"){
            db.InsertAttendance(students.at(i).firstName, students.at(i).lastName, input, "5/15/2025", "present");
        }
        else if(input == "excused_absent"){
            db.InsertAttendance(students.at(i).firstName, students.at(i).lastName, input, "5/15/2025", "excused absent");
        }
        else if(input == "not_excused_absent"){
            db.InsertAttendance(students.at(i).firstName, students.at(i).lastName, input, "5/15/2025", "not excused absent");
        }
        else if(input == "late"){
            db.InsertAttendance(students.at(i).firstName, students.at(i).lastName, input, "5/15/2025", "late");
        }
        else if(input == "return"){
            printMainMenu();
        }
        else{
            cout<<"Please enter one of the listed options exactly in all lowercase!"<<endl;
            printTakeAttendanceMenu();
        }
    }
    
    cout<<endl;
    cout<<"Attendance done!"<<endl;
    cout<<endl;
    
    printMainMenu();
}

void printViewAttendanceMenu(){
    // Print out all students, then options to organize them by name, attendance (From On-time to late or from Late to On-Time), or custom order
    string input;
    cout << "[PLACEHOLDER ATTENDANCE DATA]" << endl;
    for(int i = 0; i < students.size(); i++){
        cout << i + 1 << ": " << students[i].firstName << " " << students[i].lastName << endl;
        cout << "How many class days On Time: " << students[i].onTimeFrequency << endl;
        cout << "How many class days Absent (Excused and Inexcused): " << students[i].absentFrequency << endl;
        cout << "How many class days Late: " << students[i].lateFrequency << endl;
        cout << endl;
    }
    cout << "What would you like to do with this data?" << endl;
    cout << "[1] - Sort by Name" << endl;
    cout << "[2] - Sort by On-Time First" << endl;
    cout << "[3] - Sort by Absent First" << endl;
    cout << "[4] - Sort by Late First" << endl;
    cout << "[5] - View Past Records" << endl;
    cout << "[6] - Select Another Course" << endl;
    cout << "[7] - Return to Main Menu" << endl;
    cin>>input;
    if(input == "1"){
        cout << "Sorting by name" << endl;
    }
    else if(input == "2"){
        cout << "Sorting by on-time first" << endl;
    }
    else if(input == "3"){
        cout << "Sorting by absent first" << endl;
    }
    else if(input == "4"){
        cout << "Sorting by late first" << endl;
    }
    else if(input == "5"){
        cout << "Viewing past records" << endl;
    }
    else if(input == "6"){
        cout << "Selecting another course" << endl;
    }
    else if(input == "7"){
        printMainMenu();
    }
    else{
        cout<<"Please enter a valid number!"<<endl;
        printViewAttendanceMenu();
    }
}

void enrollNewStudent(){
    cout << "Please add the first name, last name, and the course name of the student you want to add:" << endl;
    string firstName;
    string lastName;
    string courseName;
    cout << "First Name: "; cin >> firstName;
    cout << "Last Name: "; cin >> lastName;
    while(true){
        cout << "Course Name: "; cin >> courseName;
        if(courseName != "Software_Development"){
            cout << "Invalid Course Name! Please try again." << endl;
        } else {
            break;
        }
    }
    Student newStudent = constructStudent(firstName, lastName, 0, 0, 0, courseName);
    students.push_back(newStudent);
    cout << newStudent.firstName << " " << newStudent.lastName << " successfully enrolled into " << newStudent.courseName << "!" << endl;
    cout << "----------" << endl;
    printMainMenu();
}

Student constructStudent(string name, string surname, int onTimeNum, int absentNum, int lateNum, string course){
    Student stu;
    stu.firstName = name;
    stu.lastName = surname;
    stu.onTimeFrequency = onTimeNum;
    stu.absentFrequency = absentNum;
    stu.lateFrequency = lateNum;
    stu.courseName = course;

    return stu;
}
