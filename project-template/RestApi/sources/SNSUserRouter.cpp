#include "../headers/SNSUserRouter.h"
#include "../../Core/headers/controllers/restapi/SNSUserController.h"

SNSUserRouter::SNSUserRouter() : RouterConfig("/api/sns-users") {}

void SNSUserRouter::configure(httplib::Server &svr) {

    svr.Get(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        SNSUserController ctrl;
        HttpResult result = ctrl.getAll();
        res.status = result.getStatus();
        res.set_content(result.getBody(), "application/json");
    });

    svr.Post(this->baseResource, [](const httplib::Request &req, httplib::Response &res) {
        if (req.has_param("name") && req.has_param("sns") && req.has_param("cc")) {
             std::string name = req.get_param_value("name");
             std::string sns = req.get_param_value("sns");
             std::string cc = req.get_param_value("cc");
             std::string email = req.has_param("email") ? req.get_param_value("email") : "dummy@mail.com";
             std::string phone = req.has_param("phone") ? req.get_param_value("phone") : "910000000";

             SNSUserController ctrl;
             HttpResult result = ctrl.createUser(name, "Address", "Male", phone, email, "2000-01-01", sns, cc);

             res.status = result.getStatus();
             res.set_content(result.getBody(), "application/json");
        } else {
            res.status = 400;
            res.set_content("Missing required parameters (name, sns, cc)", "text/plain");
        }
    });
}