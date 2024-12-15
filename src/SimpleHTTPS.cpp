#include <algorithm>
#include <iostream>
#include <mutex>
#include <thread>

#include "SimpleHTTPS.h"
#include <curl/curl.h>

std::mutex mtx;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *s) 
{
    size_t newLength = size*nmemb;
    s->append(static_cast<char*>(contents), newLength);
    
    return newLength;
}

SimpleHTTPS::SimpleHTTPS() 
{
    curl_global_init(CURL_GLOBAL_ALL);
}

SimpleHTTPS::~SimpleHTTPS() 
{
    curl_global_cleanup();
}

bool SimpleHTTPS::get(const std::string& url, std::string& response) 
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) 
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cerr << "curl_easy_perform() failed for " << url << ": " << curl_easy_strerror(res) << std::endl;
            response.clear();
            return false;
        }
        
        return true;
    }
    return false;
}

void SimpleHTTPS::getSingleThread(const std::string& url, std::string& response) 
{
    // Aquí usamos el método get existente pero en un contexto de hilo separado
    SimpleHTTPS client;
    client.get(url, response);
}

void SimpleHTTPS::getMultiple(const std::vector<std::string>& urls, std::vector<std::string>& responses) 
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