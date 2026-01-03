#ifndef SNSUSERROUTER_H
#define SNSUSERROUTER_H

#include "RouterConfig.h"
#include "../thirdparty/httplib.h"

class SNSUserRouter : public RouterConfig {
public:
    SNSUserRouter();
    void configure(httplib::Server &svr);
};

#endif