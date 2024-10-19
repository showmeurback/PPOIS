#include "pch.h" 
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CrewMember.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\CrewMember.cpp"

TEST(CrewMemberTest, Initialization) {
    CrewMember crewMember("Alice Smith", "Pilot");
    EXPECT_EQ(crewMember.name, "Alice Smith");
    EXPECT_EQ(crewMember.role, "Pilot");
}

TEST(CrewMemberTest, DifferentRoles) {
    CrewMember crewMember1("Bob Johnson", "Flight Attendant");
    CrewMember crewMember2("Charlie Brown", "Co-Pilot");
    EXPECT_EQ(crewMember1.role, "Flight Attendant");
    EXPECT_EQ(crewMember2.role, "Co-Pilot");
}

TEST(CrewMemberTest, EmptyFields) {
    CrewMember crewMember("", "");
    EXPECT_EQ(crewMember.name, "");
    EXPECT_EQ(crewMember.role, "");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
