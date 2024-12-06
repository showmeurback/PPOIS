#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class Visitor {
public:
    Visitor(const std::string& name, const std::string& relationship, const std::string& visitingHours);
    void requestVisit();

private:
    std::string name;
    std::string relationship;
    std::string visitingHours;
};

#endif // VISITOR_H