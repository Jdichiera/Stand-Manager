/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   standmanager.h
 * Author: udichje
 *
 * Created on March 6, 2017, 8:26 AM
 */

#ifndef STANDMANAGER_H
#define STANDMANAGER_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <sstream>
#include <stdlib.h>

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
void load(std::string filename);
void clearScreen();
void pause();
bool validateInventoryNumber(int searchNumber);
//std::list<Stand> getCollectionSubset(std::string type);
void displayInventory(std::string type);

#endif /* STANDMANAGER_H */

