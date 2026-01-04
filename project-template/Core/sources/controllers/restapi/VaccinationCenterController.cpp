#include "../../Core/headers/controllers/restapi/VaccinationCenterController.h"
#include "../../Core/headers/domain/model/Company.h"
#include "../../Core/headers/domain/model/VaccinationCenterStore.h"
#include "../../Core/headers/domain/model/VaccinationCenter.h"
#include <iostream>

VaccinationCenterController::VaccinationCenterController() {}

HttpResult VaccinationCenterController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();

    auto centers = company->getVaccinationCenterStore()->getList();

    std::string json = "[";
    for (size_t i = 0; i < centers.size(); ++i) {
        VaccinationCenter* c = centers[i];

        json += "{";
        json += "\"name\": \"" + c->getName() + "\", ";
        json += "\"address\": \"" + c->getAddress() + "\", ";
        json += "\"email\": \"" + c->getEmail() + "\", ";
        json += "\"phone\": \"" + c->getPhoneNumber() + "\", ";
        json += "\"open\": \"" + c->getOpeningHours() + "\", ";
        json += "\"close\": \"" + c->getClosingHours() + "\"";
        json += "}";

        if (i < centers.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setResult(json);
    return result;
}