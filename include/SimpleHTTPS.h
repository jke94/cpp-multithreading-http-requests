#ifndef SIMPLE_HTTPS_H
#define SIMPLE_HTTPS_H

#include <string>
#include <vector>
#include <functional>
#include "ISimpleHTTPSApi.h"

class SimpleHTTPS : public ISimpleHTTPSApi
{
public:
    SimpleHTTPS();
    ~SimpleHTTPS();

    // Realizar una única petición GET
    bool get(const std::string& url, HttpRequestResponse& response) override;

    // Realizar múltiples peticiones GET en paralelo
    void getMultiple(const std::vector<std::string>& urls, std::vector<HttpRequestResponse>& responses) override;

    // Finalizar contexto de libcurl.
    void finalizeSimpleHttps() override;

private:
    // Función privada para manejar cada petición en un hilo separado
    static void getSingleThread(const std::string& url, HttpRequestResponse& response);
};

#endif // SIMPLE_HTTPS_H