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
        std::cout << "\n\n\t\tOrders Administration Menu:" <<
        "\n\t1. Check Orders" <<
        "\n\t2. Change Order Status" <<
        "\n\t3. Back\n\n";
        std::cin >> sel;
        switch(sel) {
            case 1: {
                order.fillOrderList();
                std::cout << "ORDERS LIST: " << std::endl;
                for(int i = 0; i < order.orders.size(); i++) {
                    std::cout << "[" << i << "] CLIENT NAME: " << order.orders[i].client.getName() << "\n\tITEM: " << order.orders[i].item.getName() << "\n\tLOCATION: " << order.orders[i].location << "\n\tSTATUS: " << order.orders[i].getStatus() << std::endl;
                }
                std::cout << "- - - - - - - -";
            } break;
            case 2: {
                order.fillOrderList();
                std::cout << "Select an order by its index: ";
                int index = 0;
                std::cin >> index;
                std::cout << "(0=posted, 1=underway, 2=delivered)\nChange status: ";
                int status;
                std::cin >> status;
                std::cout << "ORDERS SIZE:" << order.orders.size();

                order.findOrderWithIndex(index).changeOrderParams(status, index);
                std::cout << "Order " << index << " changed to " << order.findOrderWithIndex(index).getStatus();
            } break;
            case 3: return;
            break;
            case 4: sel = -1;
            break;
        }
    }
}

void driverAdmin() {
    int sel = 0;
    Driver driver;
    while(sel != -1) {
        sel = 0;
        std::cout << "\n\n\t\tOrders Administration Menu:" <<
        "\n\t1. Check Driver List" <<
        "\n\t2. Change Driver Status" <<
        "\n\t3. Back\n\n";
        std::cin >> sel;
        switch(sel) {
            case 1: {
                driver.fillDriverList();
                std::cout << "DRIVER LIST: " << std::endl;
                for(int i = 0; i < driver.getDriverList().size(); i++) {
                    std::cout << "[" << i << "] DRIVER NAME: " << driver.getDriverList()[i].getName() << "\n\tCITY: " << driver.getDriverList()[i].getCity() << "\n\tSTATUS: " << driver.getDriverList()[i].status << std::endl;
                }
                std::cout << "- - - - - - - -";
            } break;
            case 2: {
                driver.fillDriverList();
                std::cout << "Select a driver by its index: ";
                int index = 0;
                std::cin >> index;
                std::cout << "(0=free, 1=dispatched, 2=arrived)\nChange status: ";
                int status;
                std::cin >> status;

                driver.findDriverWithIndex(index).changeDriverParams(status, index);
                std::cout << "Driver status " << index << " changed to " << driver.findDriverWithIndex(index).getStatus();
            } break;
            case 3: return;
            break;
            case 4: sel = -1;
            break;
        }
    }
}

void menu() {
    int sel = 0;
    while(sel != -1) {
        sel = 0;
        std::cout << "\n\n\t\tSTAFF MENU:" <<
        "\n\t1. Check Inventory" <<
        "\n\t2. Order Administration" <<
        "\n\t3. Driver Administration" <<
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
    return 0;
}