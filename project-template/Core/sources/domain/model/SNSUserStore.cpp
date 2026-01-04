#include "../../../headers/domain/model/SNSUserStore.h"

SNSUserStore::SNSUserStore() {}

SNSUserStore::~SNSUserStore() {
    for (auto user : listUsers) {
        delete user;
    }
    listUsers.clear();
}

std::vector<SNSUser*> SNSUserStore::getList() const {
    return listUsers;
}

void SNSUserStore::saveSNSUser(SNSUser* user) {
    listUsers.push_back(user);
}

SNSUser* SNSUserStore::createSNSUser(std::string name, std::string address, std::string sex,
                                     std::string phone, std::string email, std::string birthDate,
                                     std::string snsNum, std::string ccNum) {
    return new SNSUser(name, address, sex, phone, email, birthDate, snsNum, ccNum);
}

SNSUser* SNSUserStore::findUserBySNS(std::string snsNumber) const {
    for (SNSUser* user : listUsers) {
        if (user->getSNSNumber() == snsNumber) {
            return user;
        }
    }
    return nullptr;
}