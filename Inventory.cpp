#include <iostream>
#include <vector>
#include "Inventory.h"


Inventory::Inventory() {}

// Function to read the Inventario_C.csv file and fill the vector inventory variable
void fillInventory() {
    std::ifstream file("Inventario_C.csv");
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

        std::getline(ss, temp, ',');
        item.id = std::stoi(temp);
        std::getline(ss, item.nombre, ','); 
        std::getline(ss, temp, ',');
        item.cantidad = std::stoi(temp);

        std::getline(ss, temp, ',');
        item.precio = std::stod(temp);

        inventory.push_back(item);
    }

    file.close();
    std::cout << "Inventario cargado correctamente (" << inventory.size() << " items).\n";
}
void addToInventory() {
    for (auto& item : inventory) {
        if (item.id == id) {
            item.cantidad += quantity;
            std::cout << "Se añadieron " << quantity << " unidades. Nueva cantidad de "
                      << item.nombre << ": " << item.cantidad << std::endl;
            return;
        }
    }
    std::cout << "Item con ID " << id << " no encontrado.\n";

    bool Inventory::takeFromInventory(int id, int quantity) {
    for (auto& item : inventory) {
        if (item.id == id) {
            if (item.cantidad >= quantity) {
                item.cantidad -= quantity;
                std::cout << "Se retiraron " << quantity << " unidades. Quedan "
                          << item.cantidad << " de " << item.nombre << std::endl;
                return true;
            } else {
                std::cout << "Error: Stock insuficiente para " << item.nombre
                          << " (disponible: " << item.cantidad << ")\n";
                return false;
            }
        }
}

// Take a certain quantity from inventory
void takeFromInventory(int quantity) {
    for (auto& item : inventory) {
        if (item.id == productId) {
            if (item.cantidad >= quantity) {
                item.cantidad -= quantity;
                std::cout << "Compra exitosa: " << quantity 
                          << " unidad(es) de '" << item.nombre 
                          << "'. Stock restante: " << item.cantidad << std::endl;
                return true;
            } else {
                std::cout << "Error: Stock insuficiente de '" << item.nombre 
                          << "'. Disponible: " << item.cantidad 
                          << ", solicitado: " << quantity << std::endl;
                return false;
            }
        }
    }

    std::cout << "Error: Producto con ID " << productId << " no encontrado en el inventario." << std::endl;
    return false;
}
