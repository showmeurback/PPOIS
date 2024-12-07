#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Department.h"

class DepartmentTest : public ::testing::Test {
protected:
    Department department;

    DepartmentTest() : department("Emergency") {}
};

TEST_F(DepartmentTest, AddStaff) {
    Staff staff("John Doe", "Doctor", "555-5678");
    department.addStaff(staff);
}

TEST_F(DepartmentTest, RemoveStaff) {
    Staff staff("John Doe", "Doctor", "555-5678");
    department.addStaff(staff);
    department.removeStaff("John Doe");
}

TEST_F(DepartmentTest, RemoveNonExistentStaff) {
    department.removeStaff("NonExistent");
}

TEST_F(DepartmentTest, AdmitPatient) {
    Patient patient("Jane Smith", 30);
    department.admitPatient(patient);
}

TEST_F(DepartmentTest, GetDepartmentName) {
    ASSERT_EQ(department.getName(), "Emergency");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
