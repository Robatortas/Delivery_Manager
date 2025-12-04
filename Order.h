#pragma once
#include "Item.h"
#include "Driver.h"
#include "Client.h"

class Client;

class Order {
    public:
        Order(Client& client, Driver& driver, std::string location, int status);
        void addItem(Item& item, int quantity);
    private:
        Client client;
        Driver driver;
        std::string location;
        int status; // 0=posted, 1=underway, 2=delivered
};