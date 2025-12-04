#include <iostream>
#include "Order.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Item.h"

Order::Order(Client* client, Driver& driver, std::string location, int status) : client(client), driver(driver), location(location), status(status) {}

// Adds item to their order vector list
void Order::addItem(Item& item, int quantity) {}