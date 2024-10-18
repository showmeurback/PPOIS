#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
public:
    std::string name;
    std::string passportNumber;
    int age;

    Passenger(std::string n, std::string p, int a);
};

#endif // PASSENGER_H