#include "Visitor.h"
#include <iostream>

Visitor::Visitor(const std::string& name, const std::string& relationship, const std::string& visitingHours)
    : name(name), relationship(relationship), visitingHours(visitingHours) {
}

void Visitor::requestVisit() {
    std::cout << name << " (" << relationship << ") requests a visit during " << visitingHours << ".\n";
}