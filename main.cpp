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

#include <vector>
#include <cstdlib>
#include <iostream>
#include <list>
/*
 * 
 */

//Cake stand class
class Stand{
public:
    int inventoryNumber;
    Stand();
    //Stand(int);
    //Stand(const Stand &obj);
    ~Stand(){
        //std::cout << "Deleting stand " << getInventoryNumber() << std::endl;
    }
    int getInventoryNumber(){
        return inventoryNumber;
    }
    void setInventoryNumber(int invNumber){
        inventoryNumber = invNumber;
    }
    //private:
      //int *ptr;
};
Stand::Stand(){
    inventoryNumber = 0;
}

//Function declarations
void displayMenu(std::list<Stand> );
//void checkOutStand(std::map<Stand, int> standMap);
//void checkInStand(std::map<Stand, int > standMap);
//void standStatus(std::map<Stand, int> standMap);
void runReport(const std::list<Stand> &);
void addStand(std::list<Stand> );
void removeStand(std::list<Stand> s);
int quitProgram(std::list<Stand> s);



int main(int argc, char** argv) {
    //std::map<Stand, int> standMap;
    std::list<Stand> standCollection;
    displayMenu(standCollection);
    //return 0;
}

void displayMenu(std::list<Stand> standCollection){
    int menuSelection = 0;
    std::cout << "--== Main Menu ==--" << std::endl;
//    std::cout << "1. Check Out Stand" << std::endl;
//    std::cout << "2. Check In Stand" << std::endl;
//    std::cout << "3. Stand Status" << std::endl;
    std::cout << "4. Stand Report" << std::endl;
    std::cout << "5. Add Stand" << std::endl;
    std::cout << "6. RemoveStand" << std::endl;
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
            runReport(standCollection);
            break;
        case 5 :
            addStand(standCollection);
            break;
        case 6 :
            removeStand(standCollection);
            break;
        case 7 :
            quitProgram(standCollection);
            break;
        default :
            displayMenu(standCollection);
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
////};
void runReport(const std::list<Stand> &standCollection){
    std::cout << "Run Report Function" << std::endl;
    for(auto stand : standCollection){
        std::cout << stand.inventoryNumber << std::endl;
    }
//    for(int i = 0; i < standCollection.size(); i++){
//        std::cout << standCollection[i];
//    }
//    for (auto ci = standCollection.begin(); ci != standCollection.end(); ++ci)
//        std::cout << *ci << " ";
    displayMenu(standCollection);
};
void addStand(std::list<Stand> standCollection){
    int invNumber = 0;
    std::cout << "Add Stand Function" << std::endl;
    std::cout << "Please enter inventory number: ";
    std::cin >> invNumber;
    Stand stand;
    stand.setInventoryNumber(invNumber);
    standCollection.push_back(stand);
    displayMenu(standCollection);
   
};
void removeStand(std::list<Stand> standCollection){
    int response = 0;
    std::cout << "Remove Stand Function" << std::endl;
    std::cout << "Please enter stand to remove: " << std::endl;
    std::cin >> response;
    std::list<Stand>::iterator iterator;
    for(iterator = standCollection.begin(); iterator != standCollection.end(); iterator++){
        if((*iterator).getInventoryNumber() == response){
            standCollection.erase(iterator);
        }
    }
    displayMenu(standCollection);
};
int quitProgram(std::list<Stand> standCollection){
    std::string decision = "";
    std::cout << "Do you want to quit?" << std::endl;
    std::cin >> decision;
    if(decision == "y"){
        return 0;
    } else{
        displayMenu(standCollection);
    }
};


