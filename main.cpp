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

int main(int argc, char** argv) {
    std::list<Stand> standCollection;
    std::string fileName = "inventory.txt";
    
    load(fileName, standCollection);
    displayMenu(standCollection, fileName);
}

