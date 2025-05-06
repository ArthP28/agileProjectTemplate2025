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
void printTakeAttendenceMenu();
void printViewAttendenceMenu();

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
        printTakeAttendenceMenu();
    }
    else if(input == "2"){
        printViewAttendenceMenu();
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

void printViewAttendenceMenu(){
    
}
