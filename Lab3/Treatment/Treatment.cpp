#include "Treatment.h"
#include <iostream>

Treatment::Treatment(const std::string& name, const std::string& description, const Medication& medication, int duration)
    : name(name), description(description), medication(medication), duration(duration) {
}

void Treatment::startTreatment() {
    std::cout << "Starting treatment: " << name << " - " << description << " for " << duration << " days.\n";
}

void Treatment::display() const {
    std::cout << "Treatment: " << name << ", Description: " << description << ", Duration: " << duration << " days.\n";
}