#include "../../../headers/domain/model/VaccineStore.h"
#include "../../../headers/domain/model/Vaccine.h"

VaccineStore::VaccineStore() {}

Vaccine* VaccineStore::createVaccine(std::string code, std::string name, std::string brand, VaccineType* type) {
    // Passa o 'code' para a vacina nova
    return new Vaccine(code, name, brand, type);
}

void VaccineStore::saveVaccine(Vaccine* vaccine) {
    listVaccines.push_back(vaccine);
}

std::vector<Vaccine*> VaccineStore::getVaccines() {
    return listVaccines;
}

Vaccine* VaccineStore::findVaccineByCode(std::string code) {
    for (Vaccine* v : listVaccines) {
        if (v->getCode() == code) {
            return v;
        }
    }
    return nullptr;
}

bool VaccineStore::removeVaccine(std::string code) {
    for (auto it = listVaccines.begin(); it != listVaccines.end(); ++it) {
        if ((*it)->getCode() == code) {
            // delete *it; // (Opcional: liberta memória)
            listVaccines.erase(it);
            return true;
        }
    }
    return false;
}