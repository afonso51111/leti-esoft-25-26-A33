#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include "SNSUser.h"

class Appointment {
private:
    SNSUser* user;
    std::string centerName;
    std::string vaccineType;
    std::string date;

public:
    Appointment(SNSUser* user, std::string centerName, std::string vaccineType, std::string date);

    SNSUser* getUser() const;
    std::string getCenterName() const;
    std::string getVaccineType() const;
    std::string getDate() const;
};

#endif // APPOINTMENT_H