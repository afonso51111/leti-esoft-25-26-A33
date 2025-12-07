#ifndef NURSE_H
#define NURSE_H

#include "Employee.h"

class Nurse : public Employee {
public:
    Nurse(std::string name, std::string address, std::string phone, std::string email, std::string cc);
};

#endif