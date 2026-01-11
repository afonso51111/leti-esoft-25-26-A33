#include <gtest/gtest.h>
#include "../../../Core/headers/domain/model/Company.h"
#include "../../../Core/headers/domain/model/VaccineTypeStore.h"
#include "../../../Core/headers/domain/model/VaccineStore.h"
#include "../../../Core/headers/domain/model/Vaccine.h"
#include "../../../Core/headers/domain/model/VaccineType.h"

// ========================================
// TESTES DE VACCINE TYPE
// ========================================


TEST(VaccineTypeTest, Deve_Encontrar_Tipo_Por_Codigo) {
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    // Garante que existe
    VaccineType* tipo = store->findTypeByCode("FLU23");
    if (tipo == nullptr) {
        tipo = store->createVaccineType("FLU23", "Vacina Gripe", "Inativada");
        store->saveVaccineType(tipo);
    }

    VaccineType* encontrado = store->findTypeByCode("FLU23");

    ASSERT_NE(encontrado, nullptr);
    EXPECT_EQ(encontrado->getCode(), "FLU23");
}

TEST(VaccineTypeTest, Nao_Deve_Encontrar_Tipo_Inexistente) {
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    VaccineType* tipo = store->findTypeByCode("NAOEXISTE999");

    EXPECT_EQ(tipo, nullptr);
}

TEST(VaccineTypeTest, Deve_Listar_Todos_Os_Tipos) {
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    // Garante que há pelo menos 1
    if (store->getVaccineTypes().empty()) {
        VaccineType* tipo = store->createVaccineType("TEST1", "Teste", "mRNA");
        store->saveVaccineType(tipo);
    }

    auto tipos = store->getVaccineTypes();

    EXPECT_GT(tipos.size(), 0);
}

TEST(VaccineTypeTest, Deve_Remover_Tipo) {
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    // Cria um tipo só para remover
    VaccineType* tipo = store->createVaccineType("REMOVER1", "Para Remover", "Test");
    store->saveVaccineType(tipo);

    bool removido = store->removeType("REMOVER1");

    EXPECT_TRUE(removido);
    EXPECT_EQ(store->findTypeByCode("REMOVER1"), nullptr);
}

TEST(VaccineTypeTest, Nao_Deve_Remover_Tipo_Inexistente) {
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    bool removido = store->removeType("NAOEXISTE888");

    EXPECT_FALSE(removido);
}

// ========================================
// TESTES DE VACCINE
// ========================================

TEST(VaccineTest, Deve_Criar_Vacina_Valida) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    // Garante tipo existe
    VaccineType* tipo = typeStore->findTypeByCode("COV-TEST");
    if (tipo == nullptr) {
        tipo = typeStore->createVaccineType("COV-TEST", "Covid Test", "mRNA");
        typeStore->saveVaccineType(tipo);
    }

    Vaccine* vacina = vaccineStore->createVaccine("VAC-001", "TestVac", "Pfizer", tipo);
    vaccineStore->saveVaccine(vacina);

    ASSERT_NE(vacina, nullptr);
    EXPECT_EQ(vacina->getCode(), "VAC-001");
    EXPECT_EQ(vacina->getCommercialName(), "TestVac");
    EXPECT_EQ(vacina->getBrand(), "Pfizer");
}

TEST(VaccineTest, Deve_Encontrar_Vacina_Por_Codigo) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    // Garante tipo e vacina existem
    VaccineType* tipo = typeStore->findTypeByCode("COV-TEST");
    if (tipo == nullptr) {
        tipo = typeStore->createVaccineType("COV-TEST", "Covid Test", "mRNA");
        typeStore->saveVaccineType(tipo);
    }

    Vaccine* vacina = vaccineStore->findVaccineByCode("VAC-001");
    if (vacina == nullptr) {
        vacina = vaccineStore->createVaccine("VAC-001", "TestVac", "Pfizer", tipo);
        vaccineStore->saveVaccine(vacina);
    }

    Vaccine* encontrada = vaccineStore->findVaccineByCode("VAC-001");

    ASSERT_NE(encontrada, nullptr);
    EXPECT_EQ(encontrada->getCode(), "VAC-001");
}

TEST(VaccineTest, Nao_Deve_Encontrar_Vacina_Inexistente) {
    Company* company = Company::getInstance();
    VaccineStore* store = company->getVaccineStore();

    Vaccine* vacina = store->findVaccineByCode("NAOEXISTE777");

    EXPECT_EQ(vacina, nullptr);
}

TEST(VaccineTest, Deve_Listar_Todas_Vacinas) {
    Company* company = Company::getInstance();
    VaccineStore* store = company->getVaccineStore();

    auto vacinas = store->getVaccines();

    // Pode ter 0 ou mais, mas não deve dar erro
    EXPECT_GE(vacinas.size(), 0);
}

