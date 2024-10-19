#include "ReservationSystem.h"

void ReservationSystem::bookTicket(Ticket ticket) {
    tickets[ticket.ticketID] = ticket;
}

void ReservationSystem::cancelTicket(int ticketID) {
    tickets.erase(ticketID);
}