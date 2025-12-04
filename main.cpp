#include <iostream>
#include <fstream>
#include "Driver.h"
#include "Inventory.h"

// TODO: Add .csv file containing client's orders with their respective items
// TODO: Add functionality to convert all data to a .csv file to serve as a database
int main() {
    Inventory inv;
    
    std::cout << "INVENTORY LIST: " << std::endl;
    for(int i = 0; i < inv.getInventoryList().size(); i++) {
        std::cout << "NAME: " << inv.getInventoryList()[i].name << " | STOCK: " << inv.getInventoryList()[i].stock << std::endl;
    }

    Driver driver("John Doe", 001);

    std::ofstream file;
    file.open("orders.csv", std::ios_base::out);
    if(!file.is_open()) {
        std::cout << "Unable to open " << std::endl;
        return -1;
    }


    // std::string name;
    // while(file >> name) {
    //     file >> 

    // }

    return 0;
}