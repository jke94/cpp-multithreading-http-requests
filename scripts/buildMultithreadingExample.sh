#!/bin/bash

g++ -std=c++11                      \
    -I ./include                    \
    -I ./api                        \
    ./client/main.cpp               \
    ./src/SimpleHTTPS.cpp           \
    ./src/SimpleHttpsFactory.cpp    \
    ./src/SimpleHTTPSApi.cpp        \
    -lcurl                          \
    -pthread                        \
    -o main