#include "../../../headers/domain/model/SNSUser.h"

SNSUser::SNSUser(std::string name, std::string address, std::string sex, std::string phone,
                 std::string email, std::string birthDate, std::string snsNum, std::string ccNum)
    : name(name), address(address), sex(sex), phoneNumber(phone), email(email),
      birthDate(birthDate), snsNumber(snsNum), citizenCardNumber(ccNum) {
}

std::string SNSUser::getName() const {
    return name;
}

std::string SNSUser::getSNSNumber() const {
    return snsNumber;
}

std::string SNSUser::getPhoneNumber() const {
    return phoneNumber;
}