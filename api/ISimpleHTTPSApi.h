#ifndef I_SIMPLE_HTTPS_H
#define I_SIMPLE_HTTPS_H

#include <string>
#include <memory>
#include <vector>
#include <functional>

struct HttpRequestResponse
{
    std::string url;
    int httpResponseStatusCode;
};


class ISimpleHTTPSApi 
{
protected:
    virtual ~ISimpleHTTPSApi() = default;

public:

    // Realizar una única petición GET
    virtual bool get(const std::string& url, std::string& response) = 0;

    // Realizar múltiples peticiones GET en paralelo
    virtual void getMultiple(const std::vector<std::string>& urls, std::vector<std::string>& responses) = 0;
};

std::shared_ptr<ISimpleHTTPSApi> createHttpsClient();

#endif // I_SIMPLE_HTTPS_H