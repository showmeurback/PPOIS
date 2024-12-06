#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
public:
    Patient(const std::string& name, int age);
    std::string getName() const;
    void updateMedicalHistory(const std::string& history);

private:
    std::string name;
    int age;
    std::string medicalHistory;
};

#endif // PATIENT_H