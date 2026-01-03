#include "../../../headers/domain/model/VaccinationCenterStore.h"

VaccinationCenterStore::VaccinationCenterStore() {
}

VaccinationCenterStore::~VaccinationCenterStore() {
    for (auto c : listCenters) {
        delete c;
    }
    listCenters.clear();
}

VaccinationCenter* VaccinationCenterStore::createHealthcareCenter(std::string name, std::string ars, std::string ages) {
    return new HealthcareCenter(name, "Address", "910000000", "email@center.com", "website.com", "08:00", "20:00", 30, 100, ars, ages);
}

VaccinationCenter* VaccinationCenterStore::createCommunityCenter(std::string name, VaccineType* vt) {
    return new CommunityMassVaccinationCenter(name, "Address", "910000000", "email@center.com", "website.com", "08:00", "20:00", 30, 100, vt);
}

bool VaccinationCenterStore::validateVaccinationCenter(VaccinationCenter* center) const {
    if (center == nullptr) return false;
    for (auto c : listCenters) {
        if (c->getName() == center->getName()) {
            return false;
        }
    }
    return true;
}

void VaccinationCenterStore::saveVaccinationCenter(VaccinationCenter* center) {
    if (validateVaccinationCenter(center)) {
        listCenters.push_back(center);
    }
}

std::vector<VaccinationCenter*> VaccinationCenterStore::getList() const {
    return listCenters;
}