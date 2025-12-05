#pragma once

class Driver {
    public:
        Driver();
        Driver(std::string name, int id);
        int getId();
        std::string getName();
    private:
        std::string name;
        int id;
};