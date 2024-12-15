#include "SimpleHttpsFactoryUnitTests.h"
#include "SimpleHttpsFactory.h"
#include "ISimpleHTTPSApi.h"

#include "gtest/gtest.h"

using namespace cppmultithreadingrequests;

TEST_F(SimpleHttpsFactoryUnitTests, WhenCreateSimpleHttpsClientFactoryIsCalled_Then_Returns_ObjectNotNull) 
{
    SimpleHttpsFactory factory;

    std::shared_ptr<ISimpleHTTPSApi> client = factory.createSimpleHttpsClient();
    EXPECT_NE(client, nullptr);

}