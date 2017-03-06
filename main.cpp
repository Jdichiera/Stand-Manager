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

#include "standmanager.h"

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




//Global variables



int main(int argc, char** argv) {
    std::list<Stand> standCollection;
    std::string filename = "inventory.txt";
    
    load(fileName);
    displayMenu();
}

