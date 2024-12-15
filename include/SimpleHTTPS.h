#ifndef SIMPLE_HTTPS_H
#define SIMPLE_HTTPS_H

#include <string>
#include <vector>
#include <functional>
#include "ISimpleHTTPSApi.h"

class SimpleHTTPS : public ISimpleHTTPSApi
{
public:
    // Constructor y destructor
    SimpleHTTPS() = default;
    ~SimpleHTTPS() = default;

    /**
     * Realiza una solicitud HTTP GET a la URL especificada y almacena la respuesta.
     * @param url La URL a la cual se enviará la solicitud.
     * @param response Estructura donde se almacenará la respuesta HTTP.
     * @return true si la solicitud fue exitosa, false en caso contrario.
     */
    bool get(const std::string& url, HttpRequestResponse& response) override;

    /**
     * Realiza múltiples solicitudes HTTP GET en paralelo.
     * @param urls Vector de URLs a las que se enviarán las solicitudes.
     * @param responses Vector donde se almacenarán las respuestas HTTP (una por URL).
     */
    void getMultiple(const std::vector<std::string>& urls, std::vector<HttpRequestResponse>& responses) override;
};

#endif // SIMPLE_HTTPS_H