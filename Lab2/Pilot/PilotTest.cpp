#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Pilot.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Pilot.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
