#ifndef CHECKIN_H
#define CHECKIN_H

#include "Passenger.h"
#include "Baggage.h"

class CheckIn {
public:
    void checkInPassenger(Passenger passenger, Baggage baggage);
};

#endif // CHECKIN_H