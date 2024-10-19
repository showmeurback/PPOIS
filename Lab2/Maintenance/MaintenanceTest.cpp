#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Maintenance.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Maintenance.cpp"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
