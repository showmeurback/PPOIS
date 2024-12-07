#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Emergency.h"

class EmergencyTest : public ::testing::Test {
protected:
    Emergency emergency;

    EmergencyTest() : emergency("E001", "Fire in the building") {}
};

TEST_F(EmergencyTest, ActivateEmergency) {
    testing::internal::CaptureStdout();
    emergency.activateEmergency();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Emergency activated: E001 - Fire in the building"), std::string::npos);
}

TEST_F(EmergencyTest, AssignResponseTeam) {
    testing::internal::CaptureStdout();
    emergency.assignResponseTeam("Firefighters");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Response team Firefighters assigned to emergency E001"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
