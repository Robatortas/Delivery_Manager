#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Order.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Item.h"

Order::Order() {
    fillOrderList();
}

Order::Order(Client& client, Driver& driver, Item& item, std::string location, int status) : client(client), driver(driver), item(item), location(location), status(status) {
    
}

// Adds item to their order vector list
void Order::addItem(Item& item, int quantity) {}

// Fills the orders vector list
void Order::fillOrderList() {
    std::ifstream file("orders.csv");

    if (!file.is_open()) {
        std::cout << "ERROR: Unable to open file \"orders.csv\"" << std::endl;
        return;
    }

    std::string line;

    // Skip header
    if (std::getline(file, line)) {
        std::cout << "Skipped Header: " << line << std::endl;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, city, product, statusStr;

        std::getline(ss, name, ',');
        std::getline(ss, product, ',');
        std::getline(ss, city, ',');
        std::getline(ss, statusStr, ',');

        if (name.empty()) continue;

        int status = std::stoi(statusStr);
\
        Client c;
        c.setName(name);

        Driver d;

        Item item(product);

        Order o(c, d, item, city, status);

        orders.push_back(o);
    }

    file.close();
    std::cout << "Orders loaded: " << orders.size() << std::endl;
}