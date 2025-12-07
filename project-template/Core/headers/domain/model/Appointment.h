#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class SNSUser;
class VaccinationCenter;
class VaccineType;

class Appointment {
private:
    SNSUser* user;
    VaccinationCenter* center;
    VaccineType* vaccineType;
    std::string date;
    std::string time;

public:
    Appointment(SNSUser* user, VaccinationCenter* center, VaccineType* type, std::string date, std::string time);

    SNSUser* getUser() const;
    VaccinationCenter* getCenter() const;
    std::string getDate() const;
    std::string getTime() const;

    virtual ~Appointment() = default;
};

#endif