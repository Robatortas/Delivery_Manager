#include <iostream>
#include <fstream>
#include "Driver.h"
#include "Inventory.h"
#include "Order.h"

void invAdmin() {
    Inventory inv;
    
    std::cout << "INVENTORY LIST: " << std::endl;
    for(int i = 0; i < inv.getInventoryList().size(); i++) {
        std::cout << "NAME: " << inv.getInventoryList()[i].name << " | STOCK: " << inv.getInventoryList()[i].stock << std::endl;
    }
}

void orderAdmin() {
    int sel = 0;
    Order order;
    while(sel != -1) {
        sel = 0;
        std::cout << "\t\tOrders Administration Menu:" <<
        "\n\t1. Check Orders" <<
        "\n\t2. Change Order Status // UNAVAILABLE" <<
        "\n\t3. Back\n\n";
        std::cin >> sel;
        switch(sel) {
            case 1: {
                
                std::cout << "ORDERS LIST: " << std::endl;
                for(int i = 0; i < order.orders.size(); i++) {
                    std::cout << "CLIENT NAME: " << order.orders[i].client.getName() << " | ITEM: " << order.orders[i].item.getName() << " | LOCATION: " << order.orders[i].location << " | STATUS: " << order.orders[i].status << std::endl;
                }
            } break;
            case 2: orderAdmin();
            break;
            case 3: return;
            break;
            case 4: sel = -1;
        }
    }
}

void driverAdmin() {
    
}

void menu() {
    int sel = 0;
    while(sel != -1) {
        sel = 0;
        std::cout << "\n\n\t\tSTAFF MENU:" <<
        "\n\t1. Check Inventory" <<
        "\n\t2. Order Administration" <<
        "\n\t3. Driver Administration // UNAVAILABLE" <<
        "\n\t4. Exit\n\n";
        std::cin >> sel;
        switch(sel) {
            case 1: invAdmin();
            break;
            case 2: orderAdmin();
            break;
            case 3: driverAdmin();
            break;
            case 4: sel = -1;
        }
    }
}


// TODO: Add .csv file containing client's orders with their respective items
// TODO: Add functionality to convert all data to a .csv file to serve as a database
int main() {
    menu();

    // Inventory inv;
    
    // std::cout << "INVENTORY LIST: " << std::endl;
    // for(int i = 0; i < inv.getInventoryList().size(); i++) {
    //     std::cout << "NAME: " << inv.getInventoryList()[i].name << " | STOCK: " << inv.getInventoryList()[i].stock << std::endl;
    // }

    // Driver driver("John Doe", 001);


    // std::string name;
    // while(file >> name) {
    //     file >> 

    // }

    return 0;
}