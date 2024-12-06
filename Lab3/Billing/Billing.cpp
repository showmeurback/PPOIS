#include "Billing.h"
#include <iostream>

Billing::Billing(const Patient& patient, double amount)
    : patient(patient), amount(amount), status("Unpaid") {
}

void Billing::generateInvoice() {
    std::cout << "Invoice generated for " << patient.getName() << ": $" << amount << " - Status: " << status << "\n";
}

void Billing::processPayment(double paymentAmount) {
    if (paymentAmount >= amount) {
        status = "Paid";
        std::cout << "Payment of $" << paymentAmount << " processed. Status: " << status << "\n";
    }
    else {
        std::cout << "Insufficient payment. Remaining amount: $" << (amount - paymentAmount) << "\n";
    }
}