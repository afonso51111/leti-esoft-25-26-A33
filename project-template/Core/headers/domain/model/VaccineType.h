#ifndef VACCINETYPE_H
#define VACCINETYPE_H

#include <string>

class VaccineType {
private:
    std::string code;
    std::string disease;
    std::string short_description;

public:
    VaccineType(std::string code, std::string disease, std::string shortDesc);

    std::string getCode() const;
    std::string getDisease() const;
    std::string getShortDescription() const;

    // Método extra para verificar compatibilidade (útil para o Sprint 3)
    bool checkTechnology(std::string tech) const;
};

#endif // VACCINETYPE_H