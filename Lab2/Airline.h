#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <vector>
#include "Aircraft.h"
#include "Airport.h"

class Airline {
public:
    std::string name;
    std::vector<Aircraft> aircrafts;
    std::vector<Airport> airports;

    Airline(std::string n);
    void addAircraft(const Aircraft& aircraft);
    void addAirport(const Airport& airport);
};

#endif // AIRLINE_H