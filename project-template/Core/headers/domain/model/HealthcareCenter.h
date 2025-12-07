#ifndef HEALTHCARECENTER_H
#define HEALTHCARECENTER_H

#include "VaccinationCenter.h"

class HealthcareCenter : public VaccinationCenter {
private:
    std::string ars;
    std::string ages;

public:
    HealthcareCenter(std::string name, std::string address, std::string phone, std::string email,
                     std::string website, std::string openHours, std::string closeHours,
                     int slotDur, int maxVac, std::string ars, std::string ages);
};

#endif