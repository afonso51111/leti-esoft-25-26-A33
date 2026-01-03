#include "../../../headers/controllers/restapi/AppointmentController.h"
#include <iostream>
#include <vector>
#include "../../../headers/domain/model/Company.h"
#include "../../../headers/domain/model/AppointmentStore.h"
#include "../../../headers/domain/model/SNSUserStore.h"
#include "../../../headers/domain/model/VaccinationCenterStore.h"
#include "../../../headers/domain/model/VaccineTypeStore.h"
#include "../../../headers/domain/model/Appointment.h"
#include "../../../headers/domain/model/SNSUser.h"
#include "../../../headers/domain/model/VaccinationCenter.h"
#include "../../../headers/domain/model/VaccineType.h"

AppointmentController::AppointmentController() {}

HttpResult AppointmentController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();

    std::vector<Appointment*> appointments = company->getAppointmentStore()->getAll();

    std::string json = "[";
    for (size_t i = 0; i < appointments.size(); ++i) {
        Appointment* app = appointments[i];
        json += "{";
        json += "\"date\": \"" + app->getDate() + "\",";
        json += "\"time\": \"" + app->getTime() + "\",";

        if (app->getUser())
            json += "\"snsUser\": \"" + app->getUser()->getSNSNumber() + "\",";
        else
            json += "\"snsUser\": \"N/A\",";

        if (app->getCenter())
            json += "\"center\": \"" + app->getCenter()->getName() + "\"";
        else
            json += "\"center\": \"N/A\"";

        json += "}";

        if (i < appointments.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setResult(json);
    return result;
}

HttpResult AppointmentController::createAppointment(std::string snsNumber, std::string centerName,
                                                    std::string vaccineTypeCode, std::string date, std::string time) {
    HttpResult result;
    Company* company = Company::getInstance();

    SNSUser* user = company->getSNSUserStore()->findUserBySNS(snsNumber);
    if (user == nullptr) {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: SNS User not found (" + snsNumber + ").");
        return result;
    }

    VaccinationCenter* center = nullptr;
    std::vector<VaccinationCenter*> centers = company->getVaccinationCenterStore()->getList();
    for (VaccinationCenter* c : centers) {
        if (c->getName() == centerName) {
            center = c;
            break;
        }
    }

    if (center == nullptr) {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: Vaccination Center not found (" + centerName + ").");
        return result;
    }

    VaccineType* type = company->getVaccineTypeStore()->findTypeByCode(vaccineTypeCode);
    if (type == nullptr) {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: Vaccine Type not found (" + vaccineTypeCode + ").");
        return result;
    }

    Appointment* newApp = new Appointment(user, center, type, date, time);
    company->getAppointmentStore()->saveAppointment(newApp);

    result.setHttpStatus(HttpStatus::HTTP_CREATED);
    result.setResult("{ \"message\": \"Appointment scheduled successfully.\" }");
    return result;
}