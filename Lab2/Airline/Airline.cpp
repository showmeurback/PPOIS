#include "Airline.h"

Airline::Airline(std::string n) : name(n) {}

void Airline::addAircraft(const Aircraft& aircraft) {
    aircrafts.push_back(aircraft);
}

void Airline::addAirport(const Airport& airport) {
    airports.push_back(airport);
}