#include "pch.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Passenger.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Passenger.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
