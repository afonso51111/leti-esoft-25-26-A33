#ifndef VACCINATIONCENTERSTORE_H
#define VACCINATIONCENTERSTORE_H

#include <vector>
#include "VaccinationCenter.h"
#include "HealthcareCenter.h"
#include "CommunityMassVaccinationCenter.h"

class VaccinationCenterStore {
private:
    std::vector<VaccinationCenter*> listCenters;

public:
    VaccinationCenterStore();

    VaccinationCenter* createHealthcareCenter(std::string name, std::string ars, std::string ages);

    VaccinationCenter* createCommunityCenter(std::string name, VaccineType* vt);

    bool validateVaccinationCenter(VaccinationCenter* center) const;
    void saveVaccinationCenter(VaccinationCenter* center);

    std::vector<VaccinationCenter*> getList() const;

    ~VaccinationCenterStore();
};

#endif
