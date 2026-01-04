#ifndef HEALTHCARECENTER_H
#define HEALTHCARECENTER_H

#include <string>
#include "VaccinationCenter.h"

class HealthcareCenter : public VaccinationCenter {
private:
    std::string ars;
    std::string ages;

public:

    HealthcareCenter(std::string name, std::string addr, std::string phone, std::string email,
                     std::string website, std::string open, std::string close, int cap,
                     std::string ars, std::string ages);

    std::string getArs() const;
    std::string getAges() const;
};

#endif // HEALTHCARECENTER_H