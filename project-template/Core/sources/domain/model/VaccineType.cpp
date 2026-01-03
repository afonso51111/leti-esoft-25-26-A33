#include "../../../headers/domain/model/VaccineType.h"

// Construtor
VaccineType::VaccineType(std::string code, std::string disease, std::string shortDesc)
    : code(code), disease(disease), short_description(shortDesc) {
}

// Getters
std::string VaccineType::getCode() const {
    return code;
}

std::string VaccineType::getDisease() const {
    return disease;
}

std::string VaccineType::getShortDescription() const {
    return short_description;
}

// Verifica compatibilidade (exemplo simples)
bool VaccineType::checkTechnology(std::string tech) const {
    return (code == tech) || (short_description.find(tech) != std::string::npos);
}