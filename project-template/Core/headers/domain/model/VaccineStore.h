#ifndef VACCINESTORE_H
#define VACCINESTORE_H

#include <vector>
#include "Vaccine.h"

class VaccineStore {
private:
    std::vector<Vaccine*> listVaccines;

public:
    VaccineStore();

    // Atualizado para receber 'code'
    Vaccine* createVaccine(std::string code, std::string name, std::string brand, VaccineType* type);

    void saveVaccine(Vaccine* vaccine);
    std::vector<Vaccine*> getVaccines();
    Vaccine* findVaccineByCode(std::string code);

    // Novo método para apagar
    bool removeVaccine(std::string code);
};

#endif // VACCINESTORE_H