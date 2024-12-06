#include "MedicalRecord.h"
#include <iostream>

MedicalRecord::MedicalRecord(const Patient& patient) : patient(patient) {}

void MedicalRecord::addTreatment(const Treatment& treatment) {
    treatments.push_back(treatment);
}

void MedicalRecord::addMedication(const Medication& medication) {
    medications.push_back(medication);
}

void MedicalRecord::displayRecord() const {
    std::cout << "Medical Record for " << patient.getName() << ":\n";
    std::cout << "Treatments:\n";
    for (const auto& treatment : treatments) {
        treatment.display();
    }
    std::cout << "Medications:\n";
    for (const auto& medication : medications) {
        medication.display();
    }
}
