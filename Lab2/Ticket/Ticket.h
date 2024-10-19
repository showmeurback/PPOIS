#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Passenger.h"

class Ticket {
public:
    int ticketID;
    double price;
    std::string flightNumber;
    Passenger passenger;

    Ticket(int id, double p, std::string fn, Passenger pass);
    Ticket() : ticketID(0), price(0.0), flightNumber(""), passenger("","",0) {}

};

#endif // TICKET_H