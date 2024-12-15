#ifndef I_SIMPLE_HTTPS_H
#define I_SIMPLE_HTTPS_H

#include <string>
#include <memory>
#include <vector>

struct HttpRequestResponse
{
    // URl.
    std::string url;

    // Http response data.
    std::string response;

    // HTTP request response code.
    int httpResponseStatusCode;

    // Total transfer time.
    double transferTotalTime;

    // Number of size downloaded in kbytes.
    double numberOfSizeDownloaded;
    
    // Schema used for the connection.
    std::string schema;
    
    // Content type from the Content-Type header
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
};

// Initialize libcurl.
void initializeLibCurl();

// Clean up libcurl.
void cleanupLibCurl();

// Create client to do the requests.
std::shared_ptr<ISimpleHTTPSApi> createSimpleHttpsClient();

#endif // I_SIMPLE_HTTPS_H