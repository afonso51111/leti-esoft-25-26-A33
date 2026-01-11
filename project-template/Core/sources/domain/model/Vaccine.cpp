#include "../../../headers/domain/model/Vaccine.h"

Vaccine::Vaccine(std::string code, std::string commercialName, std::string brand, VaccineType* type)
    : code(code), commercial_name(commercialName), brand(brand), type(type) {
}

std::string Vaccine::getCode() const {
    return code;
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

void Vaccine::setCommercialName(std::string name) {
    this->commercial_name = name;
}

void Vaccine::setBrand(std::string brand) {
    this->brand = brand;
}