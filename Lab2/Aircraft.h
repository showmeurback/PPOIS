#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>

class Aircraft {
public:
    std::string model;
    int capacity;
    std::string registrationNumber;

    Aircraft(std::string m, int c, std::string r);
};

#endif // AIRCRAFT_H