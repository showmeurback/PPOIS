#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Patient.h"

class PatientTest : public ::testing::Test {
protected:
    Patient patient;

    PatientTest() : patient("Jane Doe", 28) {}
};

TEST_F(PatientTest, GetName) {
    ASSERT_EQ(patient.getName(), "Jane Doe");
}

TEST_F(PatientTest, UpdateMedicalHistory) {
    testing::internal::CaptureStdout();
    patient.updateMedicalHistory("Allergic to penicillin");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Jane Doe's medical history updated."), std::string::npos);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
