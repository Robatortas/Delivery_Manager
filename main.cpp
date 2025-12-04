#include <iostream>
#include <fstream>
#include "Driver.h"

// TODO: Add .csv file containing client's orders with their respective items
// TODO: Add functionality to convert all data to a .csv file to serve as a database
int main() {
    Driver driver("John Doe", 001);

    std::ofstream file;
    file.open("orders.csv", std::ios_base::out);
    if(!file.is_open) {
        std::cerr << "Unable to open " << file.getloc() << std::endl;
        return -1;
    }

    std::string name;
    while(file >> name) {
        file >> 

    }

    return 0;
}