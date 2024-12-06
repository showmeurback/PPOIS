#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>

class Medication {
public:
    Medication(const std::string& name, const std::string& dosage, const std::string& sideEffects);
    void updateDosage(const std::string& newDosage);
    void display() const;

private:
    std::string name;
    std::string dosage;
    std::string sideEffects;
};

#endif // MEDICATION_H