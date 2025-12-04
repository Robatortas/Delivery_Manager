#pragma once
#include "Vehicle.h"

class Driver {
    public:
        Driver();
        Driver(std::string name, int id);
        void setDesignatedVehicle(const Vehicle vehicle);
        int getId();
        std::string getName();
    private:
        std::string name;
        int id;
        Vehicle designatedVehicle;
};