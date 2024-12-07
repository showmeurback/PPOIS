#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Insurance.h"

class InsuranceTest : public ::testing::Test {
protected:
    Insurance insurance;

    InsuranceTest() : insurance("HealthCare Inc.", "123456789", "Full coverage") {}
};

TEST_F(InsuranceTest, UpdateCoverage) {
    testing::internal::CaptureStdout();
    insurance.updateCoverage("Partial coverage");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Coverage details updated to: Partial coverage"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
