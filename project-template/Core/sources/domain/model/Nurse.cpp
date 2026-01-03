#include "../../../headers/domain/model/Nurse.h"

Nurse::Nurse(std::string name, std::string address, std::string phone, std::string email, std::string cc)
    : Employee(name, address, phone, email, cc) {
}