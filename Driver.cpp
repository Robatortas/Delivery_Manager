#include <iostream>
#include "Driver.h"

Driver::Driver() {}

Driver::Driver(std::string name, int id) : name(name), id(id) {}

int Driver::getId() {return this->id;}

std::string Driver::getName() {return this->name;}