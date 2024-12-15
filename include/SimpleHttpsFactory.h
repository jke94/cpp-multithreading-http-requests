#ifndef SIMPLE_HTTPS_FACTORY_H
#define SIMPLE_HTTPS_FACTORY_H

#include <memory>
#include "ISimpleHTTPSApi.h"

class SimpleHttpsFactory
{
public:
    SimpleHttpsFactory() = default;
    ~SimpleHttpsFactory() = default;

    std::shared_ptr<ISimpleHTTPSApi> createSimpleHttpsClient();
    std::vector<std::string> createVectorOfUrls();
};

#endif // SIMPLE_HTTPS_FACTORY_H