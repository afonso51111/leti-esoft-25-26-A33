#include "../headers/VaccineTypeRouter.h"
// Inclui o controlador (verifica se tens este ficheiro no Core também!)
#include "../../Core/headers/controllers/restapi/VaccineTypeController.h"

VaccineTypeRouter::VaccineTypeRouter() : RouterConfig("/api/vaccine-types") {}

void VaccineTypeRouter::configure(httplib::Server &svr) {

    // GET: Listar Tipos
    svr.Get(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        VaccineTypeController ctrl;
        HttpResult result = ctrl.getAll();
        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });

    // POST: Criar Tipo
    // Exemplo: /api/vaccine-types?code=COV&desc=Covid&tech=mRNA
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
            res.set_content("Missing parameters (code, desc)", "text/plain");
        }
    });
}