#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Treatment.h"

class TreatmentTest : public ::testing::Test {
protected:
    Medication medication;
    Treatment treatment;

    TreatmentTest()
        : medication("Painkiller", "500mg", "Dizziness"),
        treatment("Surgery", "Appendectomy", medication, 7) {
    }
};

TEST_F(TreatmentTest, StartTreatment) {
    testing::internal::CaptureStdout();
    treatment.startTreatment();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Starting treatment: Surgery - Appendectomy for 7 days."), std::string::npos);
}

TEST_F(TreatmentTest, DisplayTreatment) {
    testing::internal::CaptureStdout();
    treatment.display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Treatment: Surgery"), std::string::npos);
    ASSERT_NE(output.find("Description: Appendectomy"), std::string::npos);
    ASSERT_NE(output.find("Duration: 7 days"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
