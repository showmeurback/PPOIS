#ifndef TREATMENT_H
#define TREATMENT_H

#include <string>
#include "Medication.h"

class Treatment {
public:
    Treatment(const std::string& name, const std::string& description, const Medication& medication, int duration);
    void startTreatment();
    void display() const;

private:
    std::string name;
    std::string description;
    Medication medication;
    int duration;
};

#endif // TREATMENT_H