#pragma once

class Item {
    public:
        Item();
        Item(std::string name);
        bool isAvailable();
        void takeStock(int amount);
        void addStock(int amount);
        bool isItemInInventory(std::string name);
        std::string getName();
        void getStock(std::string name);
        std::string name;
        int price;
        int stock; // The amount of units available
};