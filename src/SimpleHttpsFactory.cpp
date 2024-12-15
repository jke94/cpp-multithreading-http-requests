#include <memory>
#include <iostream>

#include "SimpleHttpsFactory.h"
#include "SimpleHTTPS.h"

std::shared_ptr<ISimpleHTTPSApi> SimpleHttpsFactory::createSimpleHttpsClient()
{
    std::shared_ptr<ISimpleHTTPSApi> client = std::make_shared<SimpleHTTPS>();
    
    if (!client) 
    {
        std::cerr << "Failed to create client." << std::endl;
    }

    return client;
}

std::vector<std::string> SimpleHttpsFactory::createVectorOfUrls()
{
    std::vector<std::string> urls = {
        "https://jsonplaceholder.typicode.com/posts/41",
        "https://jsonplaceholder.typicode.com/posts/2", 
        "https://jsonplaceholder.typicode.com/posts/12",
        "https://jsonplaceholder.typicode.com/posts/12",
        "https://jsonplaceholder.typicode.com/posts/22",
        "https://jsonplaceholder.typicode.com/posts/4",
        "https://jsonplaceholder.typicode.com/posts/5",
        "https://jsonplaceholder.typicode.com/posts/2",
        "https://jsonplaceholder.typicode.com/posts/25",
        "https://jsonplaceholder.typicode.com/posts/48",
        // "https://jsonplaceholder.typicode.com/posts/41",
        // "https://jsonplaceholder.typicode.com/posts/2", 
        // "https://jsonplaceholder.typicode.com/posts/12",
        // "https://jsonplaceholder.typicode.com/posts/12",
        // "https://jsonplaceholder.typicode.com/posts/22",
        // "https://jsonplaceholder.typicode.com/posts/4",
        // "https://jsonplaceholder.typicode.com/posts/5",
        // "https://jsonplaceholder.typicode.com/posts/2",
        // "https://jsonplaceholder.typicode.com/posts/25",
        // "https://jsonplaceholder.typicode.com/posts/48",
        // "https://jsonplaceholder.typicode.com/posts/54",
        // "https://jsonplaceholder.typicode.com/posts/23",
        // "https://jsonplaceholder.typicode.com/posts/164",
        // "https://jsonplaceholder.typicode.com/posts/72",
        // "https://jsonplaceholder.typicode.com/posts/35",
        // "https://jsonplaceholder.typicode.com/posts/58",
        // "https://jsonplaceholder.typicode.com/posts/12",
        // "https://jsonplaceholder.typicode.com/posts/2",
        // "https://jsonplaceholder.typicode.com/posts/4",
        // "https://jsonplaceholder.typicode.com/posts/52",
        // "https://jsonplaceholder.typicode.com/posts/24",
        // "https://jsonplaceholder.typicode.com/posts/24",
        // "https://jsonplaceholder.typicode.com/posts/54",
        // "https://jsonplaceholder.typicode.com/posts/54",
        // "https://jsonplaceholder.typicode.com/posts/23",
        // "https://jsonplaceholder.typicode.com/posts/64",
        // "https://jsonplaceholder.typicode.com/posts/7qweq2",
        // "https://jsonplaceholder.typicode.com/posts/35",
        // "https://jsonplaceholder.typicode.com/posts/5",         
        // "https://jsonplaceholder.typicode.com/posts/54",
        // "https://jsonplaceholder.typicode.com/posts/23",
        // "https://jsonplaceholder.typicode.com/posts/164",
        // "https://jsonplaceholder.typicode.com/posts/72",
        // "https://jsonplaceholder.typicode.com/posts/35",
        // "https://jsonplaceholder.typicode.com/posts/58",
        // "https://jsonplaceholder.typicode.com/posts/12",
        // "https://jsonplaceholder.typicode.com/posts/2",
        // "https://jsonplaceholder.typicode.com/posts/4",
        // "https://jsonplaceholder.typicode.com/posts/52",
        // "https://jsonplaceholder.typicode.com/posts/24",
        // "https://jsonplaceholder.typicode.com/posts/24",
        // "https://jsonplaceholder.typicode.com/posts/54",
        "https://jsonplaceholder.typicode.com/posts/54",
        "https://jsonplaceholder.typicode.com/posts/23",
        "https://jsonplaceholder.typicode.com/posts/64",
        "https://jsonplaceholder.typicode.com/posts/7qweq2",
        "https://jsonplaceholder.typicode.com/posts/35",
        "https://jsonplaceholder.typicode.com/posts/5",      
    };

    return urls;
}