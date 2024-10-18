#include "Security.h"
#include <iostream>

bool Security::scanPassenger(Passenger passenger) {
    std::cout << "Scanning passenger: " << passenger.name << std::endl;
    return true; // Assume all scans are successful for simplicity
}