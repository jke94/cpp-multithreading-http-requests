#!/bin/bash
g++ -std=c++11          \
    -I ./include        \
    -I ./api            \
    ./main.cpp          \
    ./src/SimpleHTTPS.cpp           \
    ./src/SimpleHttpsFactory.cpp    \
    -lcurl              \
    -pthread            \
    -o main