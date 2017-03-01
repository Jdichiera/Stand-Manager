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
#include <iomanip>
#include <list>
#include <fstream>
#include <sstream>
#include <stdlib.h>

/*
 * 
 */

//Cake stand class
class Stand{
public:
    int inventoryNumber;
    int cost;
    bool checkedOut;
    Stand();
    ~Stand(){};
    int getInventoryNumber(){
        return inventoryNumber;
    }
    int getCost(){
        return cost;
    }
    bool getCheckedOut(){
        return checkedOut;
    }
    bool setCheckedOut(bool status){
        checkedOut = status;
    }
    void setInventoryNumber(int invNumber){
        inventoryNumber = invNumber;
    }
    void setCost(int standcost){
        cost = standcost;
    }
};
Stand::Stand(){
    inventoryNumber = 0;
    cost = 0;
    checkedOut = false;
}

//Function declarations
void displayMenu();
void checkOutStand();
void checkInStand();
void standStatus();
void runReport();
void addStand();
void removeStand();
int quitProgram();
bool validateInventoryNumber(int searchNumber);
void save();
void load();
void clearScreen();
void pause();
std::list<Stand> getCollectionSubset(std::string type);


//Global
//std::ofstream file;
std::list<Stand> standCollection;
std::string filename = "inventory.txt";


int main(int argc, char** argv) {
    
    load();
    
    //file.open("inventory.txt");
    
    //std::map<Stand, int> standMap;
    
    displayMenu();
    //return 0;
}
void displayMenu(){
    clearScreen();
    int menuSelection = 0;
    std::cout << "--== Main Menu ==--" << std::endl;
    std::cout << "1. Check Out Stand" << std::endl;
    std::cout << "2. Check In Stand" << std::endl;
    std::cout << "3. Stand Status" << std::endl;
    std::cout << "4. Stand Report" << std::endl;
    std::cout << "5. Add Stand" << std::endl;
    std::cout << "6. RemoveStand" << std::endl;
    std::cout << "7. Quit Stand Manager" << std::endl;
    std::cout << "Please make a selection" << std::endl;
    std::cin >> menuSelection;
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
    int inventoryNumber;
    std::list<Stand> availableStands = getCollectionSubset("out");
    clearScreen();
    std::cout << "--== Check Out Stand ==--" << std::endl;
    std::cout << "Available stands : " << std::endl;
//    for(auto stand : standCollection){
//        if(!stand.checkedOut){
//            availableStands.push_back(stand);
//        }
//    }
    if(availableStands.empty()){
        std::cout << "There are no available stands" << std::endl;
        pause();
        displayMenu();
    }else{
        for(auto stand : availableStands){
            std::cout << "Inventory# : " << stand.inventoryNumber << std::endl;
        }
    }
    std::cout << "Enter the inventory number of the stand you want to check out." 
                << "\n(Enter -1 to return to menu)" << std::endl;
    std::cin >> inventoryNumber;
    if(inventoryNumber < 0){
        std::cout << "Returning to the main menu ..." << std::endl;
        pause();
        displayMenu();
    }else{
        if(validateInventoryNumber(inventoryNumber)){
            for(auto& stand : standCollection){
                if(inventoryNumber == stand.inventoryNumber){
                    if(!stand.checkedOut){
                        std::cout << "Checking out stand" << std::endl;
                        stand.checkedOut = true;
                    }else{
                        std::cout << "Stand already checked out" << std::endl;
                    }
                }
            }
        }
    }
    pause();
    displayMenu();
};
void checkInStand(){
    int inventoryNumber;
    std::list<Stand> availableStands = getCollectionSubset("in");
    std::cout << "--== Check In Stand ==--" << std::endl;
    std::cout << "Stands currently checked out:" << std::endl;
    
    if(availableStands.empty()){
        std::cout << "There are no available stands" << std::endl;
        pause();
        displayMenu();
    }else{
        for(auto stand : availableStands){
            std::cout << "Inventory# : " << stand.inventoryNumber << std::endl;
        }
    }
    std::cout << "Enter the inventory number of the stand you want to check out." 
                << "\n(Enter -1 to return to menu)" << std::endl;
    std::cin >> inventoryNumber;
    if(inventoryNumber < 0){
        std::cout << "Returning to the main menu ..." << std::endl;
        //pause();
        displayMenu();
    }else{
        if(validateInventoryNumber(inventoryNumber)){
            for(auto& stand : standCollection){
                if(inventoryNumber == stand.inventoryNumber){
                    if(stand.checkedOut){
                        std::cout << "Checking in stand" << std::endl;
                        stand.checkedOut = false;
                    }else{
                        std::cout << "Stand already checked in" << std::endl;
                    }
                }
            }
        }
    }
    pause();
    displayMenu();
};
void standStatus(){
    int inventoryNumber;
    std::cout << "What stand do you want to view?" << std::endl;
    std::cin >> inventoryNumber;
    if(validateInventoryNumber(inventoryNumber)){
        for(auto& stand : standCollection){
            if(inventoryNumber == stand.inventoryNumber){
                std::cout << "Inventory #: " << stand.inventoryNumber << std::endl;
                std::cout << "Cost : $" << stand.cost << std::endl;
                std::cout << "Checked Out: " << stand.checkedOut << std::endl;
            }
        }
    }else{
                std::cout << "Stand not found" << std::endl;
            }
    pause();
    displayMenu();
};
void runReport(){
    clearScreen();
    std::cout << << "--== Stand Inventory Report ==--" << std::endl;
    std::cout << std::setw(10) << "Inv#"
                << std::setw(10) << "Cost" 
                << std::setw(10) << "Out" << std::endl;
    for(auto stand : standCollection){
        std::cout << std::setw(10) << std::right <<  stand.inventoryNumber 
                    << std::setw(10) <<  stand.cost 
                    << std::setw(10) <<  stand.checkedOut << std::endl;
    }
    std::cout << std:: endl << "--== End Report ==--" << std::endl;
    pause();
    displayMenu();
};
bool validateInventoryNumber(int searchNumber){
    for(auto stand : standCollection){
        if(searchNumber == stand.inventoryNumber){
            std::cout << "same" << searchNumber << " : " << stand.inventoryNumber << std::endl;
            return true;
        };
    };
    return false;  
};
void addStand(){
    int invNumber = 0;
    int standCost = 0;
    bool duplicate = false;
    std::cout << "Please enter inventory number: ";
    std::cin >> invNumber;
    if(validateInventoryNumber(invNumber)){
        std::cout << "Stand already exists, returning to menu ..." << std::endl;
        displayMenu();
    }
    std::cout << "Please enter stand cost : $";
    std::cin >> standCost;
    Stand stand;
    stand.setInventoryNumber(invNumber);
    stand.setCost(standCost);
    standCollection.push_back(stand);
    pause();
    displayMenu();
};
    
    
   
