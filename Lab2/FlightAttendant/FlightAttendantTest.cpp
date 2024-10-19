#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightAttendant.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\FlightAttendant.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
