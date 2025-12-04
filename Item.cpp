#include <iostream>
#include <fstream>
#include "Item.h"

Item::Item(std::string name) : name(name) {}

std::string Item::getName() {return this->name;}

bool Item::isAvailable() {
    if(this->stock >= 0) return true;
    return false;
}

// Finds the item in the inventory through a name based queried search
bool Item::isItemInInventory(std::string name) {
    std::ifstream file;
    file.open("Inventario_C.csv", std::ios_base::in);
    if(!file.is_open()) std::cerr << "Unable to open file !"; return false;
    std::string line = "";
    int lineCount = 0;

    while (std::getline(file, line)) {
        lineCount++;
        if(line.find(name) != std::string::npos) {
            std::cout << "Line: " << line << " contains " << name << std::endl;
            return true;
        } else return false;
    }

    return false;
}

void Item::getStock(std::string name) {
    std::ofstream file;
    file.open("Inventario_C.csv", std::ios_base::out);
    if(!file.is_open()) std::cerr << "Unable to open file !"; return;
    if(isItemInInventory(name)) std::cout << "IT WORKS !";
}

// Take a certain amount of items from the stock if supported
void Item::takeStock(int amount) {
    if(isAvailable()) this->stock -= amount;
    else std::cerr << "Our stock isn't big enough for your amount !";
}

void Item::addStock(int amount) {this->stock += amount;}