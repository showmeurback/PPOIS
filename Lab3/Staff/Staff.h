#ifndef STAFF_H
#define STAFF_H

#include <string>

class Staff {
public:
    Staff(const std::string& name, const std::string& role, const std::string& phone);
    std::string getName() const;
    void assignToDepartment(const std::string& departmentName);

private:
    std::string name;
    std::string role;
    std::string phone;
    std::string department;
};

#endif // STAFF_H