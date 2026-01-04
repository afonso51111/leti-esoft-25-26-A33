#include "../../../headers/domain/model/HealthcareCenter.h"

HealthcareCenter::HealthcareCenter(std::string name, std::string addr, std::string phone, std::string email,
                                   std::string website, std::string open, std::string close, int cap,
                                   std::string ars, std::string ages)
    : VaccinationCenter(name, addr, phone, email, website, open, close, cap),
      ars(ars), ages(ages) {
}

std::string HealthcareCenter::getArs() const {
    return ars;
}

std::string HealthcareCenter::getAges() const {
    return ages;
}