void removeStand(){
    int response = 0;
    std::cout << "Please enter stand to remove: " << std::endl;
    std::cin >> response;
    std::list<Stand>::iterator iterator;
    for(iterator = standCollection.begin(); iterator != standCollection.end(); iterator++){
        if((*iterator).getInventoryNumber() == response){
            standCollection.erase(iterator);
        }
    }
    pause();
    displayMenu();
};
int quitProgram(){
    std::string decision = "";
    std::cout << "Do you want to quit?" << std::endl;
    std::cin >> decision;
    if(decision == "y"){
        save();
        return 0;
    } else{
        displayMenu();
    }
};

void save(){
    //open write file
    std::ofstream writeFile;

    writeFile.open(filename);
    
    for(auto stand : standCollection){
        writeFile << stand.inventoryNumber << ";" << stand.cost << ";" 
                    << stand.checkedOut << ";" << std::endl;
    }
    writeFile.close();
};

void load(){
    std::cout << "loading" << std::endl;
    Stand stand;
    std::ifstream file;
    std::string line;
    
    file.open(filename);
    while(std::getline(file, line)){
        int recordLength = 3;
        int i = 0;
        int inventoryNumber;
        int cost;
        bool checkedOut;
        size_t pos = 0;
        std::string tempArray[2];
        std::string delimiter = ";";
        
        while(((pos = line.find(delimiter)) != std::string::npos) && (i < recordLength)){
            tempArray[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }
        inventoryNumber = std::stoi(tempArray[0]);
        cost = std::stoi(tempArray[1]);
        if(tempArray[2] == "1"){
            checkedOut = true;
        }else{
            checkedOut = false;
        }
        
        stand.setInventoryNumber(inventoryNumber);
        stand.setCost(cost);
        stand.setCheckedOut(checkedOut);
        
        standCollection.push_back((stand));
    }
    file.close();
};

std::list<Stand> getCollectionSubset(std::string type){
    std::list<Stand> subset;
    
    if(type == "out"){
        for(auto stand : standCollection){
            if(!stand.checkedOut){
                subset.push_back(stand);
            }
        }
    }else{
        for(auto stand : standCollection){
            if(stand.checkedOut){
                subset.push_back(stand);
            }
        }
    }
    return subset;
};

void clearScreen(){
    int os;
    #ifdef _WIN32
    std::system("CLS");
    #elif __APPLE__
    std::system("CLEAR");
#endif
}

void pause(){
    std::cout << "Press ENTER to continue" << std::endl;
    #ifdef _WIN32
    std::system("pause");
    #elif __APPLE__
    std::system("read");
#endif
};