#include "stand.h"

Stand::Stand(){
    inventoryNumber = 0;
    cost = 0.00;
    checkedOut = false;
    description = "";
    income = 0.00;
}
void Stand::setCheckedOut(bool status){
    checkedOut = status;
}
void Stand::setInventoryNumber(int invNumber){
    inventoryNumber = invNumber;
}
void Stand::setCost(double standcost){
    cost = standcost;
}
void Stand::setDescription(std::string newDescription){
    description = newDescription;
}
void Stand::setIncome(double amount){
    income += amount;
}
int Stand::getInventoryNumber(){
    return inventoryNumber;
}
double Stand::getCost(){
    return cost;
}
bool Stand::getCheckedOut(){
    return checkedOut;
}
std::string Stand::getDescription(){
    return description;
}
double Stand::getIncome(){
    return income;
}