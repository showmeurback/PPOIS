#ifndef FLIGHTSCHEDULE_H
#define FLIGHTSCHEDULE_H

#include <vector>
#include "Flight.h"

class FlightSchedule {
public:
    std::vector<Flight> flights;

    void addFlight(const Flight& flight);
};

#endif // FLIGHTSCHEDULE_H