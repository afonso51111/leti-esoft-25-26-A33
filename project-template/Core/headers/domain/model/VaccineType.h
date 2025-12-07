#ifndef VACCINETYPE_H
#define VACCINETYPE_H

#include <string>
#include <iostream>

class VaccineType {
private:
    std::string code;
    std::string description;
    std::string technology;

public:
    VaccineType(std::string code, std::string description, std::string technology);

    std::string getCode() const;
    std::string getDescription() const;
    std::string getTechnology() const;

    bool operator==(const VaccineType& other) const;
};

#endif