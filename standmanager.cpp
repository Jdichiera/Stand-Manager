#include "standmanager.h"






//This function will display the main menu
int displayMenu(std::list<Stand> &standCollection, std::string fileName){
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
                checkOutStand(standCollection);
                break;
            case 2 :
                checkInStand(standCollection);
                break;
            case 3 :
                standStatus(standCollection);
                break;
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
                quitProgram(standCollection, fileName);
                //std::cout << "Quitting Program" << std::endl;
                return 0;
                break;
            default :
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
        displayMenu(standCollection, fileName);
};

//Allows user to check out a stand.
void checkOutStand(std::list<Stand> &standCollection){
    int inventoryNumber;
    
    clearScreen();
    std::cout << "--== Check Out Stand ==--" << std::endl;
    std::cout << "Available stands : " << std::endl;
    
        displayInventory(standCollection, "available");
        std::cout << "Enter the inventory number of the stand you want to check out." 
                    << "\n(Enter -1 to return to menu)" << std::endl;
        std::cin >> inventoryNumber;

        if(inventoryNumber == -1){
            std::cout << "Returning to the main menu ..." << std::endl;
            pause();
        }else{
            if(validateInventoryNumber(standCollection, inventoryNumber)){
                for(Stand &stand : standCollection){
                    if(inventoryNumber == stand.getInventoryNumber()){
                        if(!stand.getCheckedOut()){
                            std::cout << "Checking out stand" << std::endl;
                            //stand.setCheckedOut(true);
                            stand.setCheckedOut(true);
                        }else{
                            std::cout << "Stand already checked out" << std::endl;
                        }
                    }
                }
            }
        pause();
    }
};

//Allows users to check in a stand that has been checked out.
void checkInStand(std::list<Stand> &standCollection){
    int inventoryNumber;
    clearScreen();
    
    std::cout << "--== Check In Stand ==--" << std::endl;
    std::cout << "Stands currently checked out:" << std::endl;
    
    displayInventory(standCollection, "checkedout");
    
    std::cout << "Enter the inventory number of the stand you want to check out." 
                << "\n(Enter -1 to return to menu)" << std::endl;
    std::cin >> inventoryNumber;
    if(inventoryNumber < 0){
        std::cout << "Returning to the main menu ..." << std::endl;
    }else{
        if(validateInventoryNumber(standCollection, inventoryNumber)){
            for(Stand &stand : standCollection){
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
    }
};

//Displays the status of a stand located by inventory number
void standStatus(std::list<Stand> &standCollection){
    int inventoryNumber;
    clearScreen();
    
    std::cout << "What stand do you want to view?" << std::endl;
    displayInventory(standCollection, "all");
    std::cin >> inventoryNumber;
    if(validateInventoryNumber(standCollection, inventoryNumber)){
        for(Stand stand : standCollection){
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
};

//Runs a report of the stands in inventory.
void runReport(std::list<Stand> &standCollection){
    clearScreen();
    
    std::cout << "--== Stand Inventory Report ==--" << std::endl;
    std::cout << std::setw(10) << "Inv#"
                << std::setw(10) << "Cost" 
                << std::setw(10) << "Out" 
                << std::setw(10) << "Income" << std::endl;
    for(Stand stand : standCollection){
        std::cout << std::setw(10) << std::right <<  stand.getInventoryNumber() 
                    << std::setw(10) << stand.getCost() 
                    << std::setw(10) << stand.getCheckedOut() 
                    << std::setw(10) << std::fixed << std::setprecision(2) 
                    << stand.getIncome() << std::endl;
    }
    std::cout << std:: endl << "--== End Report ==--" << std::endl;
    pause();
};

//Adds a stand to the stand inventory
void addStand(std::list<Stand> &standCollection){
    clearScreen();
    std::cout << "--== Add Stand to Inventory ==--" << std::endl;
    displayInventory(standCollection, "all");
    int invNumber = 0;
    int standCost = 0;
    std::string description = "";
    
    std::cout << "Please enter inventory number: ";
    std::cin >> invNumber;
    if(validateInventoryNumber(standCollection, invNumber)){
        std::cout << "Stand already exists, returning to menu ..." << std::endl;
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
};
    
//Remove a stand from the inventory
void removeStand(std::list<Stand> &standCollection){
    clearScreen();
    std::cout << "--== Remove Stand from Inventory ==--" << std::endl;
    displayInventory(standCollection, "all");
    
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
};

//Quits the program
void quitProgram(std::list<Stand> &standCollection, std::string fileName){
    //clearScreen();
    std::cout << "--== Quit Program ==--" << std::endl;
    
    std::string decision = "";
    std::cout << "Do you want to quit?" << std::endl;
    std::cin >> decision;
    if(decision == "y"){
        save(standCollection, fileName);
    }
};

//Saves the inventory to a text file
void save(std::list<Stand> standCollection, std::string fileName){
    //open write file
    std::ofstream writeFile;

    writeFile.open(fileName);
    
    for(Stand stand : standCollection){
        writeFile << stand.getInventoryNumber() << ";" << stand.getCost() << ";" 
                    << stand.getCheckedOut() << ";" << stand.getIncome() << ";"
                    << stand.getDescription() << std::endl;
    }
    writeFile.close();
};

//Loads the inventory text file into a new stand collection
void load(std::string fileName, std::list<Stand> &standCollection){
    std::cout << "loading" << std::endl;
    Stand stand;
    std::ifstream file;
    std::string line;
    
    file.open(fileName);
    while(std::getline(file, line)){
        int recordLength = 5;
        int i = 0;
        
        int inventoryNumber;
        int cost;
        bool checkedOut;
        double income;
        std::string description;
        
        std::size_t pos = 0;
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

//Displays the inventory based on the input flag : all, checkedOut, checkedIn
void displayInventory(std::list<Stand> &standCollection, std::string type){
    std::list<Stand> stands;
        
    if(type == "checkedout"){
        for(Stand stand : standCollection){
            if(stand.getCheckedOut() == true){
                stands.push_back(stand);
            }
        }
    }else if(type == "available"){
        for(Stand stand : standCollection){
            if(stand.getCheckedOut() == false){
                stands.push_back(stand);
            }
        }
    }else if (type == "all"){
        stands = standCollection;
    }
    
    for (Stand stand : stands){
        std::cout << "Inventory# : " << stand.getInventoryNumber() << std::endl;
    }
};

//Helper function that validates an inventory number
bool validateInventoryNumber(std::list<Stand> &standCollection, int searchNumber){
    for(Stand stand : standCollection){
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