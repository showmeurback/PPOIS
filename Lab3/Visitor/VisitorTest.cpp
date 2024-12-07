#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Visitor.h"

class VisitorTest : public ::testing::Test {
protected:
    Visitor visitor;

    VisitorTest() : visitor("Alice", "Sister", "2 PM - 4 PM") {}
};

TEST_F(VisitorTest, RequestVisit) {
    testing::internal::CaptureStdout();
    visitor.requestVisit();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Alice (Sister) requests a visit during 2 PM - 4 PM."), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
