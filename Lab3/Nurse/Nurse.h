#ifndef NURSE_H
#define NURSE_H

#include "Staff.h"
#include <string>
#include <vector>

class Nurse : public Staff {
public:
    Nurse(const std::string& name, const std::string& role, const std::string& phone, const std::string& shift);
    void managePatientCare(const std::string& patientName);

private:
    std::string shift;
    std::vector<std::string> assignedPatients;
};

#endif // NURSE_H