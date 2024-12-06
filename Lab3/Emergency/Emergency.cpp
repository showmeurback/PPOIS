#include "Emergency.h"
#include <iostream>

Emergency::Emergency(const std::string& code, const std::string& description)
    : code(code), description(description) {
}

void Emergency::activateEmergency() {
    std::cout << "Emergency activated: " << code << " - " << description << "\n";
}

void Emergency::assignResponseTeam(const std::string& teamName) {
    responseTeam = teamName;
    std::cout << "Response team " << responseTeam << " assigned to emergency " << code << ".\n";
}