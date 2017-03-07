/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stand.h
 * Author: udichje
 *
 * Created on March 6, 2017, 9:09 AM
 */
#include "standmanager.h"
#ifndef STAND_H
#define STAND_H

//Cake stand class
class Stand{
public:
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
    
    void setCheckedOut(bool status);
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
#endif /* STAND_H */

