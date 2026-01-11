#include "../headers/VaccineRouter.h"
#include "../../Core/headers/controllers/restapi/VaccineController.h"

VaccineRouter::VaccineRouter() : RouterConfig("/api/vaccines") {}

void VaccineRouter::configure(httplib::Server &svr) {

    // 1. GET (Listar)
    svr.Get(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        VaccineController ctrl;
        HttpResult result = ctrl.getAll();
        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });

    // 2. POST (Criar) - CORRIGIDO (Agora pede 'code')
    svr.Post(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        // Verificamos se recebemos os 4 parâmetros necessários
        if (req.has_param("code") && req.has_param("name") && req.has_param("brand") && req.has_param("type")) {

            std::string code = req.get_param_value("code"); // Novo parametro
            std::string name = req.get_param_value("name");
            std::string brand = req.get_param_value("brand");
            std::string typeCode = req.get_param_value("type");

            VaccineController ctrl;
            // Chamamos o método createVaccine que agora aceita 4 argumentos
            HttpResult result = ctrl.createVaccine(code, name, brand, typeCode);

            res.status = result.getStatus();
            res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("{\"error\": \"Missing parameters (code, name, brand, type)\"}", "application/json");
        }
    });

    // 3. PUT (Atualizar)
    svr.Put(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("code") && req.has_param("name") && req.has_param("brand") && req.has_param("type")) {
            std::string code = req.get_param_value("code");
            std::string name = req.get_param_value("name");
            std::string brand = req.get_param_value("brand");
            std::string typeCode = req.get_param_value("type");

            VaccineController ctrl;
            HttpResult result = ctrl.updateVaccine(code, name, brand, typeCode);

            res.status = result.getStatus();
            res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("{\"error\": \"Missing parameters for update\"}", "application/json");
        }
    });

    // 4. DELETE (Apagar)
    svr.Delete(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("code")) {
            std::string code = req.get_param_value("code");

            VaccineController ctrl;
            HttpResult result = ctrl.deleteVaccine(code);

            res.status = result.getStatus();
            res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("{\"error\": \"Missing parameter (code)\"}", "application/json");
        }
    });
}