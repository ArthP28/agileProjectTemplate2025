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
    
}

void printViewAttendenceMenu(){
    
}
