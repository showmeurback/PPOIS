#ifndef DOCTOR_H
#define DOCTOR_H

#include "Staff.h"
#include <string>
#include <vector>

class Doctor : public Staff {
public:
    Doctor(const std::string& name, const std::string& role, const std::string& phone, const std::string& specialty);
    void treatPatient(const std::string& patientName);
    std::string getSpecialty() const;

private:
    std::string specialty;
    std::vector<std::string> patients;
};

#endif // DOCTOR_H