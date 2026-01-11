#include "../headers/VaccineTypeRouter.h"
#include "../../Core/headers/controllers/restapi/VaccineTypeController.h"

VaccineTypeRouter::VaccineTypeRouter() : RouterConfig("/api/vaccine-types") {}

void VaccineTypeRouter::configure(httplib::Server &svr) {

    // GET (Listar)
    svr.Get(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        VaccineTypeController ctrl;
        HttpResult result = ctrl.getAll();
        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });

    // POST (Criar)
    svr.Post(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("code") && req.has_param("desc")) {
             std::string code = req.get_param_value("code");
             std::string desc = req.get_param_value("desc");
             std::string tech = req.has_param("tech") ? req.get_param_value("tech") : "N/A";

             VaccineTypeController ctrl;
             HttpResult result = ctrl.createType(code, desc, tech);

             res.status = result.getStatus();
             res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("{\"error\": \"Missing parameters\"}", "application/json");
        }
    });

    // PUT (Atualizar) - NOVO
    svr.Put(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("code") && req.has_param("desc")) {
            std::string code = req.get_param_value("code");
            std::string desc = req.get_param_value("desc");

            VaccineTypeController ctrl;
            HttpResult result = ctrl.updateType(code, desc); // Chama o novo método

            res.status = result.getStatus();
            res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("{\"error\": \"Missing parameters (code, desc)\"}", "application/json");
        }
    });

    // DELETE (Apagar) - NOVO
    svr.Delete(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("code")) {
            std::string code = req.get_param_value("code");

            VaccineTypeController ctrl;
            HttpResult result = ctrl.deleteType(code); // Chama o novo método

            res.status = result.getStatus();
            res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("{\"error\": \"Missing parameter (code)\"}", "application/json");
        }
    });
}