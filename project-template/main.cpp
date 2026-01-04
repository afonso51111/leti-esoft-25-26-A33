#include <iostream>
#include "Server.h"
#include "../Core/headers/domain/model/AppointmentStore.h"
#include "../Core/headers/domain/model/Company.h"
#include "../Core/headers/domain/model/VaccineTypeStore.h"
#include "../Core/headers/domain/model/VaccineStore.h"
#include "../Core/headers/domain/model/VaccineType.h"
#include "../Core/headers/domain/model/Vaccine.h"
#include "../Core/headers/domain/model/VaccinationCenterStore.h"
#include "../Core/headers/domain/model/SNSUserStore.h"
#include "../Core/headers/domain/model/SNSUser.h"

void bootstrap() {
    std::cout << "Bootstrapping data..." << std::endl;
    Company* company = Company::getInstance();

    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineType* type1 = typeStore->createVaccineType("COV19", "Covid-19 Vaccine", "mRNA Technology");
    typeStore->saveVaccineType(type1);

    VaccineStore* vaccineStore = company->getVaccineStore();
    Vaccine* v1 = vaccineStore->createVaccine("Comirnaty", "Pfizer", type1);
    vaccineStore->saveVaccine(v1);

    VaccinationCenterStore* centerStore = company->getVaccinationCenterStore();
    VaccinationCenter* c1 = centerStore->createHealthcareCenter("Centro Hospitalar Lisboa", "ARS Lisboa", "Todos");
    centerStore->saveVaccinationCenter(c1);

    SNSUserStore* userStore = company->getSNSUserStore();
    SNSUser* u1 = userStore->createSNSUser("Maria Silva", "Rua das Flores", "Feminino", "912345678", "maria@mail.com", "1990-05-20", "123456789", "98765432");
    userStore->saveSNSUser(u1);

    AppointmentStore* appStore = company->getAppointmentStore();
    appStore->createAppointment(u1, "Centro Hospitalar Lisboa", "COV19", "2025-01-20 10:00");

    std::cout << "Data loaded successfully!" << std::endl;

}

int main() {
    bootstrap();

    Server server;
    try {
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Error starting server: " << e.what() << std::endl;
    }

    return 0;
}