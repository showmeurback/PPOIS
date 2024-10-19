#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airline.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airline.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
