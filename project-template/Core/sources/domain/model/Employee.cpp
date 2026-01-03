#include "../../../headers/domain/model/Employee.h"

Employee::Employee(std::string name, std::string addr, std::string phone, std::string email, std::string cc)
    : name(name), postal_address(addr), phone_number(phone), email(email), citizen_card_number(cc) {
}