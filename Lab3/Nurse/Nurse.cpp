#include "Nurse.h"
#include <iostream>

Nurse::Nurse(const std::string& name, const std::string& role, const std::string& phone, const std::string& shift)
    : Staff(name, role, phone), shift(shift) {
}

void Nurse::managePatientCare(const std::string& patientName) {
    assignedPatients.push_back(patientName);
    std::cout << getName() << " is managing care for " << patientName << ".\n";
}