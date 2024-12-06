#include "Department.h"
#include <iostream>
#include <algorithm>

Department::Department(const std::string& name) : name(name) {}

void Department::addStaff(const Staff& staffMember) {
    staff.push_back(staffMember);
    std::cout << "��������� " << staffMember.getName() << " �������� � ��������� " << name << ".\n";
}

void Department::removeStaff(const std::string& staffName) {
    auto it = std::remove_if(staff.begin(), staff.end(),
        [&staffName](const Staff& member) { return member.getName() == staffName; });
    if (it != staff.end()) {
        staff.erase(it, staff.end());
        std::cout << "��������� " << staffName << " ������ �� ��������� " << name << ".\n";
    }
    else {
        std::cout << "��������� " << staffName << " �� ������.\n";
    }
}

void Department::admitPatient(const Patient& patient) {
    patients.push_back(patient);
    std::cout << "������� " << patient.getName() << " ������ � ��������� " << name << ".\n";
}

std::string Department::getName() const {
    return name;
}