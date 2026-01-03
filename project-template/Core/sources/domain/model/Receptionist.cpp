#include "../../../headers/domain/model/Receptionist.h"

Receptionist::Receptionist(std::string name, std::string address, std::string phone, std::string email, std::string cc)
    : Employee(name, address, phone, email, cc) {
}