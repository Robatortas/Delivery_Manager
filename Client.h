#pragma once
#include <vector>
#include "Item.h"

class Order;

class Client {
    public:
        Client(std::string name, std::string location);
        void setOrder(Order& order);
        Order getOrder() const;
        void setLocation();
    private:
        std::string name;
        std::string location;
        std::vector<Item> itemList;
};