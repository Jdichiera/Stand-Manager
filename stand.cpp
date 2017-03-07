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