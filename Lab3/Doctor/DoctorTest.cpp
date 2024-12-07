#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Doctor.h"

class DoctorTest : public ::testing::Test {
protected:
    Doctor doctor;

    DoctorTest() : doctor("Dr. Smith", "Surgeon", "555-1234", "Surgery") {}
};

TEST_F(DoctorTest, TreatPatient) {
    testing::internal::CaptureStdout();
    doctor.treatPatient("Jane Doe");
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Dr. Smith is treating Jane Doe"), std::string::npos);
}

TEST_F(DoctorTest, GetSpecialty) {
    ASSERT_EQ(doctor.getSpecialty(), "Surgery");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
