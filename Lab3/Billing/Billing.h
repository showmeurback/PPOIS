#ifndef BILLING_H
#define BILLING_H

#include <string>
#include "Patient.h"

class Billing {
public:
    Billing(const Patient& patient, double amount);
    void generateInvoice();
    void processPayment(double amount);

private:
    Patient patient;
    double amount;
    std::string status;
};

#endif // BILLING_H