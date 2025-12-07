#ifndef VACCINESTORE_H
#define VACCINESTORE_H

#include <vector>
#include "Vaccine.h"

class VaccineStore {
private:
    std::vector<Vaccine*> listVaccines;

public:
    VaccineStore();

    Vaccine* createVaccine(std::string name, std::string brand, VaccineType* type);

    bool validateVaccine(Vaccine* v) const;

    void saveVaccine(Vaccine* v);

    std::vector<Vaccine*> getVaccines() const;

    ~VaccineStore();
};

#endif