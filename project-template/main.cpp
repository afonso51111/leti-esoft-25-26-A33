#include "RestApi/headers/Server.h"
#include "Core/headers/views/ConsoleView.h"
#include <iostream>
#include <string>
#include "Core/headers/domain/model/Company.h"
#include "Core/headers/domain/model/VaccineStore.h"
#include "Core/headers/domain/model/VaccineTypeStore.h"

void bootstrap() {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    if (typeStore->getVaccineTypes().empty()) {
        VaccineType* type1 = typeStore->createVaccineType("COV19", "Covid-19 Vaccine", "mRNA");
        typeStore->saveVaccineType(type1);

        Vaccine* v1 = vaccineStore->createVaccine("VAC001", "Comirnaty", "Pfizer", type1);
        vaccineStore->saveVaccine(v1);
    }
}

int main() {
    bootstrap();

    std::string input;
    int choice;

    std::cout << "Selecione o modo de execucao:\n";
    std::cout << "1. Iniciar Servidor REST API (para usar curl)\n";
    std::cout << "2. Iniciar Menu de Consola (UI C++)\n";
    std::cout << "Opcao: ";

    std::getline(std::cin, input);

    try {
        choice = std::stoi(input);
    } catch (...) {
        std::cout << "Opcao invalida!\n";
        return 1;
    }

    if (choice == 1) {
        Server server;
        server.run();
    } else if (choice == 2) {
        // ADICIONA ESTA LINHA DE DEBUG
        std::cout << "\n[DEBUG] A iniciar ConsoleView...\n";
        ConsoleView view;
        std::cout << "[DEBUG] ConsoleView criado, a chamar run()...\n";
        view.run();
        std::cout << "[DEBUG] run() terminou.\n";
    } else {
        std::cout << "Opcao invalida!\n";
        return 1;
    }

    return 0;
}