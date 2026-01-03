#include "../../../headers/controllers/restapi/VaccineController.h"
#include <iostream>
#include <vector>

#include "../../../headers/domain/model/Company.h"
#include "../../../headers/domain/model/Vaccine.h"
#include "../../../headers/domain/model/VaccineStore.h"
#include "../../../headers/domain/model/VaccineType.h"
#include "../../../headers/domain/model/VaccineTypeStore.h"


VaccineController::VaccineController() {}

HttpResult VaccineController::getAll() {
    HttpResult result;

    Company* company = Company::getInstance();
    auto vaccines = company->getVaccineStore()->getVaccines();

    std::string json = "[";
    for (size_t i = 0; i < vaccines.size(); ++i) {
        Vaccine* v = vaccines[i];
        json += "{";
        json += "\"commercialName\": \"" + v->getCommercialName() + "\",";
        json += "\"brand\": \"" + v->getBrand() + "\",";
        json += "\"typeCode\": \"" + v->getType()->getCode() + "\"";
        json += "}";

        if (i < vaccines.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setResult(json);
    return result;
}

HttpResult VaccineController::createVaccine(std::string name, std::string brand, std::string typeCode) {
    HttpResult result;
    Company* company = Company::getInstance();

    VaccineType* type = company->getVaccineTypeStore()->findTypeByCode(typeCode);

    if (type != nullptr) {

        Vaccine* newVaccine = company->getVaccineStore()->createVaccine(name, brand, type);

        if (company->getVaccineStore()->validateVaccine(newVaccine)) {
            company->getVaccineStore()->saveVaccine(newVaccine);

            result.setHttpStatus(HttpStatus::HTTP_CREATED);
            result.setResult("{ \"message\": \"Vaccine Created Successfully\" }");
        } else {
            result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
            result.setResult("Error: Vaccine validation failed (duplicated?).");
        }
    } else {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: Invalid Vaccine Type Code (" + typeCode + ").");
    }

    return result;
}