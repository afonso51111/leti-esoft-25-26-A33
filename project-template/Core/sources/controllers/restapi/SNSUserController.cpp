#include "../../Core/headers/controllers/restapi/SNSUserController.h"
#include "../../Core/headers/domain/model/Company.h"
#include "../../Core/headers/domain/model/SNSUserStore.h"
#include "../../Core/headers/domain/model/SNSUser.h"
#include <iostream>

SNSUserController::SNSUserController() {}

HttpResult SNSUserController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();

    auto users = company->getSNSUserStore()->getList();

    std::string json = "[";
    for (size_t i = 0; i < users.size(); ++i) {
        SNSUser* u = users[i];
        json += "{";
        json += "\"name\": \"" + u->getName() + "\", ";
        json += "\"sns\": \"" + u->getSNSNumber() + "\", ";
        json += "\"phone\": \"" + u->getPhoneNumber() + "\"";
        json += "}";
        if (i < users.size() - 1) json += ",";
    }
    json += "]";

    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setResult(json);
    return result;
}

HttpResult SNSUserController::createUser(std::string name, std::string address, std::string sex,
                                         std::string phone, std::string email, std::string birthDate,
                                         std::string snsNum, std::string ccNum) {
    HttpResult result;
    Company* company = Company::getInstance();
    SNSUserStore* store = company->getSNSUserStore();

    SNSUser* newUser = store->createSNSUser(name, address, sex, phone, email, birthDate, snsNum, ccNum);

    if (newUser != nullptr) {
        store->saveSNSUser(newUser); // Guardamos na lista
        result.setHttpStatus(HttpStatus::HTTP_OK);
        result.setResult("{\"message\": \"User created successfully\"}");
    } else {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("{\"message\": \"Error creating user\"}");
    }

    return result;
}