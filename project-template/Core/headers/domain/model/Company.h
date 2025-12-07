#ifndef COMPANY_H
#define COMPANY_H

class EmployeeStore;
class VaccineTypeStore;
class VaccinationCenterStore;
class SNSUserStore;
class VaccineStore;

class Company {
private:
    static Company* instance;

    EmployeeStore* employeeStore;
    VaccineTypeStore* vaccineTypeStore;
    VaccinationCenterStore* centerStore;
    SNSUserStore* snsUserStore;
    VaccineStore* vaccineStore;

    Company();

public:
    static Company* getInstance();

    EmployeeStore* getEmployeeStore() const;
    VaccineTypeStore* getVaccineTypeStore() const;
    VaccinationCenterStore* getVaccinationCenterStore() const;
    SNSUserStore* getSNSUserStore() const;
    VaccineStore* getVaccineStore() const;

    ~Company();
};

#endif