#ifndef VACCINECONTROLLER_H
#define VACCINECONTROLLER_H

#include <string>
#include "HttpResult.h"
#include "../../domain/model/Company.h"

class VaccineController {
public:
    VaccineController();

    HttpResult getAll();

    HttpResult createVaccine(std::string name, std::string brand, std::string typeCode);
};

#endif