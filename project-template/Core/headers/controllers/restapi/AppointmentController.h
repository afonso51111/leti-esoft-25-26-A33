#ifndef APPOINTMENTCONTROLLER_H
#define APPOINTMENTCONTROLLER_H

#include <string>
#include "HttpResult.h"
#include "../../domain/model/Company.h"

class AppointmentController {
public:
    AppointmentController();

    HttpResult getAll();

    HttpResult createAppointment(std::string snsNumber, std::string centerName,
                                 std::string vaccineTypeCode, std::string date, std::string time);
};

#endif