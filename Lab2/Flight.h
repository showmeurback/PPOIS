#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "Ticket.h"

class Flight {
public:
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    int capacity;
    std::vector<Ticket> tickets;

    Flight(std::string fn, std::string o, std::string d, std::string dt, std::string at, int cap);
    void addTicket(Ticket ticket);
};

#endif // FLIGHT_H