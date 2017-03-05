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
private:
    int inventoryNumber;
    double cost;
    bool checkedOut;
    std::string description;
    double income;
    
public:
    int getInventoryNumber(){
        return inventoryNumber;
    }
    double getCost(){
        return cost;
    }
    bool getCheckedOut(){
        return checkedOut;
    }
    std::string getDescription(){
        return description;
    }
    double getIncome(){
        return income;
    }
    
    void setCheckedOut(bool status){
        checkedOut = status;
    }
    void setInventoryNumber(int invNumber){
        inventoryNumber = invNumber;
    }
    void setCost(double standcost){
        cost = standcost;
    }
    void setDescription(std::string newDescription){
        description = newDescription;
    }
    void setIncome(double amount){
        income += amount;
    }
    
    
    Stand();
    ~Stand(){};
};

Stand::Stand(){
    inventoryNumber = 0;
    cost = 0.00;
    checkedOut = false;
    description = "";
    income = 0.00;
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

void save();
void load();
void clearScreen();
void pause();
bool validateInventoryNumber(int searchNumber);
//std::list<Stand> getCollectionSubset(std::string type);
void displayInventory(std::string type);


//Global variables
std::list<Stand> standCollection;
std::string filename = "inventory.txt";


int main(int argc, char** argv) {
    load();
    displayMenu();
}

//This function will display the main menu
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
    std::cout << "Please make a selection between 1 and 7" << std::endl;
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
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                displayMenu();
                break;
        }

};

//Allows user to check out a stand.
void checkOutStand(){
    int inventoryNumber;
    //std::list<Stand> availableStands = getCollectionSubset("out");
    
    clearScreen();
    std::cout << "--== Check Out Stand ==--" << std::endl;
    std::cout << "Available stands : " << std::endl;
    
//    if(availableStands.empty()){
//        std::cout << "There are no available stands" << std::endl;
//        pause();
//        displayMenu();
//    }else{
        displayInventory("in");
        std::cout << "Enter the inventory number of the stand you want to check out." 
                    << "\n(Enter -1 to return to menu)" << std::endl;
        std::cin >> inventoryNumber;

        if(inventoryNumber == -1){
            std::cout << "Returning to the main menu ..." << std::endl;
            pause();
            displayMenu();
        }else{
            if(validateInventoryNumber(inventoryNumber)){
                for(auto& stand : standCollection){
                    if(inventoryNumber == stand.getInventoryNumber()){
                        if(!stand.getCheckedOut()){
                            std::cout << "Checking out stand" << std::endl;
                            stand.setCheckedOut(true);
                        }else{
                            std::cout << "Stand already checked out" << std::endl;
                        }
                    }
                }
            }
        pause();
        displayMenu();
        }
    //}
};

//Allows users to check in a stand that has been checked out.
void checkInStand(){
    int inventoryNumber;
    //std::list<Stand> availableStands = getCollectionSubset("in");
    clearScreen();
    
    std::cout << "--== Check In Stand ==--" << std::endl;
    std::cout << "Stands currently checked out:" << std::endl;
    
//    if(availableStands.empty()){
//        std::cout << "There are no available stands" << std::endl;
//        pause();
//        displayMenu();
//    }else{
//        for(auto stand : availableStands){
//            std::cout << "Inventory# : " << stand.getInventoryNumber() << std::endl;
//        }
        displayInventory("out");
    
    std::cout << "Enter the inventory number of the stand you want to check out." 
                << "\n(Enter -1 to return to menu)" << std::endl;
    std::cin >> inventoryNumber;
    if(inventoryNumber < 0){
        std::cout << "Returning to the main menu ..." << std::endl;
        displayMenu();
    }else{
        if(validateInventoryNumber(inventoryNumber)){
            for(auto& stand : standCollection){
                if(inventoryNumber == stand.getInventoryNumber()){
                    if(stand.getCheckedOut()){
                        double income = 0;
                        std::cout << "Income generated: $" << std::endl;
                        std::cin >> income;
                        std::cout << "Checking in stand" << std::endl;
                        stand.setIncome(income);
                        stand.setCheckedOut(false);
                    }else{
                        std::cout << "Stand already checked in" << std::endl;
                    }
                }
            }
        }
    pause();
    displayMenu();
    }
    
   // }
};

//Displays the status of a stand located by inventory number
void standStatus(){
    int inventoryNumber;
    clearScreen();
    
    std::cout << "What stand do you want to view?" << std::endl;
    std::cin >> inventoryNumber;
    if(validateInventoryNumber(inventoryNumber)){
        for(auto& stand : standCollection){
            if(inventoryNumber == stand.getInventoryNumber()){
                std::cout << "Inventory #: " << stand.getInventoryNumber() << std::endl;
                std::cout << "Cost : $" << std::fixed << std::setprecision(2) << stand.getCost() << std::endl;
                std::cout << "Checked Out : " << stand.getCheckedOut() << std::endl;
                std::cout << "Description : " << stand.getDescription() << std::endl;
                std::cout << "Income Generated : $" << std::fixed << std::setprecision(2) << stand.getIncome() << std::endl;
            }
        }
    }else{
                std::cout << "Stand not found" << std::endl;
            }
    pause();
    displayMenu();
};

