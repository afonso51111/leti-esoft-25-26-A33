#include "../../../headers/domain/model/Vaccine.h"

Vaccine::Vaccine(std::string commercialName, std::string brand, VaccineType* type)
    : commercial_name(commercialName), brand(brand), type(type) {
}

std::string Vaccine::getCommercialName() const {
    return commercial_name;
}

std::string Vaccine::getBrand() const {
    return brand;
}

VaccineType* Vaccine::getType() const {
    return type;
}