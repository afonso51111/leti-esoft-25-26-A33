#ifndef VACCINATIONCENTER_H
#define VACCINATIONCENTER_H

#include <string>
#include <vector>
#include "WaitingRoom.h"
#include "RecoveryRoom.h"

class VaccinationCenter {
protected:
    std::string name;
    std::string postal_address;
    std::string phone_number;
    std::string email;
    std::string website_address;
    std::string opening_hours;
    std::string closing_hours;
    int capacity_per_hour;

    WaitingRoom waitingRoom;
    RecoveryRoom recoveryRoom;

public:
    VaccinationCenter(std::string name, std::string addr, std::string phone, std::string email,
                       std::string website, std::string open, std::string close, int cap);

    std::string getName() const;

    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getWebsite() const;
    std::string getOpeningHours() const;
    std::string getClosingHours() const;
    int getCapacity() const;

    virtual ~VaccinationCenter() = default;
};

#endif // VACCINATIONCENTER_H