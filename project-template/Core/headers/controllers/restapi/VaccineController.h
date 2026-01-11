#ifndef VACCINECONTROLLER_H
#define VACCINECONTROLLER_H

#include <string>
#include "HttpResult.h"

class VaccineController {
public:
    VaccineController();

    HttpResult getAll();

    // CORRIGIDO: Adicionado o parâmetro 'code'
    HttpResult createVaccine(std::string code, std::string name, std::string brand, std::string typeCode);

    HttpResult updateVaccine(std::string code, std::string name, std::string brand, std::string typeCode);
    HttpResult deleteVaccine(std::string code);
};

#endif // VACCINECONTROLLER_H