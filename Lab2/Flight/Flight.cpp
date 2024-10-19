#include "Flight.h"
#include <iostream>

Flight::Flight(std::string fn, std::string o, std::string d, std::string dt, std::string at, int cap)
    : flightNumber(fn), origin(o), destination(d), departureTime(dt), arrivalTime(at), capacity(cap) {}

void Flight::addTicket(Ticket ticket) {
    if (tickets.size() < capacity) {
        tickets.push_back(ticket);
    }
    else {
        std::cout << "Flight is full!" << std::endl;
    }
}