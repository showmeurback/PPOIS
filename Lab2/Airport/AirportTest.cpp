#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airport.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Airport.cpp" 

TEST(AirportTest, Initialization) {
    Airport airport("JFK International", "New York");
    EXPECT_EQ(airport.name, "JFK International");
    EXPECT_EQ(airport.location, "New York");
    EXPECT_TRUE(airport.flights.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
