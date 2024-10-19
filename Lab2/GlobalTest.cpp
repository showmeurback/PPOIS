#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Aircraft.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Aircraft.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airline.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airline.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airport.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airport.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Baggage.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Baggage.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CheckIn.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CheckIn.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CrewMember.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CrewMember.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CustomerService.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CustomerService.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Flight.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Flight.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightAttendant.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightAttendant.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightSchedule.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightSchedule.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Maintenance.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Maintenance.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Passenger.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Passenger.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Pilot.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Pilot.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\TIcket.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Ticket.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Security.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Security.cpp"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\ReservationSystem.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\ReservationSystem.cpp"

TEST(AircraftTest, Initialization) {
    Aircraft aircraft("Boeing 747", 400, "N12345");

    // Проверка модели
    EXPECT_EQ(aircraft.model, "Boeing 747");
    // Проверка вместимости
    EXPECT_EQ(aircraft.capacity, 400);
    // Проверка регистрационного номера
    EXPECT_EQ(aircraft.registrationNumber, "N12345");
}

TEST(AircraftTest, InitializationWithEmptyValues) {
    Aircraft aircraft("", 0, "");

    EXPECT_EQ(aircraft.model, "");
    EXPECT_EQ(aircraft.capacity, 0);
    EXPECT_EQ(aircraft.registrationNumber, "");
}

TEST(AircraftTest, InitializationWithMaxValues) {
    Aircraft aircraft("Airbus A380", INT_MAX, "A12345");

    EXPECT_EQ(aircraft.model, "Airbus A380");
    EXPECT_EQ(aircraft.capacity, INT_MAX);
    EXPECT_EQ(aircraft.registrationNumber, "A12345");
}

TEST(AirlineTest, Initialization) {
    Airline airline("Airline XYZ");

    EXPECT_EQ(airline.name, "Airline XYZ");
    EXPECT_TRUE(airline.aircrafts.empty());
    EXPECT_TRUE(airline.airports.empty());
}

TEST(AirlineTest, AddAircraft) {
    Airline airline("Airline XYZ");
    Aircraft aircraft("Boeing 747", 400, "N12345");

    airline.addAircraft(aircraft);

    EXPECT_EQ(airline.aircrafts.size(), 1);
    EXPECT_EQ(airline.aircrafts[0].model, "Boeing 747");
    EXPECT_EQ(airline.aircrafts[0].capacity, 400);
    EXPECT_EQ(airline.aircrafts[0].registrationNumber, "N12345");
}

TEST(AirlineTest, AddAirport) {
    Airline airline("Airline XYZ");
    Airport airport("JFK International", "New York");

    airline.addAirport(airport);

    EXPECT_EQ(airline.airports.size(), 1);
    EXPECT_EQ(airline.airports[0].name, "JFK International");
    EXPECT_EQ(airline.airports[0].location, "New York");
}

TEST(AirlineTest, AddMultipleAircrafts) {
    Airline airline("Airline XYZ");
    Aircraft aircraft1("Boeing 747", 400, "N12345");
    Aircraft aircraft2("Airbus A380", 600, "N67890");

    airline.addAircraft(aircraft1);
    airline.addAircraft(aircraft2);

    EXPECT_EQ(airline.aircrafts.size(), 2);
    EXPECT_EQ(airline.aircrafts[1].model, "Airbus A380");
}

TEST(AirlineTest, AddMultipleAirports) {
    Airline airline("Airline XYZ");
    Airport airport1("JFK International", "New York");
    Airport airport2("LAX", "Los Angeles");

    airline.addAirport(airport1);
    airline.addAirport(airport2);

    EXPECT_EQ(airline.airports.size(), 2);
    EXPECT_EQ(airline.airports[1].name, "LAX");
}

TEST(AirportTest, Initialization) {
    Airport airport("JFK International", "New York");
    EXPECT_EQ(airport.name, "JFK International");
    EXPECT_EQ(airport.location, "New York");
    EXPECT_TRUE(airport.flights.empty());
}

TEST(BaggageTest, Initialization) {
    Baggage baggage(20, 2);
    EXPECT_EQ(baggage.weight, 20);
    EXPECT_EQ(baggage.numberOfPieces, 2);
}

TEST(BaggageTest, ZeroWeightAndPieces) {
    Baggage baggage(0, 0);
    EXPECT_EQ(baggage.weight, 0);
    EXPECT_EQ(baggage.numberOfPieces, 0);
}

TEST(BaggageTest, LargeValues) {
    Baggage baggage(100, 10);
    EXPECT_EQ(baggage.weight, 100);
    EXPECT_EQ(baggage.numberOfPieces, 10);
}

TEST(CheckInTest, CheckInPassenger) {
    Passenger passenger("John Doe", "JD123", 20);
    Baggage baggage(20, 2);
    CheckIn checkIn;

    EXPECT_NO_THROW(checkIn.checkInPassenger(passenger, baggage));
}

TEST(CheckInTest, CheckInWithZeroBaggage) {
    Passenger passenger("Jane Smith", "JS456", 20);
    Baggage baggage(0, 0);
    CheckIn checkIn;

    EXPECT_NO_THROW(checkIn.checkInPassenger(passenger, baggage));
}

TEST(CrewMemberTest, Initialization) {
    CrewMember crewMember("Alice Smith", "Pilot");
    EXPECT_EQ(crewMember.name, "Alice Smith");
    EXPECT_EQ(crewMember.role, "Pilot");
}

TEST(CrewMemberTest, DifferentRoles) {
    CrewMember crewMember1("Bob Johnson", "Flight Attendant");
    CrewMember crewMember2("Charlie Brown", "Co-Pilot");
    EXPECT_EQ(crewMember1.role, "Flight Attendant");
    EXPECT_EQ(crewMember2.role, "Co-Pilot");
}

