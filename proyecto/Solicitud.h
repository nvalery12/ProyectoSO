//
// Created by noel on 8/1/21.
//

#ifndef PROYECTOSO_SOLICITUD_H
#define PROYECTOSO_SOLICITUD_H

#include "ProductoServicio.h"
#include "Cliente.h"
#include "Empresa.h"
#include "Fecha.h"
#include <String.h>

class Solicitud {
private:
    ProductoServicio product;
    Cliente client;
    Empresa prov;
    Fecha entrega;
    String status;
public:
    Solicitud(const ProductoServicio &product, const Cliente &client, const Empresa &prov, const Fecha &entrega,
              const String &status);

    const ProductoServicio &getProduct() const;

    void setProduct(const ProductoServicio &product);

    const Cliente &getClient() const;

    void setClient(const Cliente &client);

    const Empresa &getProv() const;

    void setProv(const Empresa &prov);

    const Fecha &getEntrega() const;

    void setEntrega(const Fecha &entrega);

    const String &getStatus() const;

    void setStatus(const String &status);
};


#endif //PROYECTOSO_SOLICITUD_H
