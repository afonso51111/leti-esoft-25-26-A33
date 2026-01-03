#include "../../../headers/domain/model/HealthcareCenter.h"

HealthcareCenter::HealthcareCenter(std::string name, std::string address, std::string phone, std::string email,
                                   std::string website, std::string openHours, std::string closeHours,
                                   int slotDur, int maxVac, std::string ars, std::string ages)
    : VaccinationCenter(name, address, phone, email, website, openHours, closeHours, maxVac),
      ars(ars), ages(ages) {
    // Nota: assumi maxVac como capacidade. Ajusta se slotDur for para usar no cálculo.
}