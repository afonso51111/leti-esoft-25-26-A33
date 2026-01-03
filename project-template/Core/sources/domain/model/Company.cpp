#include "../../../headers/domain/model/Company.h"
#include "../../../headers/domain/model/EmployeeStore.h"
#include "../../../headers/domain/model/VaccineTypeStore.h"
#include "../../../headers/domain/model/VaccinationCenterStore.h"
#include "../../../headers/domain/model/SNSUserStore.h"
#include "../../../headers/domain/model/VaccineStore.h"
#include "../../../headers/domain/model/AppointmentStore.h"

Company* Company::instance = nullptr;

Company::Company() {
    this->employeeStore = new EmployeeStore();
    this->vaccineTypeStore = new VaccineTypeStore();
    this->centerStore = new VaccinationCenterStore();
    this->snsUserStore = new SNSUserStore();
    this->vaccineStore = new VaccineStore();
    this->appointmentStore = new AppointmentStore();
}

Company* Company::getInstance() {
    if (instance == nullptr) {
        instance = new Company();
    }
    return instance;
}

EmployeeStore* Company::getEmployeeStore() const {
    return employeeStore;
}

VaccineTypeStore* Company::getVaccineTypeStore() const {
    return vaccineTypeStore;
}

VaccinationCenterStore* Company::getVaccinationCenterStore() const {
    return centerStore;
}

SNSUserStore* Company::getSNSUserStore() const {
    return snsUserStore;
}

VaccineStore* Company::getVaccineStore() const {
    return vaccineStore;
}

AppointmentStore* Company::getAppointmentStore() const {
    return appointmentStore;
}

Company::~Company() {
    delete employeeStore;
    delete vaccineTypeStore;
    delete centerStore;
    delete snsUserStore;
    delete vaccineStore;
    delete appointmentStore;
}