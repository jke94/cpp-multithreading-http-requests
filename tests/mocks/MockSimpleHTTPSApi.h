#ifndef MOCK_SIMPLE_HTTPS_API_H
#define MOCK_SIMPLE_HTTPS_API_H

#include <string>
#include <vector>

#include "ISimpleHTTPSApi.h"
#include "gmock/gmock.h"

class MockSimpleHTTPSApi : public ISimpleHTTPSApi 
{
public:
    MOCK_METHOD(bool, get, (const std::string& url, HttpRequestResponse& response), (override));
    MOCK_METHOD(void, getMultiple, (const std::vector<std::string>& urls, std::vector<HttpRequestResponse>& responses), (override));
};

#endif // MOCK_SIMPLE_HTTPS_API_H