#include "ISimpleHTTPSApi.h"
#include "SimpleHttpsFactory.h"
#include "SimpleHTTPS.h"

std::shared_ptr<ISimpleHTTPSApi> createSimpleHttpsClient()
{
    SimpleHttpsFactory simpleHttpsClientFactory;

    return simpleHttpsClientFactory.createSimpleHttpsClient();
}