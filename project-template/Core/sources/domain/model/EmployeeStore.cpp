#include "../../../headers/domain/model/EmployeeStore.h"
#include <iostream>

EmployeeStore::EmployeeStore() {
}

EmployeeStore::~EmployeeStore() {
    for (auto emp : employees) {
        delete emp;
    }
    employees.clear();
}

Employee* EmployeeStore::createEmployee(std::string name, std::string address, std::string phone, std::string email, std::string cc, std::string role) {
    if (role == "Nurse") {
        return new Nurse(name, address, phone, email, cc);
    } else if (role == "Receptionist") {
        return new Receptionist(name, address, phone, email, cc);
    }
    return nullptr;
}

bool EmployeeStore::validateEmployee(Employee* emp) const {
    if (emp == nullptr) return false;

    // Aqui deverias validar duplicados (email, telefone)
    // Para isso precisarias de Getters na classe Employee (ex: getEmail())
    // Como no header que mandaste não tinhas getters, deixo simples:
    return true;
}

void EmployeeStore::saveEmployee(Employee* emp) {
    if (validateEmployee(emp)) {
        employees.push_back(emp);
    }
}

std::vector<Employee*> EmployeeStore::getEmployees() const {
    return employees;
}