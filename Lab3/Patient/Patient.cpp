#include "Patient.h"
#include <iostream>

Patient::Patient(const std::string& name, int age) : name(name), age(age) {}

std::string Patient::getName() const {
    return name;
}

void Patient::updateMedicalHistory(const std::string& history) {
    medicalHistory = history;
    std::cout << name << "'s medical history updated.\n";
}