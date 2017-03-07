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

#include "stand.h"

//Function declarations
int displayMenu(std::list<Stand> &standCollection, std::string fileName);
void checkOutStand(std::list<Stand> &standCollection);
void checkInStand(std::list<Stand> &standCollection);
void standStatus(std::list<Stand> &standCollection);
void runReport(std::list<Stand> &standCollection);
void addStand(std::list<Stand> &standCollection);
void removeStand(std::list<Stand> &standCollection);
void quitProgram(std::list<Stand> &standCollection, std::string fileName);

void save(std::list<Stand> &standCollection, std::string fileName);
void load(std::string fileName, std::list<Stand> &standCollection);
void clearScreen();
void pause();
bool validateInventoryNumber(std::list<Stand> &standCollection, int searchNumber);
void displayInventory(std::list<Stand> &standCollection, std::string type);
#endif /* STANDMANAGER_H */

