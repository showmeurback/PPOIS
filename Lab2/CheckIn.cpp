#include "CheckIn.h"
#include <iostream>

void CheckIn::checkInPassenger(Passenger passenger, Baggage baggage) {
    std::cout << "Checking in " << passenger.name << " with " << baggage.numberOfPieces << " pieces of baggage." << std::endl;
}