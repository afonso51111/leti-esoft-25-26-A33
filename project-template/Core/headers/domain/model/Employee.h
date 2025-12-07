#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
protected:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::string citizenCardNumber;

public:
    Employee(std::string name, std::string address, std::string phone, std::string email, std::string cc);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    virtual ~Employee() = default;
};

#endif