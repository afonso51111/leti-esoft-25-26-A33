#include <iostream>
#include "RestApi/headers/Server.h"
#include "Core/headers/domain/model/Company.h"
#include "Core/headers/domain/model/VaccineTypeStore.h"
#include "Core/headers/domain/model/VaccineStore.h"
#include "Core/headers/domain/model/VaccineType.h"
#include "Core/headers/domain/model/Vaccine.h"

void bootstrap() {
    std::cout << "Bootstrapping data..." << std::endl;

    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineType* type1 = typeStore->createVaccineType("COV19", "Covid-19 Vaccine", "mRNA Technology");
    VaccineType* type2 = typeStore->createVaccineType("FLU", "Influenza Vaccine", "Viral Vector");
    typeStore->saveVaccineType(type1);
    typeStore->saveVaccineType(type2);

    VaccineStore* vaccineStore = company->getVaccineStore();
    Vaccine* v1 = vaccineStore->createVaccine("Comirnaty", "Pfizer", type1);
    Vaccine* v2 = vaccineStore->createVaccine("Spikevax", "Moderna", type1);
    Vaccine* v3 = vaccineStore->createVaccine("Fluarix", "GSK", type2);
    vaccineStore->saveVaccine(v1);
    vaccineStore->saveVaccine(v2);
    vaccineStore->saveVaccine(v3);

    std::cout << "Data loaded: " << typeStore->getVaccineTypes().size() << " Types, "
              << vaccineStore->getVaccines().size() << " Vaccines." << std::endl;
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