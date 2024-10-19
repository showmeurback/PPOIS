#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightSchedule.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightSchedule.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
