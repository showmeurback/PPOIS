#ifndef INSURANCE_H
#define INSURANCE_H

#include <string>

class Insurance {
public:
    Insurance(const std::string& provider, const std::string& policyNumber, const std::string& coverageDetails);
    void updateCoverage(const std::string& newDetails);

private:
    std::string provider;
    std::string policyNumber;
    std::string coverageDetails;
};

#endif // INSURANCE_H