#ifndef COMMUNITYMASSVACCINATIONCENTER_H
#define COMMUNITYMASSVACCINATIONCENTER_H

#include "VaccinationCenter.h"
#include "VaccineType.h"

class CommunityMassVaccinationCenter : public VaccinationCenter {
private:
    VaccineType* vaccineType;

public:
    CommunityMassVaccinationCenter(std::string name, std::string address, std::string phone,
                                   std::string email, std::string website, std::string openHours,
                                   std::string closeHours, int slotDur, int maxVac,
                                   VaccineType* vType);
};

#endif