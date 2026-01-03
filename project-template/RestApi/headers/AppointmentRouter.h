#ifndef APPOINTMENTROUTER_H
#define APPOINTMENTROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

class AppointmentRouter : public RouterConfig {
public:
    AppointmentRouter();
    void configure(httplib::Server &svr);
};

#endif