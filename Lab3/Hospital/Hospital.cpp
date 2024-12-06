#include "Hospital.h"
#include <iostream>
#include <algorithm>

Hospital::Hospital(const std::string& name, const std::string& address, const std::string& phone)
    : name(name), address(address), phone(phone) {
}

void Hospital::addDepartment(const Department& dept) {
    departments.push_back(dept);
    std::cout << "Отделение " << dept.getName() << " добавлено в больницу " << name << ".\n";
}

void Hospital::removeDepartment(const std::string& deptName) {
    auto it = std::remove_if(departments.begin(), departments.end(),
        [&deptName](const Department& dept) { return dept.getName() == deptName; });
    if (it != departments.end()) {
        departments.erase(it, departments.end());
        std::cout << "Отделение " << deptName << " удалено из больницы " << name << ".\n";
    }
    else {
        std::cout << "Отделение " << deptName << " не найдено.\n";
    }
}

void Hospital::displayDepartments() const {
    std::cout << "Отделения в больнице " << name << ":\n";
    for (const auto& dept : departments) {
        std::cout << "- " << dept.getName() << "\n";
    }
}

const std::vector<Department>& Hospital::getDepartments() const {
    return departments;
}