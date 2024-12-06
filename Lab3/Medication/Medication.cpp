#include "Medication.h"
#include <iostream>

Medication::Medication(const std::string& name, const std::string& dosage, const std::string& sideEffects)
    : name(name), dosage(dosage), sideEffects(sideEffects) {
}

void Medication::updateDosage(const std::string& newDosage) {
    dosage = newDosage;
    std::cout << "Dosage updated to: " << dosage << "\n";
}

void Medication::display() const {
    std::cout << "Medication: " << name << ", Dosage: " << dosage << ", Side Effects: " << sideEffects << "\n";
}