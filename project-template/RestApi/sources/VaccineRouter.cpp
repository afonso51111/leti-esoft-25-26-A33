#include "../headers/VaccineRouter.h"
#include "../../Core/headers/controllers/restapi/VaccineController.h"

VaccineRouter::VaccineRouter() : RouterConfig("/api/vaccines") {}

void VaccineRouter::configure(httplib::Server &svr) {

    svr.Get(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        VaccineController ctrl;
        HttpResult result = ctrl.getAll();

        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });

    svr.Post(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {

        if (req.has_param("name") && req.has_param("brand") && req.has_param("type")) {

            std::string name = req.get_param_value("name");
            std::string brand = req.get_param_value("brand");
            std::string typeCode = req.get_param_value("type");

            VaccineController ctrl;
            HttpResult result = ctrl.createVaccine(name, brand, typeCode);

            res.status = result.getStatus();
            res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("Missing parameters (name, brand, type)", "text/plain");
        }
    });
}