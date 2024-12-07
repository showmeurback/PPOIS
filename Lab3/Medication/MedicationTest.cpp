#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Medication.h"

class MedicationTest : public ::testing::Test {
protected:
    Medication medication;

    MedicationTest() : medication("Painkiller", "500mg", "Dizziness, Nausea") {}
};

TEST_F(MedicationTest, UpdateDosage) {
    testing::internal::CaptureStdout();
    medication.updateDosage("250mg");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Dosage updated to: 250mg"), std::string::npos);
}

TEST_F(MedicationTest, DisplayMedication) {
    testing::internal::CaptureStdout();
    medication.display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Medication: Painkiller"), std::string::npos);
    ASSERT_NE(output.find("Dosage: 500mg"), std::string::npos);
    ASSERT_NE(output.find("Side Effects: Dizziness, Nausea"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
