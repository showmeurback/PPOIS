#ifndef FLIGHTATTENDANT_H
#define FLIGHTATTENDANT_H

#include "CrewMember.h"

class FlightAttendant : public CrewMember {
public:
    int yearsOfExperience;

    FlightAttendant(std::string n, std::string r, int exp);
};

#endif // FLIGHTATTENDANT_H