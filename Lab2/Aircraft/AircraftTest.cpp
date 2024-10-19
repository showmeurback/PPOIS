#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Aircraft.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
