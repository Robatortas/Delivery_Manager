#include <iostream>
#include "Driver.h"
#include "Vehicle.h"

Driver::Driver(std::string name, int id) : name(name), id(id) {}

// Assigns the vehicle that will be designated to the driver
void Driver::setDesignatedVehicle(const Vehicle vehicle) {
    this->designatedVehicle = vehicle;
}

int Driver::getId() {return this->id;}

std::string Driver::getName() {return this->name;}