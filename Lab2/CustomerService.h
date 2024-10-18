#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include "Passenger.h"
#include <string>
#include <iostream>

class CustomerService {
public:
    void assistPassenger(const Passenger& passenger);
};

#endif // CUSTOMERSERVICE_H