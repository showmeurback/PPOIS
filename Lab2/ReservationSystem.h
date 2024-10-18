#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <map>
#include "Ticket.h"

class ReservationSystem {
public:
    std::map<int, Ticket> tickets;

    void bookTicket(Ticket ticket);
    void cancelTicket(int ticketID);
};

#endif // RESERVATIONSYSTEM_H