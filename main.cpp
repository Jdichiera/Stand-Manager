/* 
 * Author: Jeramy Dichiera
 * Created on February 12, 2017, 8:30 AM
 * File:   main.cpp
 *
 * Purpose: A simple console application that allows you to manage wedding
 * cake stands.
 * 
 * Input:
 * 
 * Output:
 * 
 * Exceptions:
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

//Function declarations
void displayMenu();
void checkOutStand();
void checkInStand();
void standStatus();
void runReport();
void addStand();
void removeStand();
int quitProgram();

int main(int argc, char** argv) {
    displayMenu();
    //return 0;
}

void displayMenu(){
    int menuSelection = 0;
    cout << "--== Main Menu ==--" << endl;
    cout << "1. Check Out Stand" << endl;
    cout << "2. Check In Stand" << endl;
    cout << "3. Stand Status" << endl;
    cout << "4. Stand Report" << endl;
    cout << "5. Add Stand" << endl;
    cout << "6. RemoveStand" << endl;
    cout << "7. Quit Stand Manager" << endl;
    cout << "Please make a selection" << endl;
    cin >> menuSelection;
    switch(menuSelection){
        case 1 :
            checkOutStand();
            break;
        case 2 :
            checkInStand();
            break;
        case 3 :
            standStatus();
            break;
        case 4 :
            runReport();
            break;
        case 5 :
            addStand();
            break;
        case 6 :
            removeStand();
            break;
        case 7 :
            quitProgram();
            break;
        default :
            displayMenu();
            break;
    }
};

void checkOutStand(){
    cout << "Check Out Stand Function" << endl;
    displayMenu();
};
void checkInStand(){
    cout << "Check In Stand Function" << endl;
    displayMenu();
};
void standStatus(){
    cout << "Stand Status Function" << endl;
    displayMenu();
};
void runReport(){
    cout << "Run Report Function" << endl;
    displayMenu();
};
void addStand(){
    cout << "Add Stand Function" << endl;
    displayMenu();
};
void removeStand(){
    cout << "Remove Stand Function" << endl;
    displayMenu();
};
int quitProgram(){
    string decision = "";
    cout << "Do you want to quit?" << endl;
    cin >> decision;
    if(decision == "y"){
        return 0;
    } else{
        displayMenu();
    }
};
