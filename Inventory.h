#pragma once
#include <vector>
#include "Inventory.h"
#include "Item.h"

class Inventory {
    public:
        Inventory();
        void fillInventory();
        void addToInventory(std::string name, int quantity);
        void takeFromInventory(std::string name, int quantity);
        std::vector<Item> getInventoryList();
    private:
        std::vector<Item> inventory; 
};