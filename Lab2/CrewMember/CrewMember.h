#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>

class CrewMember {
public:
    std::string name;
    std::string role;

    CrewMember(std::string n, std::string r);
};

#endif // CREWMEMBER_H