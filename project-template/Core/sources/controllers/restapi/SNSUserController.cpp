#include "../../../headers/controllers/restapi/SNSUserController.h"
#include <iostream>
#include "../../../headers/domain/model/SNSUser.h"
#include "../../../headers/domain/model/SNSUserStore.h"
#include <vector>

#include <iostream>

SNSUserController::SNSUserController() {}

HttpResult SNSUserController::getAll() {
    HttpResult result;
    Company* company = Company::getInstance();

    std::vector<SNSUser*> users = company->getSNSUserStore()->getAllUsers();

    std::string json = "[";
    for (size_t i = 0; i < users.size(); ++i) {
        SNSUser* u = users[i];

        json += "{";
        json += "\"name\": \"" + u->getName() + "\",";
        json += "\"snsNumber\": \"" + u->getSNSNumber() + "\",";
        json += "\"phoneNumber\": \"" + u->getPhoneNumber() + "\"";
        json += "}";

        if (i < users.size() - 1) {
            json += ",";
        }
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

    if (store->findUserBySNS(snsNum) != nullptr) {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: SNS User already exists.");
        return result;
    }

    SNSUser* newUser = store->createSNSUser(name, address, sex, phone, email, birthDate, snsNum, ccNum);

    if (store->validateSNSUser(newUser)) {
        store->saveSNSUser(newUser);
        result.setHttpStatus(HttpStatus::HTTP_CREATED);
        result.setResult("{ \"message\": \"SNS User registered successfully.\" }");
    } else {
        result.setHttpStatus(HttpStatus::HTTP_BAD_REQUEST);
        result.setResult("Error: Invalid data or duplicate fields (phone/email).");
    }

    return result;
}