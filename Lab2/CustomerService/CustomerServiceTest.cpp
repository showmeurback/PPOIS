#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CustomerService.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CustomerService.cpp"

TEST(CustomerServiceTest, AssistPassenger) {
    Passenger passenger("Emily Clark", "EC789", 19);
    CustomerService customerService;

    EXPECT_NO_THROW(customerService.assistPassenger(passenger));
}

TEST(CustomerServiceTest, AssistPassengerWithEmptyName) {
    Passenger passenger("", "EC000", 29);
    CustomerService customerService;

    EXPECT_NO_THROW(customerService.assistPassenger(passenger));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
