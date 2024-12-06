#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <string>

class Emergency {
public:
    Emergency(const std::string& code, const std::string& description);
    void activateEmergency();
    void assignResponseTeam(const std::string& teamName);

private:
    std::string code;
    std::string description;
    std::string responseTeam;
};

#endif // EMERGENCY_H