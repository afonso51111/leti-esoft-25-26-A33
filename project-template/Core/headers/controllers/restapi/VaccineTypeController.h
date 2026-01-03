#ifndef VACCINETYPECONTROLLER_H
#define VACCINETYPECONTROLLER_H

#include <string>
#include "HttpResult.h"
#include "../../domain/model/Company.h"

class VaccineTypeController {
public:
    VaccineTypeController();

    HttpResult getAll();

    HttpResult createType(std::string code, std::string description, std::string tech);
};

#endif