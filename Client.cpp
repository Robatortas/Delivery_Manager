#include <iostream>
#include "Client.h"

Client::Client(std::string name, std::string location) : name(name), location(location) {}

void Client::setOrder(Order order) {this->order = order;}

Order Client::getOrder() const {return this->order}

void Client::setLocation() {}