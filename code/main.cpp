// For Sys(Clear) which is currently experimental
#ifdef _WIN32
#include <stdlib.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
using namespace std;

void printMainMenu();
void printTakeAttendanceMenu();
void printViewAttendanceMenu();

int main()
{
    //system("cls");
    cout<<"Agile Project"<<endl;
    
    printMainMenu();
    
    return 0;
}

void printMainMenu(){
    
    string input;
    cout<<"Please type number cooresponding to the option you want: "<<endl;
    cout<<"1: Take attendance"<<endl;
    cout<<"2: View attendance"<<endl;
    
    cin>>input;
    
    if(input == "1"){
        printTakeAttendanceMenu();
    }
    else if(input == "2"){
        printViewAttendanceMenu();
    }
    else{

        cout<<"Please enter a valid number!"<<endl;
        printMainMenu();
    }
}

void printTakeAttendenceMenu(){
    string input;
    
    cout<<"For each name type one of the following options: "<<endl;
    cout<<" present"<<endl;
    cout<<" excused absent"<<endl;
    cout<<" not excused absent"<<endl;
    cout<<" late"<<endl;
    
    cin>>input;
    
    if(input == "present"){
        
    }
    else if(input == "excused absent"){
        
    }
    else if(input == "not excused absent"){
        
    }
    else if(input == "late"){
        
    }
    else{
        cout<<"Please enter one of the listed options exactly in all lowercase!"<<endl;
        printTakeAttendenceMenu();
    }
}

void printViewAttendanceMenu(){
    // Print out all students, then options to organize them by name, attendance (From On-time to late or from Late to On-Time), or custom order
    string input;
    cout << "[PLACEHOLDER ATTENDANCE DATA]" << endl;
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
