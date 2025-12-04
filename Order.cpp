#include <iostream>
#include <fstream>
#include "Order.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Item.h"

Order::Order(Client& client, Driver& driver, std::string location, int status) : client(client), driver(driver), location(location), status(status) {
    fillOrderList();
}

// Adds item to their order vector list
void Order::addItem(Item& item, int quantity) {}

// Fills the orders vector list
void Order::fillOrderList() {
    std::ofstream file;
    file.open("Proyecto_C.csv", std::ios_base::out);
    if(!file.is_open()) std::cout << "ERROR: Unable to open file"; return;
    
}