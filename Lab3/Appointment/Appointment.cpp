#include "Appointment.h"
#include <iostream>

Appointment::Appointment(const Patient& patient, const Doctor& doctor, const std::string& date, const std::string& time)
    : patient(patient), doctor(doctor), date(date), time(time) {
}

void Appointment::reschedule(const std::string& newDate, const std::string& newTime) {
    date = newDate;
    time = newTime;
    std::cout << "Appointment rescheduled to " << date << " at " << time << ".\n";
}

