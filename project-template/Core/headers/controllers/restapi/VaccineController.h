#ifndef VACCINECONTROLLER_H
#define VACCINECONTROLLER_H

#include <string>
#include "HttpResult.h"
#include "../../domain/model/Company.h"

class VaccineController {
public:
    VaccineController();
    // Nota: O professor usa autenticação no construtor, mas para já fazemos simples

    // GET: Listar todas
    HttpResult getAll();

    // POST: Criar nova
    HttpResult createVaccine(std::string name, std::string brand, std::string typeCode);
};

#endif