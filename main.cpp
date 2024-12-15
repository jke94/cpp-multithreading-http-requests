#include <chrono>
#include <iostream>
#include <memory>

#include "ISimpleHTTPSApi.h"

std::vector<std::string> urls = {
    "https://jsonplaceholder.typicode.com/posts/41",
    "https://jsonplaceholder.typicode.com/posts/2", 
    "https://jsonplaceholder.typicode.com/posts/12",
    "https://jsonplaceholder.typicode.com/posts/12",
    "https://jsonplaceholder.typicode.com/posts/22",
    "https://jsonplaceholder.typicode.com/posts/23",
    "https://jsonplaceholder.typicode.com/posts/64",
    "https://jsonplaceholder.typicode.com/posts/7qweq2",
    "https://jsonplaceholder.typicode.com/posts/35",
    "https://jsonplaceholder.typicode.com/posts/5",         
    "https://jsonplaceholder.typicode.com/posts/54",
    "https://jsonplaceholder.typicode.com/posts/23",
    "https://jsonplaceholder.typicode.com/posts/164",
    "https://jsonplaceholder.typicode.com/posts/72",
    "https://jsonplaceholder.typicode.com/posts/35",
    "https://jsonplaceholder.typicode.com/posts/58",
    "https://jsonplaceholder.typicode.com/posts/12",
    "https://jsonplaceholder.typicode.com/posts/2",
    "https://jsonplaceholder.typicode.com/posts/4",
    "https://jsonplaceholder.typicode.com/posts/52",
    "https://jsonplaceholder.typicode.com/posts/24",
    "https://jsonplaceholder.typicode.com/posts/24",
    "https://jsonplaceholder.typicode.com/posts/54",
    "https://jsonplaceholder.typicode.com/posts/54",
    "https://jsonplaceholder.typicode.com/posts/23",
    "https://jsonplaceholder.typicode.com/posts/64",
    "https://jsonplaceholder.typicode.com/posts/7qweq2",
    "https://jsonplaceholder.typicode.com/posts/35",
    "https://jsonplaceholder.typicode.com/posts/5",      
};

int main() 
{
    auto start = std::chrono::steady_clock::now();

    initializeLibCurl();
    
    std::shared_ptr<ISimpleHTTPSApi> client = createSimpleHttpsClient();
    std::cout << "Size of urls vector: " << urls.size() << std::endl;

    std::vector<HttpRequestResponse> responses;
    client->getMultiple(urls, responses);

    for (size_t i = 0; i < responses.size(); ++i) 
    {
        std::cout << "Response from " << urls[i] << std::endl;
        std::cout << 
        "\t[Content length: " << responses[i].response.length() <<  "]" <<
        "[HTTP Response status code: " << responses[i].httpResponseStatusCode << "]" <<
        "[TransferTotalTime: " << responses[i].transferTotalTime << "]" <<
        "[NumberOfSizeDownloaded: " << responses[i].numberOfSizeDownloaded << " (kbytes)]" <<
        "[Schema: " << responses[i].schema << "]" <<
        "[Content-Type Header: " << responses[i].contentType << "]" <<
        std::endl;
    }

    cleanupLibCurl();
    
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    std::cout << "Program execution duration time: " << diff_sec.count() << " (milliseconds)"<< std::endl;

    return 0;
}