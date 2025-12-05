#include <iostream>
#include <sstream>
#include <fstream>
#include "Driver.h"

Driver::Driver() {}

Driver::Driver(std::string name, std::string city, int status) : name(name), city(city), status(status) {}

std::string Driver::getCity() {return this->city;}

std::string Driver::getName() {return this->name;}

std::vector<Driver> Driver::getDriverList() {return this->drivers;}

Driver Driver::findDriverWithIndex(int index) {
    return this->drivers[index];
}

std::string Driver::getStatus() {
    if(this->status == 1) return "dispatched";
    else if(this->status == 2) return "arrived";
    return "free";
}

void Driver::changeDriverParams(int status, int index) {
    this->status = status;
    index+=1;
    std::ifstream iFile("drivers.csv");

    if (!iFile.is_open()) {
        std::cerr << "ERROR: Unable to open file \"drivers.csv\"" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(iFile, line)) {
        lines.push_back(line);
    }
    iFile.close(); 

    if (index >= lines.size() || index < 1) {
        std::cerr << "ERROR: Invalid index (" << index << ") provided for file update. Must be 1 or higher." << std::endl;
        return;
    }

    std::string tLine = lines[index];
    std::string header = lines[0];
    std::stringstream ss(tLine);

    std::string name, city, statusSt; 

    std::getline(ss, name, ',');
    std::getline(ss, city, ',');
    std::getline(ss, statusSt, ',');
    
    std::stringstream newLineSS;
    newLineSS << name << "," << city << "," << status; 
    
    lines[index] = newLineSS.str();

    std::ofstream file("drivers.csv", std::ios::trunc);

    int lnCount = 0;
    for (std::string& updatedLine : lines) {
        if(lnCount == 0) file << header << "\n";
        else file << updatedLine << "\n";
        lnCount++;
    }

    file.close();
}

// Fills the orders vector list
void Driver::fillDriverList() {
    this->drivers.clear();
    std::ifstream file("drivers.csv");

    if (!file.is_open()) {
        std::cout << "ERROR: Unable to open file \"drivers.csv\"" << std::endl;
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
        std::string name, city, statusStr;

        std::getline(ss, name, ',');
        std::getline(ss, city, ',');
        std::getline(ss, statusStr, ',');

        if (name.empty()) continue;

        int status = std::stoi(statusStr);

        Driver d(name, city, status);
        drivers.push_back(d);
    }

    file.close();
}