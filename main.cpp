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
#include <fstream>
#include <sstream>
/*
 * 
 */

//Cake stand class
class Stand{
public:
    int inventoryNumber;
    int cost;
    Stand();
    ~Stand(){};
    int getInventoryNumber(){
        return inventoryNumber;
    }
    int getCost(){
        return cost;
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
}

//Function declarations
void displayMenu( );
//void checkOutStand(std::map<Stand, int> standMap);
//void checkInStand(std::map<Stand, int > standMap);
//void standStatus(std::map<Stand, int> standMap);
void runReport();
void addStand();
void removeStand();
int quitProgram();
void save();
void load();
bool findStand(int searchNumber);

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
void runReport(){
    std::cout << "Run Report Function" << std::endl;
    std::cout << std:: endl << "--== Stand Inventory Report ==--" << std::endl;
    for(auto stand : standCollection){
        std::cout << "Inventory #: " << stand.inventoryNumber << std::endl;
        std::cout << "Cost : $" << stand.cost << std::endl;
        std::cout << "-----" << std::endl;
    }
    std::cout << std:: endl << "--== End Report ==--" << std::endl;
    
    displayMenu();
};
bool findStand(int searchNumber){
    std::cout << "Find Stand Function" << std::endl;
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
    std::cout << "Add Stand Function" << std::endl;
    std::cout << "Please enter inventory number: ";
    std::cin >> invNumber;
    if(findStand(invNumber)){
        std::cout << "Stand already exists, returning to menu ..." << std::endl;
        displayMenu();
    }
    std::cout << "Please enter stand cost : $";
    std::cin >> standCost;
    Stand stand;
    stand.setInventoryNumber(invNumber);
    stand.setCost(standCost);
    standCollection.push_back(stand);
    displayMenu();
}
    
    
   
void removeStand(){
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
    std::cout << "Save Function" << std::endl;
    
    //open write file
    std::ofstream writeFile;

    writeFile.open(filename);
    
    for(auto stand : standCollection){
        writeFile << stand.inventoryNumber << ";" << stand.cost << ";" << std::endl;
    }
    writeFile.close();
};

void load(){
    std::string standArray[1];
    std::cout << "loading" << std::endl;
    Stand stand;
    std::ifstream file;
    std::string line;
    
    
    
    file.open(filename);
    while(std::getline(file, line)){
        int recordLength = 2;
        int i = 0;
        size_t pos = 0;
        std::string tempArray[1];
        std::string delimiter = ";";
        
        while(((pos = line.find(delimiter)) != std::string::npos) && (i < recordLength)){
            tempArray[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }
        stand.setInventoryNumber(std::stoi(tempArray[0]));
        stand.setCost(std::stoi(tempArray[1]));
        standCollection.push_back((stand));
    }
    file.close();
};