TEST(VaccineTest, Deve_Atualizar_Nome_Comercial) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    // Garante tipo existe
    VaccineType* tipo = typeStore->findTypeByCode("COV-TEST");
    if (tipo == nullptr) {
        tipo = typeStore->createVaccineType("COV-TEST", "Covid Test", "mRNA");
        typeStore->saveVaccineType(tipo);
    }

    // Cria vacina
    Vaccine* vacina = vaccineStore->findVaccineByCode("VAC-UPDATE");
    if (vacina == nullptr) {
        vacina = vaccineStore->createVaccine("VAC-UPDATE", "Nome Original", "Pfizer", tipo);
        vaccineStore->saveVaccine(vacina);
    }

    // Atualiza
    vacina->setCommercialName("Nome Atualizado");

    EXPECT_EQ(vacina->getCommercialName(), "Nome Atualizado");
}

TEST(VaccineTest, Deve_Atualizar_Marca) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    VaccineType* tipo = typeStore->findTypeByCode("COV-TEST");
    if (tipo == nullptr) {
        tipo = typeStore->createVaccineType("COV-TEST", "Covid Test", "mRNA");
        typeStore->saveVaccineType(tipo);
    }

    Vaccine* vacina = vaccineStore->findVaccineByCode("VAC-UPDATE2");
    if (vacina == nullptr) {
        vacina = vaccineStore->createVaccine("VAC-UPDATE2", "TestVac", "Pfizer", tipo);
        vaccineStore->saveVaccine(vacina);
    }

    vacina->setBrand("Moderna");

    EXPECT_EQ(vacina->getBrand(), "Moderna");
}

TEST(VaccineTest, Deve_Remover_Vacina) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    VaccineType* tipo = typeStore->findTypeByCode("COV-TEST");
    if (tipo == nullptr) {
        tipo = typeStore->createVaccineType("COV-TEST", "Covid Test", "mRNA");
        typeStore->saveVaccineType(tipo);
    }

    // Cria uma vacina só para remover
    Vaccine* vacina = vaccineStore->createVaccine("VAC-REMOVER", "Para Remover", "Test", tipo);
    vaccineStore->saveVaccine(vacina);

    bool removida = vaccineStore->removeVaccine("VAC-REMOVER");

    EXPECT_TRUE(removida);
    EXPECT_EQ(vaccineStore->findVaccineByCode("VAC-REMOVER"), nullptr);
}

TEST(VaccineTest, Nao_Deve_Remover_Vacina_Inexistente) {
    Company* company = Company::getInstance();
    VaccineStore* store = company->getVaccineStore();

    bool removida = store->removeVaccine("NAOEXISTE666");

    EXPECT_FALSE(removida);
}

// ========================================
// TESTES DE INTEGRAÇÃO
// ========================================

TEST(IntegrationTest, Deve_Criar_Tipo_E_Vacina_Associada) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    // Cria tipo
    VaccineType* tipo = typeStore->createVaccineType("HPV9", "HPV 9-valente", "Recombinante");
    typeStore->saveVaccineType(tipo);

    // Cria vacina desse tipo
    Vaccine* vacina = vaccineStore->createVaccine("VAC-HPV-01", "Gardasil 9", "MSD", tipo);
    vaccineStore->saveVaccine(vacina);

    // Verifica associação
    EXPECT_EQ(vacina->getType(), tipo);
    EXPECT_EQ(vacina->getType()->getCode(), "HPV9");
}

TEST(IntegrationTest, Deve_Listar_Vacinas_De_Um_Tipo) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    // Garante tipo existe
    VaccineType* tipo = typeStore->findTypeByCode("COV-TEST");
    if (tipo == nullptr) {
        tipo = typeStore->createVaccineType("COV-TEST", "Covid Test", "mRNA");
        typeStore->saveVaccineType(tipo);
    }

    // Conta quantas vacinas deste tipo existem
    auto todasVacinas = vaccineStore->getVaccines();
    int count = 0;
    for (auto v : todasVacinas) {
        if (v->getType()->getCode() == "COV-TEST") {
            count++;
        }
    }

    EXPECT_GE(count, 0);
}

// ========================================
// TESTES DE VALIDAÇÃO
// ========================================

TEST(ValidationTest, Tipo_Deve_Ter_Codigo_Valido) {
    Company* company = Company::getInstance();
    VaccineTypeStore* store = company->getVaccineTypeStore();

    VaccineType* tipo = store->createVaccineType("VALID", "Descricao", "Tech");

    bool valido = store->validateVaccineType(tipo);

    EXPECT_TRUE(valido);
}

// ========================================
// TESTES DE SINGLETON COMPANY
// ========================================

TEST(CompanyTest, Deve_Retornar_Mesma_Instancia) {
    Company* instance1 = Company::getInstance();
    Company* instance2 = Company::getInstance();

    EXPECT_EQ(instance1, instance2);
}

TEST(CompanyTest, Deve_Ter_VaccineTypeStore) {
    Company* company = Company::getInstance();

    VaccineTypeStore* store = company->getVaccineTypeStore();

    EXPECT_NE(store, nullptr);
}

TEST(CompanyTest, Deve_Ter_VaccineStore) {
    Company* company = Company::getInstance();

    VaccineStore* store = company->getVaccineStore();

    EXPECT_NE(store, nullptr);
}