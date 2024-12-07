#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Staff.h"

class StaffTest : public ::testing::Test {
protected:
    Staff staff;

    StaffTest() : staff("John Doe", "Nurse", "555-1234") {}
};

TEST_F(StaffTest, GetName) {
    ASSERT_EQ(staff.getName(), "John Doe");
}

TEST_F(StaffTest, AssignToDepartment) {
    testing::internal::CaptureStdout();
    staff.assignToDepartment("Emergency");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("John Doe назначен в отделение Emergency."), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