//Runs a report of the stands in inventory.
void runReport(){
    clearScreen();
    
    std::cout << "--== Stand Inventory Report ==--" << std::endl;
    std::cout << std::setw(10) << "Inv#"
                << std::setw(10) << "Cost" 
                << std::setw(10) << "Out" 
                << std::setw(10) << "Income" << std::endl;
    for(auto stand : standCollection){
        std::cout << std::setw(10) << std::right <<  stand.getInventoryNumber() 
                    << std::setw(10) << stand.getCost() 
                    << std::setw(10) << stand.getCheckedOut() 
                    << std::setw(10) << std::fixed << std::setprecision(2) 
                    << stand.getIncome() << std::endl;
    }
    std::cout << std:: endl << "--== End Report ==--" << std::endl;
    pause();
    displayMenu();
};

//Adds a stand to the stand inventory
void addStand(){
    clearScreen();
    std::cout << "--== Add Stand to Inventory ==--" << std::endl;
    int invNumber = 0;
    int standCost = 0;
    std::string description = "";
    
    std::cout << "Please enter inventory number: ";
    std::cin >> invNumber;
    if(validateInventoryNumber(invNumber)){
        std::cout << "Stand already exists, returning to menu ..." << std::endl;
        displayMenu();
    }
    std::cout << "Please enter stand cost : $";
    std::cin >> standCost;
    std::cout << "Please enter stand description (limit 15 characters): " << std::endl;
    std::cin >> description;
    
    Stand stand;
    stand.setInventoryNumber(invNumber);
    stand.setCost(standCost);
    stand.setDescription(description);
    
    standCollection.push_back(stand);
    
    pause();
    displayMenu();
};
    
//Remove a stand from the inventory
void removeStand(){
    clearScreen();
    std::cout << "--== Remove Stand from Inventory ==--" << std::endl;
    
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

//Quits the program
int quitProgram(){
    //clearScreen();
    std::cout << "--== Quit Program ==--" << std::endl;
    
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

//Saves the inventory to a text file
void save(){
    //open write file
    std::ofstream writeFile;

    writeFile.open(filename);
    
    for(auto stand : standCollection){
        writeFile << stand.getInventoryNumber() << ";" << stand.getCost() << ";" 
                    << stand.getCheckedOut() << ";" << stand.getIncome() << ";"
                    << stand.getDescription() << std::endl;
    }
    writeFile.close();
};

//Loads the inventory text file into a new stand collection
void load(){
    std::cout << "loading" << std::endl;
    Stand stand;
    std::ifstream file;
    std::string line;
    
    file.open(filename);
    while(std::getline(file, line)){
        int recordLength = 5;
        int i = 0;
        
        int inventoryNumber;
        int cost;
        bool checkedOut;
        double income;
        std::string description;
        
        size_t pos = 0;
        std::string tempArray[4];
        std::string delimiter = ";";
        
        while(((pos = line.find(delimiter)) != std::string::npos) && (i < recordLength)){
            tempArray[i] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            i++;
        }
        inventoryNumber = std::stoi(tempArray[0]);
        cost = std::stod(tempArray[1]);
        if(tempArray[2] == "1"){
            checkedOut = true;
        }else{
            checkedOut = false;
        }
        income = std::stod(tempArray[3]);
        description = tempArray[4];
        
        stand.setInventoryNumber(inventoryNumber);
        stand.setCost(cost);
        stand.setCheckedOut(checkedOut);
        stand.setIncome(income);
        stand.setDescription(description);
        
        standCollection.push_back((stand));
    }
    file.close();
};

//Gets a subset of the collection. User can pass in whether or not they want a
//set of stands that are checked out or stands that are checked in
//std::list<Stand> getCollectionSubset(std::string type){
//    std::list<Stand> subset;
//    
//    
//    }else if(type == "in") {
//        for(auto stand : standCollection){
//            if(stand.getCheckedOut()){
//                subset.push_back(stand);
//            }
//        }
//    }
//    return subset;
//};

//Displays the inventory based on the input flag : all, checkedOut, checkedIn
void displayInventory(std::string type){
    std::cout << "display Inv" << std::endl;
    std::list<Stand> stands;
        
    if(type == "out"){
        std::cout << "out" << std::endl;
        for(auto stand : standCollection){
            if(!stand.getCheckedOut()){
                stands.push_back(stand);
            }
        }
    }else if(type == "in"){
        std::cout << "in" << std::endl;
        for(auto stand : standCollection){
            if(stand.getCheckedOut()){
                stands.push_back(stand);
            }
        }
    }else{
        std::cout << "def" << std::endl;
        stands = standCollection;
    }
    std::cout << stands.size() << std::endl;
    for (Stand stand : stands){
        std::cout << "Inventory# : " << stand.getInventoryNumber() << std::endl;
    }

    
};

//Helper function that validates an inventory number
bool validateInventoryNumber(int searchNumber){
    for(auto stand : standCollection){
        if(searchNumber == stand.getInventoryNumber()){
            return true;
        };
    };
    return false;  
};

//Detects the users OS and then clears the screen
void clearScreen(){
    #ifdef _WIN32
    std::system("CLS");
    #elif __APPLE__
    std::system("CLEAR");
#endif
};

//Detects the users OS and sends the appropriate pause command.
void pause(){
    std::cout << "Press ENTER to continue" << std::endl;
    #ifdef _WIN32
    std::system("pause");
    #elif __APPLE__
    std::system("read");
#endif
};