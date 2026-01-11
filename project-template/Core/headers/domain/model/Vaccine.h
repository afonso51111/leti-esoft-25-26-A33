#ifndef VACCINE_H
#define VACCINE_H

#include <string>
#include "VaccineType.h"

class Vaccine {
private:
    std::string code;            // Novo: Código da vacina
    std::string commercial_name;
    std::string brand;
    VaccineType* type;

public:
    // Construtor atualizado
    Vaccine(std::string code, std::string commercialName, std::string brand, VaccineType* type);

    std::string getCode() const;
    std::string getCommercialName() const;
    std::string getBrand() const;
    VaccineType* getType() const;

    // Setters para editar (Update)
    void setCommercialName(std::string name);
    void setBrand(std::string brand);

    virtual ~Vaccine() = default;
};

#endif // VACCINE_H