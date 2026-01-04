#include "../../../headers/domain/model/VaccinationCenterStore.h"
#include "../../../headers/domain/model/HealthcareCenter.h"

VaccinationCenterStore::VaccinationCenterStore() {
    // Construtor vazio
}

VaccinationCenterStore::~VaccinationCenterStore() {
    // Destrutor: Limpar memória
    for (auto center : listCenters) {
        delete center;
    }
    listCenters.clear();
}

std::vector<VaccinationCenter*> VaccinationCenterStore::getList() const {
    return listCenters;
}


void VaccinationCenterStore::saveVaccinationCenter(VaccinationCenter* center) {
    listCenters.push_back(center);
}

VaccinationCenter* VaccinationCenterStore::createHealthcareCenter(std::string name, std::string ars, std::string ages) {
    return new HealthcareCenter(name, "Morada Default", "000000000", "email@sns.pt", "www.sns.pt", "08:00", "20:00", 100, ars, ages);
}

