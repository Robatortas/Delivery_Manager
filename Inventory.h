#pragma once
#include <vector>
#include "Item.h"

class Inventory {
    public:
        Inventory();
        void fillInventory();
        void addToInventory();
        void takeFromInventory(int quantity);
    private:
        std::vector<Item> inventory; 
};