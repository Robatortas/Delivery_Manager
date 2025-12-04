#include <iostream>
#include "Order.h"
#include "Client.h"

Client::Client() {}

Client::Client(std::string name, std::string location) : name(name), location(location) {}

void Client::setOrder(Order& order) {

}

// Order Client::getOrder() const {
//     return NULL;
// }

std::string Client::getName() {return this->name;}

void Client::setName(std::string name) {this->name = name;}

void Client::setLocation() {}