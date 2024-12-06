#include "Doctor.h"
#include <iostream>

Doctor::Doctor(const std::string& name, const std::string& role, const std::string& phone, const std::string& specialty)
    : Staff(name, role, phone), specialty(specialty) {
}

void Doctor::treatPatient(const std::string& patientName) {
    patients.push_back(patientName);
    std::cout << getName() << " is treating " << patientName << ".\n";
}

std::string Doctor::getSpecialty() const {
    return specialty;
}