#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "../controllers/restapi/VaccineController.h"
#include "../controllers/restapi/VaccineTypeController.h"
#include <string>

class ConsoleView {
private:
    VaccineController vaccineController;
    VaccineTypeController typeController;

    // --- Menus Principais ---
    void menuVaccineTypes();
    void menuVaccines();

    // --- Métodos Auxiliares de UI ---
    void clearScreen();
    void pause();
    void printHeader(std::string title);
    void printResult(HttpResult result);

    // --- Métodos de Leitura com Validação ---
    std::string readString(std::string label, bool allowEmpty = false);
    int readInt(std::string label);

public:
    ConsoleView();
    void run(); // Ponto de entrada
};

#endif // CONSOLEVIEW_H