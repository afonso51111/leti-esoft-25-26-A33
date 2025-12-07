#ifndef SNSUSER_H
#define SNSUSER_H

#include <string>

class SNSUser {
private:
    std::string name;
    std::string address;
    std::string sex;
    std::string phoneNumber;
    std::string email;
    std::string birthDate;
    std::string snsNumber;
    std::string citizenCardNumber;

public:
    SNSUser(std::string name, std::string address, std::string sex, std::string phone,
            std::string email, std::string birthDate, std::string snsNum, std::string ccNum);

    std::string getName() const;
    std::string getSNSNumber() const;
    std::string getPhoneNumber() const;

    virtual ~SNSUser() = default;
};

#endif