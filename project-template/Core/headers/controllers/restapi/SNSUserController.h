#ifndef SNSUSERCONTROLLER_H
#define SNSUSERCONTROLLER_H

#include "HttpResult.h"
#include "../../domain/model/Company.h"

class SNSUserController {
public:
    SNSUserController();

    HttpResult getAll();

    HttpResult createUser(std::string name, std::string address, std::string sex,
                          std::string phone, std::string email, std::string birthDate,
                          std::string snsNum, std::string ccNum);
};

#endif