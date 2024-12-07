#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Nurse.h"

class NurseTest : public ::testing::Test {
protected:
    Nurse nurse;

    NurseTest() : nurse("Nina", "Head Nurse", "555-9876", "Night Shift") {}
};

TEST_F(NurseTest, ManagePatientCare) {
    testing::internal::CaptureStdout();
    nurse.managePatientCare("John Doe");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Nina is managing care for John Doe"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
