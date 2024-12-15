#!/bin/bash

# A. Generate unit tests executable.
g++ -std=c++11                                          \
    -I ./api                                            \
    -I ./include                                        \
    -I ./tests/include                                  \
    -I ./tests/mocks                                    \
    ./src/SimpleHTTPSApi.cpp                            \
    ./src/SimpleHttpsFactory.cpp                        \
    ./src/SimpleHTTPS.cpp                               \
    ./tests/mainUnitTests.cpp                           \
    ./tests/src/SimpleHttpsApiUnitTests.cpp             \
    ./tests/src/SimpleHttpsFactoryUnitTests.cpp         \
    -lgtest     \
    -lpthread   \
    -lgmock     \
    -lpthread   \
    -lcurl      \
    -o mainUnitTests

# B. Running unit tests.
./mainUnitTests