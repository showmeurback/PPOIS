#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "Patient.h"
#include "Doctor.h"

class Appointment {
public:
    Appointment(const Patient& patient, const Doctor& doctor, const std::string& date, const std::string& time);
    void reschedule(const std::string& newDate, const std::string& newTime);

private:
    Patient patient;
    Doctor doctor;
    std::string date;
    std::string time;
};

#endif // APPOINTMENT_H