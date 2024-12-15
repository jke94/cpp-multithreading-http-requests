#include "SimpleHttpsApiUnitTests.h"
#include "ISimpleHTTPSApi.h"
#include "SimpleHttpsFactory.h"
#include "MockSimpleHTTPSApi.h"
#include "gtest/gtest.h"

using namespace cppmultithreadingrequests;

// Test that createSimpleHttpsClient returns a valid shared pointer.
TEST_F(SimpleHttpsApiUnitTests, WhenMethodCreateSimpleHttpsClientIsCalled_Then_Returns_ObjectNotNull) 
{
    std::shared_ptr<ISimpleHTTPSApi> client = createSimpleHttpsClient();

    EXPECT_NE(client, nullptr);
}