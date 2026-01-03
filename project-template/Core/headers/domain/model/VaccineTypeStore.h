#ifndef VACCINETYPESTORE_H
#define VACCINETYPESTORE_H

#include <vector>
#include "VaccineType.h"

class VaccineTypeStore {
private:
    std::vector<VaccineType*> listVaccineTypes;

public:
    VaccineTypeStore();

    VaccineType* createVaccineType(std::string code, std::string description, std::string technology);

    bool validateVaccineType(VaccineType* vt) const;

    void saveVaccineType(VaccineType* vt);

    std::vector<VaccineType*> getVaccineTypes() const;

    ~VaccineTypeStore();

    VaccineType* findTypeByCode(std::string code) const;
};

#endif