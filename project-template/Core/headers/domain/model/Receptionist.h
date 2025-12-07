#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Employee.h"

class Receptionist : public Employee {
public:
    Receptionist(std::string name, std::string address, std::string phone, std::string email, std::string cc);
};

#endif