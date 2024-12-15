#include <algorithm>
#include <iostream>
#include <future>
#include <mutex>
#include <vector>
#include <queue>
#include "SimpleHTTPS.h"
#include "ISimpleHTTPSApi.h"
#include <curl/curl.h>

static std::once_flag curl_init_flag;
static std::once_flag curl_cleanup_flag;

void initializeLibCurl()
{
    std::call_once(curl_init_flag, []() { curl_global_init(CURL_GLOBAL_ALL); });
}

void cleanupLibCurl() 
{
    std::call_once(curl_cleanup_flag, []() { curl_global_cleanup(); });
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) 
{
    size_t newLength = size * nmemb;
    s->append(static_cast<char*>(contents), newLength);
    return newLength;
}

bool SimpleHTTPS::get(const std::string& url, HttpRequestResponse& response) 
{
    CURL* curl = curl_easy_init();

    if (!curl) 
    {
        std::cerr << "Failed to initialize CURL for " << url << std::endl;
        return false;
    }

    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.response);

    res = curl_easy_perform(curl);

    if (res == CURLE_OK) 
    {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.httpResponseStatusCode);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response.transferTotalTime);

        double numberOfSizeDownloaded;
        curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &numberOfSizeDownloaded);
        response.numberOfSizeDownloaded = numberOfSizeDownloaded / 1000.0;

        char* schema = nullptr;
        curl_easy_getinfo(curl, CURLINFO_SCHEME, &schema);
        response.schema = schema ? std::string(schema) : "";

        char* contentType = nullptr;
        curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &contentType);
        response.contentType = contentType ? std::string(contentType) : "";
    } 
    else 
    {
        std::cerr << "curl_easy_perform() failed for " << url << ": " << curl_easy_strerror(res) << std::endl;
        response.response.clear();
        curl_easy_cleanup(curl);
        return false;
    }

    curl_easy_cleanup(curl);

    return true;
}

void SimpleHTTPS::getMultiple(const std::vector<std::string>& urls, std::vector<HttpRequestResponse>& responses) 
{
    responses.resize(urls.size());
    
    // Usar std::async para concurrencia
    std::vector<std::future<void>> futures;
    for (size_t i = 0; i < urls.size(); ++i) 
    {
        futures.emplace_back(std::async(std::launch::async, [this, &urls, &responses, i]() 
        {
            this->get(urls[i], responses[i]);
        }));
    }

    for (auto& fut : futures) 
    {
        fut.get();
    }
}