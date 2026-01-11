#include "../../../headers/domain/model/VaccineTypeStore.h"
#include "../../../headers/domain/model/VaccineType.h"

VaccineTypeStore::VaccineTypeStore() {
}

VaccineTypeStore::~VaccineTypeStore() {
    for (auto vt : listVaccineTypes) {
        delete vt;
    }
    listVaccineTypes.clear();
}

VaccineType* VaccineTypeStore::createVaccineType(std::string code, std::string description, std::string technology) {
    return new VaccineType(code, technology, description);
}

bool VaccineTypeStore::validateVaccineType(VaccineType* vt) const {
    if (vt == nullptr) return false;

    for (auto existing : listVaccineTypes) {
        if (existing->getCode() == vt->getCode()) {
            return false;
        }
    }
    return true;
}

void VaccineTypeStore::saveVaccineType(VaccineType* vt) {
    validateVaccineType(vt);
    listVaccineTypes.push_back(vt);
}

std::vector<VaccineType*> VaccineTypeStore::getVaccineTypes() const {
    return listVaccineTypes;
}

// --- O MÉTODO NOVO QUE PRECISAS PARA A API ---
VaccineType* VaccineTypeStore::findTypeByCode(std::string code) const {
    for (auto vt : listVaccineTypes) {
        if (vt->getCode() == code) {
            return vt;
        }
    }
    return nullptr;
}

bool VaccineTypeStore::removeType(std::string code) {
    for (auto it = listVaccineTypes.begin(); it != listVaccineTypes.end(); ++it) {
        if ((*it)->getCode() == code) {
            // Opcional: delete *it; // Descomenta se quiseres libertar memória (recomendado em C++)
            listVaccineTypes.erase(it);
            return true; // Apagado com sucesso
        }
    }
    return false; // Não encontrado
}