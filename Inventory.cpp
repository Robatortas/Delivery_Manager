#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Item.h"
#include "Inventory.h"

Inventory::Inventory() {
    fillInventory();
}

// Function to read the Inventario_C.csv file and fill the vector inventory variable
void Inventory::fillInventory() {
    std::ifstream file;
    file.open("Inventario_C.csv", std::ios_base::in);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo Inventario_C.csv" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Item item;
        std::string temp;

        std::getline(ss, item.name, ','); 
        std::getline(ss, temp, ',');
        item.stock = std::stoi(temp);

        inventory.push_back(item);
    }

    file.close();
    std::cout << "Inventario cargado correctamente (" << inventory.size() << " items).\n";
}

void Inventory::addToInventory(std::string name, int quantity) {
    for (auto& item : inventory) {
        if (item.name == name) {
            item.stock += quantity;
            std::cout << "Se añadieron " << quantity << " unidades. Nueva cantidad de "
                      << item.name << ": " << item.stock << std::endl;
            return;
        }
    }
    std::cout << "Item con ID " << name << " no encontrado.\n";
}

void Inventory::takeFromInventory(std::string name, int quantity) {
    for (auto& item : inventory) {
        if (item.name == name) {
            if (item.stock >= quantity) {
                item.stock -= quantity;
                std::cout << "Se retiraron " << quantity << " unidades. Quedan "
                          << item.stock << " de " << item.name << std::endl;
            } else {
                std::cout << "Error: Stock insuficiente para " << item.name
                          << " (disponible: " << item.stock << ")\n";
            }
        }
    }
}

std::vector<Item> Inventory::getInventoryList() {return this->inventory;}