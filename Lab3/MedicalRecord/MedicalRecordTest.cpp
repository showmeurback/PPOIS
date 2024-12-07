#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\MedicalRecord.h"

class MedicalRecordTest : public ::testing::Test {
protected:
    Patient patient;
    MedicalRecord medicalRecord;

    MedicalRecordTest() : patient("Jane Doe", 28), medicalRecord(patient) {}
};

TEST_F(MedicalRecordTest, DisplayRecord) {
    testing::internal::CaptureStdout();
    medicalRecord.displayRecord();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Medical Record for Jane Doe"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
