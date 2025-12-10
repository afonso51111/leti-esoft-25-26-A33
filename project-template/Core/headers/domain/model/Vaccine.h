#ifndef VACCINE_H
#define VACCINE_H

#include <string>
#include "VaccineType.h"

class Vaccine {
private:
    std::string commercial_name;
    std::string brand;
    VaccineType* type;

public:
    Vaccine(std::string commercialName, std::string brand, VaccineType* type);

    std::string getCommercialName() const;
    std::string getBrand() const;
    VaccineType* getType() const;

    virtual ~Vaccine() = default;
};

#endif // VACCINE_H