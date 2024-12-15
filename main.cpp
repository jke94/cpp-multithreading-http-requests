#include "SimpleHttpsFactory.h"
#include <iostream>
#include <chrono>
#include <memory>

int main() 
{
    auto start = std::chrono::steady_clock::now();

    SimpleHttpsFactory simpleHttpsClientFactory;
    
    std::shared_ptr<ISimpleHTTPSApi> client = simpleHttpsClientFactory.createSimpleHttpsClient();
    std::vector<std::string> urls = simpleHttpsClientFactory.createVectorOfUrls();
    std::cout << "Size of urls vector: " << urls.size() << std::endl;

    std::vector<std::string> responses;
    client->getMultiple(urls, responses);

    for (size_t i = 0; i < responses.size(); ++i) 
    {
        std::cout << "Response from " << urls[i] << " content length: " << responses[i].length() << std::endl;
    }
    
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    std::cout << "Program execution duration time: " << diff_sec.count() << " (milliseconds)"<< std::endl;

    return 0;
}