#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Security.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Security.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
