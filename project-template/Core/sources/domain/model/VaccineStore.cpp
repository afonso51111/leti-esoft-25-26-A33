#include "../../../headers/domain/model/VaccineStore.h"

VaccineStore::VaccineStore() {
}

VaccineStore::~VaccineStore() {
    for (auto v : listVaccines) {
        delete v;
    }
    listVaccines.clear();
}

Vaccine* VaccineStore::createVaccine(std::string name, std::string brand, VaccineType* type) {
    return new Vaccine(name, brand, type);
}

bool VaccineStore::validateVaccine(Vaccine* v) const {
    if (v == nullptr) return false;

    for (auto existing : listVaccines) {
        if (existing->getCommercialName() == v->getCommercialName() &&
            existing->getBrand() == v->getBrand()) {
            return false;
            }
    }
    return true;
}

void VaccineStore::saveVaccine(Vaccine* v) {
    listVaccines.push_back(v);
}

std::vector<Vaccine*> VaccineStore::getVaccines() const {
    return listVaccines;
}