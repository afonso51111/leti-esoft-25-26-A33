#include "../../../headers/domain/model/Appointment.h"

Appointment::Appointment(SNSUser* user, std::string centerName, std::string vaccineType, std::string date)
    : user(user), centerName(centerName), vaccineType(vaccineType), date(date) {}

SNSUser* Appointment::getUser() const { return user; }
std::string Appointment::getCenterName() const { return centerName; }
std::string Appointment::getVaccineType() const { return vaccineType; }
std::string Appointment::getDate() const { return date; }