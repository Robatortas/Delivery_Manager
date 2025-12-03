#pragma once

class Item {
    public:
        Item(std::string name);
        bool isAvailable();
        void takeStock(int amount);
        void addStock(int amount);
    private:
        std::string name;
        int stock; // The amount of units available
};