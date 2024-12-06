#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>
#include "Department.h"

class Hospital {
public:
    Hospital(const std::string& name, const std::string& address, const std::string& phone);

    void addDepartment(const Department& dept);
    void removeDepartment(const std::string& deptName);
    void displayDepartments() const;
    const std::vector<Department>& getDepartments() const;

private:
    std::string name;
    std::string address;
    std::string phone;
    std::vector<Department> departments; 
};

#endif // HOSPITAL_H