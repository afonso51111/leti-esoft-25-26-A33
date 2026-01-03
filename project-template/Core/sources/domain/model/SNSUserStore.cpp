#include "../../../headers/domain/model/SNSUserStore.h"

SNSUserStore::SNSUserStore() {
}

SNSUserStore::~SNSUserStore() {
    for (auto u : listUsers) {
        delete u;
    }
    listUsers.clear();
}

SNSUser* SNSUserStore::createSNSUser(std::string name, std::string address, std::string sex, std::string phone,
                                     std::string email, std::string birthDate, std::string snsNum, std::string ccNum) {
    return new SNSUser(name, address, sex, phone, email, birthDate, snsNum, ccNum);
}

bool SNSUserStore::validateSNSUser(SNSUser* user) const {
    if (user == nullptr) return false;

    for (auto existing : listUsers) {
        if (existing->getSNSNumber() == user->getSNSNumber() ||
            existing->getPhoneNumber() == user->getPhoneNumber()) {
            return false;
            }
    }
    return true;
}

void SNSUserStore::saveSNSUser(SNSUser* user) {
    if (validateSNSUser(user)) {
        listUsers.push_back(user);
    }
}

SNSUser* SNSUserStore::findUserBySNS(std::string snsNumber) const {
    for (auto user : listUsers) {
        if (user->getSNSNumber() == snsNumber) {
            return user;
        }
    }
    return nullptr;
}

std::vector<SNSUser*> SNSUserStore::getAllUsers() const {
    return listUsers;
}

