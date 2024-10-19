#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\ReservationSystem.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\ReservationSystem.cpp"

TEST(ReservationSystemTest, BookTicket) {
    ReservationSystem reservationSystem;
    Passenger passenger("Alice Smith", "P12345678", 30);
    Ticket ticket(1, 199.99, "FL123", passenger);
    reservationSystem.bookTicket(ticket);
    EXPECT_EQ(reservationSystem.tickets.size(), 1);
    EXPECT_EQ(reservationSystem.tickets[1].ticketID, 1);
}

TEST(ReservationSystemTest, CancelTicket) {
    ReservationSystem reservationSystem;
    Passenger passenger("Bob Johnson", "P87654321", 25);
    Ticket ticket(2, 299.99, "FL456", passenger);
    reservationSystem.bookTicket(ticket);
    reservationSystem.cancelTicket(2);
    EXPECT_EQ(reservationSystem.tickets.size(), 0);
}

TEST(ReservationSystemTest, CancelNonexistentTicket) {
    ReservationSystem reservationSystem;
    EXPECT_NO_THROW(reservationSystem.cancelTicket(999));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
