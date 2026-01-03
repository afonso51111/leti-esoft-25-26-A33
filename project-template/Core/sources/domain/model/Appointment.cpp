#include "../../../headers/domain/model/Appointment.h"
#include "../../../headers/domain/model/SNSUser.h"
#include "../../../headers/domain/model/VaccinationCenter.h"
#include "../../../headers/domain/model/VaccineType.h"

Appointment::Appointment(SNSUser* user, VaccinationCenter* center, VaccineType* type, std::string date, std::string time)
    : user(user), center(center), vaccineType(type), date(date), time(time) {
}

SNSUser* Appointment::getUser() const {
    return user;
}

VaccinationCenter* Appointment::getCenter() const {
    return center;
}

std::string Appointment::getDate() const {
    return date;
}

std::string Appointment::getTime() const {
    return time;
}