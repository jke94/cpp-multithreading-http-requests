#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>

#include "SimpleHTTPS.h"
#include <curl/curl.h>

static std::once_flag curl_init_flag;
std::mutex mtx;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *s) 
{
    size_t newLength = size*nmemb;
    s->append(static_cast<char*>(contents), newLength);
    
    return newLength;
}

SimpleHTTPS::SimpleHTTPS() 
{
    std::call_once(curl_init_flag, []() { curl_global_init(CURL_GLOBAL_ALL); });
}

SimpleHTTPS::~SimpleHTTPS() 
{

}

bool SimpleHTTPS::get(const std::string& url, HttpRequestResponse& response) 
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl) 
    {
        double numberOfSizeDownloaded;
        char* schema;
        char* contentType;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.response);
        
        res = curl_easy_perform(curl);

        // Get data.
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.httpResponseStatusCode);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &response.transferTotalTime);
       
        curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &numberOfSizeDownloaded);
        response.numberOfSizeDownloaded = numberOfSizeDownloaded / 1000.00;

        curl_easy_getinfo(curl, CURLINFO_SCHEME, &schema);
        response.schema = std::string(schema);

        curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &contentType);
        response.contentType = std::string(contentType);

        curl_easy_cleanup(curl);

        if(res != CURLE_OK) 
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cerr << "curl_easy_perform() failed for " << url << ": " << curl_easy_strerror(res) << std::endl;
            response.response.clear();
            return false;
        }
        
        return true;
    }
    return false;
}

void SimpleHTTPS::getSingleThread(const std::string& url, HttpRequestResponse& response) 
{
    // Aquí usamos el método get existente pero en un contexto de hilo separado
    SimpleHTTPS client;
    client.get(url, response);
}

void SimpleHTTPS::getMultiple(const std::vector<std::string>& urls, std::vector<HttpRequestResponse>& responses) 
{
    // Asegurarse de que el tamaño de responses coincide con el de urls
    responses.resize(urls.size());

    std::vector<std::thread> threads;
    for (size_t i = 0; i < urls.size(); ++i)
    {
        threads.emplace_back(getSingleThread, std::ref(urls[i]), std::ref(responses[i]));
    }

    // Esperar a que todos los hilos terminen
    for (auto& th : threads)
    {
        th.join();
    }
}

void SimpleHTTPS::finalizeSimpleHttps()
{
    curl_global_cleanup();
}