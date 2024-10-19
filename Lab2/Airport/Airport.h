#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include "Flight.h"

class Airport {
public:
    std::string name;
    std::string location;
    std::vector<Flight> flights;

    Airport(std::string n, std::string loc);
    void addFlight(Flight flight);
};

#endif // AIRPORT_H