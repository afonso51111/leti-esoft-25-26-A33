#include "../../../headers/controllers/restapi/AppointmentController.h"
#include "../../../headers/domain/model/Company.h"
#include "../../../headers/domain/model/SNSUserStore.h"
#include "../../../headers/domain/model/VaccinationCenterStore.h"
#include "../../../headers/domain/model/VaccineTypeStore.h"
#include "../../../headers/domain/model/AppointmentStore.h"
#include <iostream>

AppointmentController::AppointmentController() {}

HttpResult AppointmentController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();

    auto appointments = company->getAppointmentStore()->getList();

    std::string json = "[";
    for (size_t i = 0; i < appointments.size(); ++i) {
        Appointment* app = appointments[i];
        json += "{";
        json += "\"sns\": \"" + app->getUser()->getSNSNumber() + "\", ";
        json += "\"center\": \"" + app->getCenterName() + "\", ";
        json += "\"vaccine\": \"" + app->getVaccineType() + "\", ";
        json += "\"date\": \"" + app->getDate() + "\"";
        json += "}";
        if (i < appointments.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setResult(json);
    return result;
}

HttpResult AppointmentController::createAppointment(std::string snsNumber, std::string centerName, std::string vaccineType, std::string date, std::string time) {
    HttpResult result;
    Company* company = Company::getInstance();

    SNSUserStore* userStore = company->getSNSUserStore();
    SNSUser* user = userStore->findUserBySNS(snsNumber);
    if (user == nullptr) {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("{\"message\": \"User not found\"}");
        return result;
    }

    std::string fullDate = date + " " + time;

    AppointmentStore* appStore = company->getAppointmentStore();

    bool success = appStore->createAppointment(user, centerName, vaccineType, fullDate);

    if (success) {
        result.setHttpStatus(HttpStatus::HTTP_OK);
        result.setResult("{\"message\": \"Appointment scheduled successfully\"}");
    } else {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("{\"message\": \"Error scheduling appointment\"}");
    }

    return result;
}