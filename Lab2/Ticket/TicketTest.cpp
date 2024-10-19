#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\TIcket.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Ticket.cpp"

TEST(TicketTest, Initialization) {
    Passenger passenger("Alice Smith", "P12345678", 30);
    Ticket ticket(1, 199.99, "FL123", passenger);
    EXPECT_EQ(ticket.ticketID, 1);
    EXPECT_DOUBLE_EQ(ticket.price, 199.99);
    EXPECT_EQ(ticket.flightNumber, "FL123");
    EXPECT_EQ(ticket.passenger.name, "Alice Smith");
}

TEST(TicketTest, DefaultConstructor) {
    Ticket ticket;
    EXPECT_EQ(ticket.ticketID, 0);
    EXPECT_DOUBLE_EQ(ticket.price, 0.0);
    EXPECT_EQ(ticket.flightNumber, "");
    EXPECT_EQ(ticket.passenger.name, "");
}

TEST(TicketTest, TicketWithDifferentPassenger) {
    Passenger passenger("Bob Johnson", "P87654321", 25);
    Ticket ticket(2, 299.99, "FL456", passenger);
    EXPECT_EQ(ticket.passenger.passportNumber, "P87654321");
    EXPECT_EQ(ticket.passenger.age, 25);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
