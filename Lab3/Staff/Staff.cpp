#include "Staff.h"
#include <iostream>

Staff::Staff(const std::string& name, const std::string& role, const std::string& phone)
    : name(name), role(role), phone(phone) {
}

std::string Staff::getName() const {
    return name;
}

void Staff::assignToDepartment(const std::string& departmentName) {
    department = departmentName;
    std::cout << name << " назначен в отделение " << departmentName << ".\n";
}