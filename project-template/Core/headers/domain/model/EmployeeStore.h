#ifndef EMPLOYEESTORE_H
#define EMPLOYEESTORE_H

#include <vector>
#include <string>
#include "Employee.h"
#include "Nurse.h"
#include "Receptionist.h"

class EmployeeStore {
private:
    std::vector<Employee*> employees;

public:
    EmployeeStore();

    Employee* createEmployee(std::string name, std::string address, std::string phone, std::string email, std::string cc, std::string role);

    bool validateEmployee(Employee* emp) const;

    void saveEmployee(Employee* emp);

    std::vector<Employee*> getEmployees() const;

    ~EmployeeStore();
};

#endif