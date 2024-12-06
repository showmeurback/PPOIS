#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "Staff.h"
#include "Patient.h"

class Department {
public:
    Department(const std::string& name);

    void addStaff(const Staff& staffMember);
    void removeStaff(const std::string& staffName);
    void admitPatient(const Patient& patient);
    std::string getName() const;

private:
    std::string name; 
    std::vector<Staff> staff; 
    std::vector<Patient> patients; 
};

#endif // DEPARTMENT_H