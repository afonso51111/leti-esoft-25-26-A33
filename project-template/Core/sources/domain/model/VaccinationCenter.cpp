#include "../../../headers/domain/model/VaccinationCenter.h"

VaccinationCenter::VaccinationCenter(std::string name, std::string addr, std::string phone, std::string email,
                                     std::string website, std::string open, std::string close, int cap)
    : name(name), postal_address(addr), phone_number(phone), email(email),
      website_address(website), opening_hours(open), closing_hours(close), capacity_per_hour(cap) {
}

std::string VaccinationCenter::getName() const {
    return name;
}