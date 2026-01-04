#ifndef APPOINTMENTCONTROLLER_H
#define APPOINTMENTCONTROLLER_H

#include "controllers/restapi/HttpResult.h"
#include <string>

class AppointmentController {
public:
    AppointmentController();

    HttpResult getAll();

    HttpResult createAppointment(std::string snsNumber, std::string centerName, std::string vaccineType, std::string date, std::string time);
};

#endif // APPOINTMENTCONTROLLER_H