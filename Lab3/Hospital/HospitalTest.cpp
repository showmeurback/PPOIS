#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Hospital.h"

class HospitalTest : public ::testing::Test {
protected:
    Hospital hospital;

    HospitalTest() : hospital("City Hospital", "123 Main St", "555-1234") {}
};

TEST_F(HospitalTest, AddDepartment) {
    Department department("Emergency");
    hospital.addDepartment(department);
    ASSERT_EQ(hospital.getDepartments().size(), 1);
}

TEST_F(HospitalTest, RemoveDepartment) {
    Department department("Emergency");
    hospital.addDepartment(department);
    hospital.removeDepartment("Emergency");
    ASSERT_EQ(hospital.getDepartments().size(), 0);
}

TEST_F(HospitalTest, RemoveNonExistentDepartment) {
    hospital.removeDepartment("NonExistent");
    ASSERT_EQ(hospital.getDepartments().size(), 0);
}

TEST_F(HospitalTest, DisplayDepartments) {
    Department department1("Emergency");
    Department department2("Pediatrics");
    hospital.addDepartment(department1);
    hospital.addDepartment(department2);

    testing::internal::CaptureStdout();
    hospital.displayDepartments();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_NE(output.find("Emergency"), std::string::npos);
    ASSERT_NE(output.find("Pediatrics"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
