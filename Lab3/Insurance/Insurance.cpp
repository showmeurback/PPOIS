#include "Insurance.h"
#include <iostream>

Insurance::Insurance(const std::string& provider, const std::string& policyNumber, const std::string& coverageDetails)
    : provider(provider), policyNumber(policyNumber), coverageDetails(coverageDetails) {
}

void Insurance::updateCoverage(const std::string& newDetails) {
    coverageDetails = newDetails;
    std::cout << "Coverage details updated to: " << coverageDetails << "\n";
}