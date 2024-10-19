#ifndef PILOT_H
#define PILOT_H

#include "CrewMember.h"

class Pilot : public CrewMember {
public:
    int licenseNumber;

    Pilot(std::string n, std::string r, int ln);
};

#endif // PILOT_H