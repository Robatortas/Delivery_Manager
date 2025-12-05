#pragma once
#include <vector>

class Driver {
    public:
        Driver();
        Driver(std::string name, std::string city, int status);
        std::string getCity();
        std::string getName();
        std::string getStatus();
        Driver findDriverWithIndex(int index);
        std::vector<Driver> getDriverList();
        void changeDriverParams(int status, int index);
        void fillDriverList();
        int status; // 0=Free,1=Dispatched,2=Arrived
    private:
        std::vector<Driver> drivers;
        std::string name;
        std::string city;
};