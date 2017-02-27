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
#include <map>
/*
 * 
 */

class Stand;

//Function declarations
void displayMenu(std::map<Stand, int> standMap);
//void checkOutStand(std::map<Stand, int> standMap);
//void checkInStand(std::map<Stand, int > standMap);
//void standStatus(std::map<Stand, int> standMap);
void runReport(std::map<Stand, int> standMap);
void addStand(std::map<Stand, int> standMap);
//void removeStand(std::map<Stand, int> standMap);
int quitProgram(std::map<Stand, int> standMap);



int main(int argc, char** argv) {
    std::map<Stand, int> standMap;
    displayMenu(standMap);
    //return 0;
}

void displayMenu(std::map<Stand, int> standMap){
    int menuSelection = 0;
    std::cout << "--== Main Menu ==--" << std::endl;
//    std::cout << "1. Check Out Stand" << std::endl;
//    std::cout << "2. Check In Stand" << std::endl;
//    std::cout << "3. Stand Status" << std::endl;
    std::cout << "4. Stand Report" << std::endl;
    std::cout << "5. Add Stand" << std::endl;
    //std::cout << "6. RemoveStand" << std::endl;
    std::cout << "7. Quit Stand Manager" << std::endl;
    std::cout << "Please make a selection" << std::endl;
    std::cin >> menuSelection;
    switch(menuSelection){
//        case 1 :
//            checkOutStand(standMap);
//            break;
//        case 2 :
//            checkInStand(standMap);
//            break;
//        case 3 :
//            standStatus(standMap);
//            break;
        case 4 :
            runReport(standMap);
            break;
        case 5 :
            addStand(standMap);
            break;
//        case 6 :
//            removeStand(standMap);
//            break;
        case 7 :
            quitProgram(standMap);
            break;
        default :
            displayMenu(standMap);
            break;
    }
};

//void checkOutStand(std::map<Stand, int> standMap){
//    std::cout << "Check Out Stand Function" << std::endl;
//    displayMenu(standMap);
//};
//void checkInStand(std::map<Stand, int> standMap){
//    std::cout << "Check In Stand Function" << std::endl;
//    displayMenu(standMap);
//};
//void standStatus(std::map<Stand, int> standMap){
//    std::cout << "Stand Status Function" << std::endl;
//    displayMenu(standMap);
//};
void runReport(std::map<Stand, int> standMap){
    std::cout << "Run Report Function" << std::endl;
//    for(auto i : standMap){
//        std::cout << i->first << " " << i.second.first << " " << i.second.second << std::endl;
//    }
    displayMenu(standMap);
};
void addStand(std::map<Stand, int> standMap){
    int invNumber = 0;
    std::cout << "Add Stand Function" << std::endl;
    std::cout << "Please enter inventory number: ";
    std::cin >> invNumber;
    Stand stand(int invNumber);
    standMap.insert(stand, invNumber);
    displayMenu(standMap);
};
//void removeStand(std::map<Stand, int> standMap){
//    std::cout << "Remove Stand Function" << std::endl;
//    displayMenu(standMap);
//};
int quitProgram(std::map<Stand, int> standMap){
    std::string decision = "";
    std::cout << "Do you want to quit?" << std::endl;
    std::cin >> decision;
    if(decision == "y"){
        return 0;
    } else{
        displayMenu(standMap);
    }
};

//Cake stand class
class Stand{
public:
    int inventoryNumber;
    Stand();
    Stand(int);
    ~Stand(){
        std::cout << "Deleting stand " << getInventoryNumber() << std::endl;
    }
    int getInventoryNumber(){
        return inventoryNumber;
    }
};

Stand::Stand(int invNumber){
    inventoryNumber = invNumber;
    std::cout << "Creating stand " << getInventoryNumber() << std::endl;
}
    

