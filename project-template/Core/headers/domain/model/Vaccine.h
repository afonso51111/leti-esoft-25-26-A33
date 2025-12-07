#ifndef VACCINE_H
#define VACCINE_H

#include <string>
#include "VaccineType.h"

class Vaccine {
private:
    std::string name;
    std::string brand;
    VaccineType* type;

public:
    Vaccine(std::string name, std::string brand, VaccineType* type);

    std::string getName() const;
    std::string getBrand() const;
    VaccineType* getType() const;

    virtual ~Vaccine() = default;
};

#endif