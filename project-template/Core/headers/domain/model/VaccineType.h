#ifndef VACCINETYPE_H
#define VACCINETYPE_H

#include <string>

class VaccineType {
private:
    std::string code;
    std::string description;
    std::string technology;

public:
    VaccineType(std::string code, std::string description, std::string technology);

    std::string getCode() const;
    std::string getShortDescription() const;
    std::string getTechnology() const;

    // CORRIGIDO: Este método é obrigatório para o UPDATE funcionar
    void setDescription(std::string description);
};

#endif // VACCINETYPE_H