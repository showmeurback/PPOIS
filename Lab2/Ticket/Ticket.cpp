#include "Ticket.h"

Ticket::Ticket(int id, double p, std::string fn, Passenger pass)
    : ticketID(id), price(p), flightNumber(fn), passenger(pass) {}
