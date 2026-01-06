#include <gtest/gtest.h>
#include "../../../Core/headers/domain/model/Company.h"
#include "../../../Core/headers/domain/model/VaccineTypeStore.h"
#include "../../../Core/headers/domain/model/VaccineStore.h"
#include "../../../Core/headers/domain/model/Vaccine.h"
#include "../../../Core/headers/domain/model/VaccineType.h"

class VaccineTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
};

TEST_F(VaccineTest, Deve_Conseguir_Obter_Descricao_Pela_Vacina) {
    Company* company = Company::getInstance();
    VaccineTypeStore* typeStore = company->getVaccineTypeStore();
    VaccineStore* vaccineStore = company->getVaccineStore();

    VaccineType* tipoCovid = typeStore->createVaccineType("TEST-COV", "Vacina de Teste mRNA", "Covid-19");
    typeStore->saveVaccineType(tipoCovid);

    Vaccine* vacina = vaccineStore->createVaccine("ComirnatyTest", "Pfizer", tipoCovid);
    vaccineStore->saveVaccine(vacina);

    std::string codigo = vacina->getType()->getCode();
    std::string descricao = vacina->getType()->getShortDescription();

    EXPECT_EQ(codigo, "TEST-COV");
    EXPECT_EQ(descricao, "Vacina de Teste mRNA");
}