#include "ISimpleHTTPSApi.h"
#include "SimpleHttpsFactory.h"
#include "SimpleHTTPS.h"

using namespace cppmultithreadingrequests;

std::shared_ptr<ISimpleHTTPSApi> createSimpleHttpsClient()
{
    SimpleHttpsFactory simpleHttpsClientFactory;

    return simpleHttpsClientFactory.createSimpleHttpsClient();
}