#include "pch.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CheckIn.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CheckIn.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
