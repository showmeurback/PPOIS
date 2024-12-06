#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

#include <string>
#include <vector>
#include "Patient.h"
#include "Treatment.h"
#include "Medication.h"

class MedicalRecord {
public:
    MedicalRecord(const Patient& patient);
    void addTreatment(const Treatment& treatment);
    void addMedication(const Medication& medication);
    void displayRecord() const;

private:
    Patient patient;
    std::vector<Treatment> treatments;
    std::vector<Medication> medications;
};

#endif // MEDICALRECORD_H