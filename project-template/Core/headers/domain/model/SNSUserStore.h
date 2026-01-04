#ifndef SNSUSERSTORE_H
#define SNSUSERSTORE_H

#include <vector>
#include "SNSUser.h"

class SNSUserStore {
private:
    std::vector<SNSUser*> listUsers;

public:
    SNSUserStore();
    virtual ~SNSUserStore();

    SNSUser* createSNSUser(std::string name, std::string address, std::string sex,
                           std::string phone, std::string email, std::string birthDate,
                           std::string snsNum, std::string ccNum);

    void saveSNSUser(SNSUser* user);

    std::vector<SNSUser*> getList() const;
    SNSUser* findUserBySNS(std::string snsNumber) const;
};

#endif // SNSUSERSTORE_H