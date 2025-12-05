#pragma once
#include "Item.h"
#include "Driver.h"
#include "Client.h"
#include <vector>

class Client;

class Order {
    public:
        Order();
        Order(Client& client, Driver& driver, Item& item, std::string location, int status);
        void addItem(Item& item, int quantity);
        void fillOrderList();
        std::string getStatus();
        void changeOrderParams(int status, int index);
        Order findOrderWithIndex(int index);
        std::vector<Order> orders;
        Client client;
        Driver driver;
        std::string location;
        Item item;
        int status; // 0=posted, 1=underway, 2=delivered
};