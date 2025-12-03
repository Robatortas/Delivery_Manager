#include <iostream>
#include "Item.h"

Item::Item(std::string name) : name(name) {}

std::string Item::getName() {return this->name;}

bool Item::isAvailable() {
    if(this->stock >= 0) return true;
    return false;
}

// Take a certain amount of items from the stock if supported
void Item::takeStock(int amount) {
    if(isAvailable()) this->stock -= amount;
    else std::cerr << "Our stock isn't big enough for your amount !"
}

void Item::addStock(int amount) {this->stock += amount}