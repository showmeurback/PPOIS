#include "Airport.h"

Airport::Airport(std::string n, std::string loc)
    : name(n), location(loc) {}

void Airport::addFlight(Flight flight) {
    flights.push_back(flight);
}