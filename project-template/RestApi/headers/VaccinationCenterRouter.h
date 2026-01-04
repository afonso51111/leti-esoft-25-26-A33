#ifndef VACCINATIONCENTERROUTER_H
#define VACCINATIONCENTERROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

class VaccinationCenterRouter : public RouterConfig {
public:
    VaccinationCenterRouter();
    void configure(httplib::Server &svr);
};

#endif // VACCINATIONCENTERROUTER_H