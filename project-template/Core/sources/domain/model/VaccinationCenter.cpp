#include "../../../headers/domain/model/VaccinationCenter.h"

VaccinationCenter::VaccinationCenter(std::string name, std::string addr, std::string phone, std::string email,
                                     std::string website, std::string open, std::string close, int cap)
    : name(name), postal_address(addr), phone_number(phone), email(email),
      website_address(website), opening_hours(open), closing_hours(close), capacity_per_hour(cap) {
}

std::string VaccinationCenter::getName() const {
    return name;
}

std::string VaccinationCenter::getAddress() const {
    return postal_address;
}

std::string VaccinationCenter::getPhoneNumber() const {
    return phone_number;
}

std::string VaccinationCenter::getEmail() const {
    return email;
}

std::string VaccinationCenter::getWebsite() const {
    return website_address;
}

std::string VaccinationCenter::getOpeningHours() const {
    return opening_hours;
}

std::string VaccinationCenter::getClosingHours() const {
    return closing_hours;
}

int VaccinationCenter::getCapacity() const {
    return capacity_per_hour;
}