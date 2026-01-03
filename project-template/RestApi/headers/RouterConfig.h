#ifndef ROUTERCONFIG_H
#define ROUTERCONFIG_H

#include <string>

class RouterConfig {
protected:
    std::string baseResource;
public:
    RouterConfig(std::string path) : baseResource(path) {}
    virtual ~RouterConfig() = default;
};

#endif