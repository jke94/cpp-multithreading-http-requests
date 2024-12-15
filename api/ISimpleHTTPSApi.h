#ifndef I_SIMPLE_HTTPS_H
#define I_SIMPLE_HTTPS_H

#include <string>
#include <memory>
#include <vector>

struct HttpRequestResponse
{
    std::string url;
    std::string response;
    int httpResponseStatusCode;
    double transferTotalTime;
    // Number of size downloaded in kbytes.
    double numberOfSizeDownloaded;
    
    // Schema used for the connection.
    std::string schema;
    
    //Content type from the Content-Type header
    std::string contentType;
};

class ISimpleHTTPSApi 
{
protected:
    virtual ~ISimpleHTTPSApi() = default;

public:

    // Realizar una única petición GET
    virtual bool get(const std::string& url, HttpRequestResponse& response) = 0;

    // Realizar múltiples peticiones GET en paralelo
    virtual void getMultiple(const std::vector<std::string>& urls, std::vector<HttpRequestResponse>& responses) = 0;

    virtual void finalizeSimpleHttps() = 0;
};

std::shared_ptr<ISimpleHTTPSApi> createHttpsClient();

#endif // I_SIMPLE_HTTPS_H