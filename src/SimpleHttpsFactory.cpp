#include <memory>
#include <iostream>

#include "SimpleHttpsFactory.h"
#include "SimpleHTTPS.h"

namespace cppmultithreadingrequests
{
    std::shared_ptr<ISimpleHTTPSApi> SimpleHttpsFactory::createSimpleHttpsClient()
    {
        std::shared_ptr<ISimpleHTTPSApi> client = std::make_shared<SimpleHTTPS>();
        
        if (!client) 
        {
            std::cerr << "Failed to create client." << std::endl;
        }

        return client;
    }
}