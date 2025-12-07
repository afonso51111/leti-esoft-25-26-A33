#ifndef VACCINATIONCENTER_H
#define VACCINATIONCENTER_H

#include <string>
#include <vector>
#include "VaccineType.h"

class VaccinationCenter {
protected:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::string websiteAddress;
    std::string openingHours;
    std::string closingHours;
    int slotDuration;
    int maxVaccinesPerSlot;

public:
    VaccinationCenter(std::string name, std::string address, std::string phone, std::string email,
                      std::string website, std::string openHours, std::string closeHours,
                      int slotDur, int maxVac);

    std::string getName() const;

    virtual ~VaccinationCenter() = default;
};

#endif