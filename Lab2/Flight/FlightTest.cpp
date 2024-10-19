#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Flight.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Flight.cpp"

TEST(FlightTest, Initialization) {
    Flight flight("FL123", "New York", "Los Angeles", "10:00", "13:00", 150);
    EXPECT_EQ(flight.flightNumber, "FL123");
    EXPECT_EQ(flight.origin, "New York");
    EXPECT_EQ(flight.destination, "Los Angeles");
    EXPECT_EQ(flight.departureTime, "10:00");
    EXPECT_EQ(flight.arrivalTime, "13:00");
    EXPECT_EQ(flight.capacity, 150);
    EXPECT_TRUE(flight.tickets.empty());
}

TEST(FlightTest, AddTicket) {
    Flight flight("FL123", "New York", "Los Angeles", "10:00", "13:00", 150);
    Passenger passenger("John Doe", "JD123", 30);
    Ticket ticket(1, 199.99, "FL123", passenger);
    flight.addTicket(ticket);
    EXPECT_EQ(flight.tickets.size(), 1);
    EXPECT_EQ(flight.tickets[0].ticketID, 1);
}

TEST(FlightTest, AddMultipleTickets) {
    Flight flight("FL123", "New York", "Los Angeles", "10:00", "13:00", 150);
    Passenger passenger1("John Doe", "JD123", 30);
    Passenger passenger2("Jane Doe", "JD456", 28);
    Ticket ticket1(1, 199.99, "FL123", passenger1);
    Ticket ticket2(2, 299.99, "FL123", passenger2);
    flight.addTicket(ticket1);
    flight.addTicket(ticket2);
    EXPECT_EQ(flight.tickets.size(), 2);
    EXPECT_EQ(flight.tickets[1].ticketID, 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
