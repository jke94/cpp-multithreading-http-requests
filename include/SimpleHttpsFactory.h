#ifndef SIMPLE_HTTPS_FACTORY_H
#define SIMPLE_HTTPS_FACTORY_H

#include <memory>
#include <string>
#include <vector>

#include "ISimpleHTTPSApi.h"

namespace cppmultithreadingrequests
{
    class SimpleHttpsFactory
    {
    public:
        SimpleHttpsFactory() = default;
        ~SimpleHttpsFactory() = default;

        std::shared_ptr<ISimpleHTTPSApi> createSimpleHttpsClient();
    };

};

#endif // SIMPLE_HTTPS_FACTORY_H