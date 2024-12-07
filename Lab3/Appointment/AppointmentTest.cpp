#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Hospital.h"

class AppointmentTest : public ::testing::Test {
protected:
    Appointment appointment;

    AppointmentTest() : appointment("City Hospital", "123 Main St", "555-1234") {}
};

TEST_F(AppointmentTest, AddDepartment) {
    Department department("Emergency");
    appointment.addDepartment(department);
    ASSERT_EQ(hospital.getDepartments().size(), 1);
}

TEST_F(AppointmentTest, RemoveDepartment) {
    Department department("Emergency");
    appointment.addDepartment(department);
    appointment.removeDepartment("Emergency");
    ASSERT_EQ(hospital.getDepartments().size(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
