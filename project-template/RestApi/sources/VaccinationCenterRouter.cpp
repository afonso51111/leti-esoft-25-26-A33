#include "../headers/VaccinationCenterRouter.h"
#include "../../Core/headers/controllers/restapi/VaccinationCenterController.h"
#include <iostream>

VaccinationCenterRouter::VaccinationCenterRouter() : RouterConfig("/api/centers") {}

void VaccinationCenterRouter::configure(httplib::Server &svr) {

    svr.Get("/api/centers", [](const httplib::Request &req, httplib::Response &res) {
        VaccinationCenterController ctrl;
        HttpResult result = ctrl.getAll();

        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });
}