#include "../../../headers/domain/model/CommunityMassVaccinationCenter.h"

CommunityMassVaccinationCenter::CommunityMassVaccinationCenter(std::string name, std::string address, std::string phone,
                                                               std::string email, std::string website, std::string openHours,
                                                               std::string closeHours, int slotDur, int maxVac,
                                                               VaccineType* vType)
    : VaccinationCenter(name, address, phone, email, website, openHours, closeHours, maxVac),
      vaccineType(vType) {
}