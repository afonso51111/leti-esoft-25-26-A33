#ifndef VACCINATIONCENTERCONTROLLER_H
#define VACCINATIONCENTERCONTROLLER_H

#include "controllers/restapi/HttpResult.h"

class VaccinationCenterController {
public:
    VaccinationCenterController();
    HttpResult getAll();
};

#endif // VACCINATIONCENTERCONTROLLER_H