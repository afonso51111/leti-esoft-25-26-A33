#ifndef VACCINEROUTER_H
#define VACCINEROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

class VaccineRouter : public RouterConfig {
public:
    VaccineRouter();
    void configure(httplib::Server &svr);
};

#endif