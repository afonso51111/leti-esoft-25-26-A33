#include "../../../headers/controllers/restapi/VaccineController.h"
#include "../../../headers/domain/model/Company.h"
#include "../../../headers/domain/model/VaccineStore.h"
#include "../../../headers/domain/model/VaccineTypeStore.h"
#include "../../../headers/domain/model/Vaccine.h"

VaccineController::VaccineController() {}

HttpResult VaccineController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();
    auto vaccines = company->getVaccineStore()->getVaccines();

    std::string json = "[";
    for (size_t i = 0; i < vaccines.size(); ++i) {
        Vaccine* v = vaccines[i];
        json += "{";
        json += "\"code\": \"" + v->getCode() + "\",";
        json += "\"name\": \"" + v->getCommercialName() + "\",";
        json += "\"brand\": \"" + v->getBrand() + "\"";
        json += "}";
        if (i < vaccines.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(200);
    result.setResult(json);
    return result;
}

HttpResult VaccineController::createVaccine(std::string code, std::string name, std::string brand, std::string typeCode) {
    HttpResult result;
    Company* company = Company::getInstance();
    VaccineStore* store = company->getVaccineStore();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();

    if (store->findVaccineByCode(code) != nullptr) {
        result.setHttpStatus(400);
        result.setResult("Error: Vaccine Code already exists.");
        return result;
    }

    VaccineType* type = typeStore->findTypeByCode(typeCode);
    if (type == nullptr) {
        result.setHttpStatus(400);
        result.setResult("Error: Invalid Vaccine Type Code.");
        return result;
    }

    Vaccine* vaccine = store->createVaccine(code, name, brand, type);
    store->saveVaccine(vaccine);

    result.setHttpStatus(201);
    result.setResult("{ \"message\": \"Vaccine created successfully\" }");
    return result;
}

HttpResult VaccineController::updateVaccine(std::string code, std::string name, std::string brand, std::string typeCode) {
    HttpResult result;
    Company* company = Company::getInstance();
    VaccineStore* store = company->getVaccineStore();

    Vaccine* vaccine = store->findVaccineByCode(code);

    if (vaccine != nullptr) {
        vaccine->setCommercialName(name);
        vaccine->setBrand(brand);

        result.setHttpStatus(200);
        result.setResult("{ \"message\": \"Vaccine updated successfully.\" }");
    } else {
        result.setHttpStatus(404);
        result.setResult("{ \"error\": \"Vaccine not found.\" }");
    }
    return result;
}

HttpResult VaccineController::deleteVaccine(std::string code) {
    HttpResult result;
    Company* company = Company::getInstance();
    VaccineStore* store = company->getVaccineStore();

    bool success = store->removeVaccine(code);

    if (success) {
        result.setHttpStatus(200);
        result.setResult("{ \"message\": \"Vaccine deleted successfully\" }");
    } else {
        result.setHttpStatus(404);
        result.setResult("{ \"error\": \"Vaccine not found.\" }");
    }
    return result;
}