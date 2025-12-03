#pragma once
#include <vector>
#include "Order.h"

class Client {
    public:
        Client(std::string name, std::string location);
        void setOrder(Order order);
        Order getOrder();
    private:
        std::string name;
        std::string location;
        Order order;
        std::vector itemList;
}