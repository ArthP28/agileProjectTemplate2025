#include <iostream>
using namespace std;

void printMainMenu();

int main()
{
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
    
    if(input == '1'){
        
    }
    else if(input == '2'){
        
    }
    else{
        //clrscr();
        cout<<"Please enter a valid number!"<<endl;
        printMainMenu();
    }
}
