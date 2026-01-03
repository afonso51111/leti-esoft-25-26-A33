#ifndef VACCINETYPEROUTER_H
#define VACCINETYPEROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

class VaccineTypeRouter : public RouterConfig {
public:
    VaccineTypeRouter();
    void configure(httplib::Server &svr);
};

#endif