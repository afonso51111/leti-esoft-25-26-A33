#ifndef SNSUSERSTORE_H
#define SNSUSERSTORE_H

#include <vector>
#include "SNSUser.h"

class SNSUserStore {
private:
    std::vector<SNSUser*> listUsers;

public:
    SNSUserStore();

    SNSUser* createSNSUser(std::string name, std::string address, std::string sex, std::string phone,
                           std::string email, std::string birthDate, std::string snsNum, std::string ccNum);

    bool validateSNSUser(SNSUser* user) const;

    void saveSNSUser(SNSUser* user);

    SNSUser* findUserBySNS(std::string snsNumber) const;

    std::vector<SNSUser*> getAllUsers() const;

    ~SNSUserStore();
};

#endif