#include "../../headers/views/ConsoleView.h"
#include <iostream>
#include <string>

using namespace std;

ConsoleView::ConsoleView() {}

void ConsoleView::clearScreen() {
    // Não usa system("cls") - só imprime linhas para separar
    cout << "\n\n\n";
}

void ConsoleView::pause() {
    string dummy;
    cout << "\n[Pressione ENTER para continuar]\n";
    getline(cin, dummy);
}

void ConsoleView::printHeader(string title) {
    cout << "\n\n";
    cout << "================================================\n";
    cout << "  " << title << "\n";
    cout << "================================================\n\n";
}

void ConsoleView::printResult(HttpResult result) {
    cout << "\n--- RESULTADO ---\n";
    cout << "Status: " << result.getStatus() << "\n";
    cout << result.getBody() << "\n";
    cout << "-----------------\n";
}

string ConsoleView::readString(string label, bool allowEmpty) {
    string input;
    while (true) {
        cout << label << ": ";
        getline(cin, input);
        if (allowEmpty || !input.empty()) {
            return input;
        }
        cout << "[ERRO] Campo obrigatorio!\n";
    }
}

int ConsoleView::readInt(string label) {
    string input;
    while (true) {
        cout << label << ": ";
        getline(cin, input);
        if (!input.empty()) {
            try {
                return stoi(input);
            } catch (...) {}
        }
        cout << "[ERRO] Numero invalido!\n";
    }
}

void ConsoleView::run() {
    int op;
    do {
        printHeader("MENU PRINCIPAL - PVMS");
        cout << "1. Gerir Tipos de Vacina\n";
        cout << "2. Gerir Vacinas\n";
        cout << "0. Sair\n\n";
        op = readInt("Opcao");

        if (op == 1) {
            menuVaccineTypes();
        } else if (op == 2) {
            menuVaccines();
        } else if (op == 0) {
            cout << "\n\nSistema encerrado. Ate breve!\n\n";
        } else {
            cout << "\n[ERRO] Opcao invalida!\n";
            pause();
        }
    } while (op != 0);
}

void ConsoleView::menuVaccineTypes() {
    int op;
    do {
        printHeader("GERIR TIPOS DE VACINA");
        cout << "1. Listar todos os tipos\n";
        cout << "2. Criar novo tipo\n";
        cout << "3. Editar tipo existente\n";
        cout << "4. Apagar tipo\n";
        cout << "0. Voltar ao menu principal\n\n";
        op = readInt("Opcao");

        if (op == 1) {
            printHeader("LISTA DE TIPOS DE VACINA");
            cout << typeController.getAll().getBody() << "\n";
            pause();
        }
        else if (op == 2) {
            printHeader("CRIAR NOVO TIPO");
            string code = readString("Codigo (ex: COV19)");
            string desc = readString("Descricao");
            string tech = readString("Tecnologia");
            cout << "\nA processar...\n";
            HttpResult r = typeController.createType(code, desc, tech);
            printResult(r);
            pause();
        }
        else if (op == 3) {
            printHeader("EDITAR TIPO");
            string code = readString("Codigo do tipo");
            string desc = readString("Nova descricao");
            cout << "\nA processar...\n";
            HttpResult r = typeController.updateType(code, desc);
            printResult(r);
            pause();
        }
        else if (op == 4) {
            printHeader("APAGAR TIPO");
            string code = readString("Codigo do tipo");
            string conf = readString("Tem certeza? (s/n)");
            if (conf == "s" || conf == "S") {
                cout << "\nA processar...\n";
                HttpResult r = typeController.deleteType(code);
                printResult(r);
            } else {
                cout << "\nOperacao cancelada.\n";
            }
            pause();
        }
        else if (op == 0) {
            // Voltar
        }
        else {
            cout << "\n[ERRO] Opcao invalida!\n";
            pause();
        }
    } while (op != 0);
}

void ConsoleView::menuVaccines() {
    int op;
    do {
        printHeader("GERIR VACINAS");
        cout << "1. Listar todas as vacinas\n";
        cout << "2. Criar nova vacina\n";
        cout << "3. Editar vacina existente\n";
        cout << "4. Apagar vacina\n";
        cout << "0. Voltar ao menu principal\n\n";
        op = readInt("Opcao");

        if (op == 1) {
            printHeader("LISTA DE VACINAS");
            cout << vaccineController.getAll().getBody() << "\n";
            pause();
        }
        else if (op == 2) {
            printHeader("CRIAR NOVA VACINA");
            string code = readString("Codigo da vacina (ex: VAC001)");
            string name = readString("Nome comercial");
            string brand = readString("Marca/Fabricante");
            string type = readString("Codigo do tipo");
            cout << "\nA processar...\n";
            HttpResult r = vaccineController.createVaccine(code, name, brand, type);
            printResult(r);
            pause();
        }
        else if (op == 3) {
            printHeader("EDITAR VACINA");
            string code = readString("Codigo da vacina");
            string name = readString("Novo nome comercial");
            string brand = readString("Nova marca");
            cout << "\nA processar...\n";
            HttpResult r = vaccineController.updateVaccine(code, name, brand, "N/A");
            printResult(r);
            pause();
        }
        else if (op == 4) {
            printHeader("APAGAR VACINA");
            string code = readString("Codigo da vacina");
            string conf = readString("Tem certeza? (s/n)");
            if (conf == "s" || conf == "S") {
                cout << "\nA processar...\n";
                HttpResult r = vaccineController.deleteVaccine(code);
                printResult(r);
            } else {
                cout << "\nOperacao cancelada.\n";
            }
            pause();
        }
        else if (op == 0) {
            // Voltar
        }
        else {
            cout << "\n[ERRO] Opcao invalida!\n";
            pause();
        }
    } while (op != 0);
}