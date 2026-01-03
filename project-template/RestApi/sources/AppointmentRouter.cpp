#include "../headers/AppointmentRouter.h"
#include "../../Core/headers/controllers/restapi/AppointmentController.h"

AppointmentRouter::AppointmentRouter() : RouterConfig("/api/appointments") {}

void AppointmentRouter::configure(httplib::Server &svr) {

    svr.Get(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        AppointmentController ctrl;
        HttpResult result = ctrl.getAll();
        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });

    svr.Post(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("sns") && req.has_param("center") && req.has_param("type")) {
             std::string sns = req.get_param_value("sns");
             std::string center = req.get_param_value("center");
             std::string type = req.get_param_value("type");
             std::string date = req.has_param("date") ? req.get_param_value("date") : "2025-01-01";
             std::string time = req.has_param("time") ? req.get_param_value("time") : "09:00";

             AppointmentController ctrl;
             HttpResult result = ctrl.createAppointment(sns, center, type, date, time);

             res.status = result.getStatus();
             res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("Missing required parameters (sns, center, type)", "text/plain");
        }
    });
}