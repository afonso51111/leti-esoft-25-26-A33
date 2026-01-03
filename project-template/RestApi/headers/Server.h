#ifndef SERVER_H
#define SERVER_H

#include "../thirdparty/httplib.h"

class Server {
private:
    httplib::Server svr;
public:
    void run();
};

#endif