TEST(CrewMemberTest, EmptyFields) {
    CrewMember crewMember("", "");
    EXPECT_EQ(crewMember.name, "");
    EXPECT_EQ(crewMember.role, "");
}

TEST(CustomerServiceTest, AssistPassenger) {
    Passenger passenger("Emily Clark", "EC789", 19);
    CustomerService customerService;

    EXPECT_NO_THROW(customerService.assistPassenger(passenger));
}

TEST(CustomerServiceTest, AssistPassengerWithEmptyName) {
    Passenger passenger("", "EC000", 29);
    CustomerService customerService;

    EXPECT_NO_THROW(customerService.assistPassenger(passenger));
}

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

TEST(FlightAttendantTest, Initialization) {
    FlightAttendant flightAttendant("Laura Wilson", "Flight Attendant", 5);
    EXPECT_EQ(flightAttendant.name, "Laura Wilson");
    EXPECT_EQ(flightAttendant.role, "Flight Attendant");
    EXPECT_EQ(flightAttendant.yearsOfExperience, 5);
}

TEST(FlightAttendantTest, DifferentExperienceLevels) {
    FlightAttendant flightAttendant1("Mike Brown", "Flight Attendant", 2);
    FlightAttendant flightAttendant2("Sarah Connor", "Senior Flight Attendant", 10);
    EXPECT_EQ(flightAttendant1.yearsOfExperience, 2);
    EXPECT_EQ(flightAttendant2.yearsOfExperience, 10);
}

TEST(FlightAttendantTest, ZeroExperience) {
    FlightAttendant flightAttendant("Emily Davis", "Junior Flight Attendant", 0);
    EXPECT_EQ(flightAttendant.yearsOfExperience, 0);
}

TEST(FlightScheduleTest, Initialization) {
    FlightSchedule schedule;
    EXPECT_TRUE(schedule.flights.empty());
}

TEST(FlightScheduleTest, AddFlight) {
    FlightSchedule schedule;
    Flight flight("FL123", "New York", "Los Angeles", "10:00", "13:00", 150);
    schedule.addFlight(flight);
    EXPECT_EQ(schedule.flights.size(), 1);
    EXPECT_EQ(schedule.flights[0].flightNumber, "FL123");
}

TEST(FlightScheduleTest, AddMultipleFlights) {
    FlightSchedule schedule;
    Flight flight1("FL123", "New York", "Los Angeles", "10:00", "13:00", 150);
    Flight flight2("FL456", "Chicago", "Miami", "15:00", "18:00", 200);
    schedule.addFlight(flight1);
    schedule.addFlight(flight2);
    EXPECT_EQ(schedule.flights.size(), 2);
    EXPECT_EQ(schedule.flights[1].flightNumber, "FL456");
}
 
TEST(MaintenanceTest, PerformMaintenance) {
    Aircraft aircraft("Boeing 737", 180, "N12345");
    Maintenance maintenance;
    EXPECT_NO_THROW(maintenance.performMaintenance(aircraft));
}

TEST(MaintenanceTest, PerformMaintenanceWithDifferentAircraft) {
    Aircraft aircraft("Airbus A320", 150, "N67890");
    Maintenance maintenance;
    EXPECT_NO_THROW(maintenance.performMaintenance(aircraft));
}

TEST(PassengerTest, Initialization) {
    Passenger passenger("Alice Smith", "P12345678", 30);
    EXPECT_EQ(passenger.name, "Alice Smith");
    EXPECT_EQ(passenger.passportNumber, "P12345678");
    EXPECT_EQ(passenger.age, 30);
}

TEST(PassengerTest, DifferentAges) {
    Passenger passenger1("Bob Johnson", "P87654321", 25);
    Passenger passenger2("Charlie Brown", "P11223344", 45);
    EXPECT_EQ(passenger1.age, 25);
    EXPECT_EQ(passenger2.age, 45);
}

TEST(PassengerTest, ZeroAge) {
    Passenger passenger("Emily Davis", "P00000000", 0);
    EXPECT_EQ(passenger.age, 0);
}

TEST(PilotTest, Initialization) {
    Pilot pilot("David Wilson", "Pilot", 123456);
    EXPECT_EQ(pilot.name, "David Wilson");
    EXPECT_EQ(pilot.role, "Pilot");
    EXPECT_EQ(pilot.licenseNumber, 123456);
}

TEST(PilotTest, DifferentLicenseNumbers) {
    Pilot pilot1("John Doe", "Captain", 654321);
    Pilot pilot2("Jane Smith", "First Officer", 987654);
    EXPECT_EQ(pilot1.licenseNumber, 654321);
    EXPECT_EQ(pilot2.licenseNumber, 987654);
}

TEST(PilotTest, ZeroLicenseNumber) {
    Pilot pilot("Emily Clark", "Co-Pilot", 0);
    EXPECT_EQ(pilot.licenseNumber, 0);
}

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

TEST(SecurityTest, ScanPassenger) {
    Passenger passenger("Alice Smith", "P12345678", 30);
    Security security;
    EXPECT_TRUE(security.scanPassenger(passenger));
}


TEST(SecurityTest, ScanUnderagePassenger) {
    Passenger passenger("John Doe", "P87654321", 15);
    Security security;
    EXPECT_TRUE(security.scanPassenger(passenger));
}

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

TEST(PassengerTest, Initialization) {
    Passenger passenger("Alice Smith", "P12345678", 30);
    EXPECT_EQ(passenger.name, "Alice Smith");
    EXPECT_EQ(passenger.passportNumber, "P12345678");
    EXPECT_EQ(passenger.age, 30);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}