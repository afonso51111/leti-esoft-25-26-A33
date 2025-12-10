#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name;
    std::string postal_address;
    std::string phone_number;
    std::string email;
    std::string citizen_card_number;

public:
    Employee(std::string name, std::string addr, std::string phone, std::string email, std::string cc);

    virtual ~Employee() = default;
};

#endif // EMPLOYEE_H