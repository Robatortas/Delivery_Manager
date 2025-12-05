#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Order.h"
#include "Driver.h"
#include "Item.h"

Order::Order() {}

Order::Order(Client& client, Driver& driver, Item& item, std::string location, int status) : client(client), driver(driver), item(item), location(location), status(status) {
    
}

// Adds item to their order vector list
void Order::addItem(Item& item, int quantity) {}

Order Order::findOrderWithIndex(int index) {
    return this->orders[index];
}

std::string Order::getStatus() {
    if(this->status == 1) return "underway";
    else if(this->status == 2) return "delivered";
    return "posted";
}

void Order::changeOrderParams(int status, int index) {
    this->status = status;
    index+=1;
    std::ifstream iFile("orders.csv");

    if (!iFile.is_open()) {
        std::cout << "ERROR: Unable to open file \"orders.csv\"" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    int lineCount = 1;

    // Read every line into the vector
    while (std::getline(iFile, line)) {
        lines.push_back(line);
    }
    iFile.close();

    if (index >= lines.size() || index < 0) {
        std::cerr << "ERROR: Invalid index (" << index << ") provided for file update." << std::endl;
        return;
    }

    // Skip header
    if (std::getline(iFile, line)) {
        std::cout << "Skipped Header: " << line << std::endl;
    }

    // Line we want to reach
    std::string tLine = lines[index];
    std::string header = lines[0];
    std::stringstream ss(tLine);

    std::string name, product, city, statusStr; // statusStr will hold the OLD status, but we only need to extract it

    std::getline(ss, name, ',');
    std::getline(ss, product, ',');
    std::getline(ss, city, ',');
    std::getline(ss, statusStr, ',');
    
    std::stringstream newLineSS;
    newLineSS << name << "," << product << "," << city << "," << status;
    
    lines[index] = newLineSS.str();

    this->status = status; 
    
    std::ofstream file("orders.csv", std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "ERROR: Unable to open file \"orders.csv\" for writing." << std::endl;
        return;
    }

    // Write lines back to file

    int lnCount = 0;
    for (std::string& updatedLine : lines) {
        if(lnCount == 0) file << header << "\n";
        else file << updatedLine << "\n";
        lnCount++;
    }

    file.close();
}

// Fills the orders vector list
void Order::fillOrderList() {
    this->orders.clear();
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