#include "../../../headers/controllers/restapi/VaccineTypeController.h"
#include <iostream>
#include "../../../headers/domain/model/Company.h"
#include "../../../headers/domain/model/VaccineTypeStore.h"
#include "../../../headers/domain/model/VaccineType.h"

VaccineTypeController::VaccineTypeController() {}

HttpResult VaccineTypeController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();

    auto types = company->getVaccineTypeStore()->getVaccineTypes();

    std::string json = "[";
    for (size_t i = 0; i < types.size(); ++i) {
        VaccineType* vt = types[i];
        json += "{";
        json += "\"code\": \"" + vt->getCode() + "\",";
        json += "\"description\": \"" + vt->getShortDescription() + "\"";
        json += "}";

        if (i < types.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setResult(json);
    return result;
}

HttpResult VaccineTypeController::createType(std::string code, std::string description, std::string tech) {
    HttpResult result;
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    if (store->findTypeByCode(code) != nullptr) {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: Vaccine Type Code already exists.");
        return result;
    }

    VaccineType* newType = store->createVaccineType(code, description, tech);

    if (store->validateVaccineType(newType)) {
        store->saveVaccineType(newType);
        result.setHttpStatus(HttpStatus::HTTP_CREATED);
        result.setResult("{ \"message\": \"Vaccine Type created successfully.\" }");
    } else {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: Invalid data.");
    }

    return result;
}