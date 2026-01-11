#include "../../../headers/domain/model/VaccineType.h"

VaccineType::VaccineType(std::string code, std::string description, std::string technology)
    : code(code), description(description), technology(technology) {}

std::string VaccineType::getCode() const { return code; }
std::string VaccineType::getShortDescription() const { return description; }
std::string VaccineType::getTechnology() const { return technology; }

// CORRIGIDO: Implementação do setter
void VaccineType::setDescription(std::string description) {
    this->description = description;
}