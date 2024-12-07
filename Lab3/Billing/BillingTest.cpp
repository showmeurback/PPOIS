#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Billing.h"

class BillingTest : public ::testing::Test {
protected:
    Billing billing;

    BillingTest() : billing("John Doe", "Nurse", "555-1234") {}
};

TEST_F(BillingTest, AssignToDepartment) {
    testing::internal::CaptureStdout();
    billing.assignToDepartment("Emergency");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("John Doe назначен в отделение Emergency."), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
