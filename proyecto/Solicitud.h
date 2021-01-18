//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_SOLICITUD_H
#define PROYECTO_SOLICITUD_H
#include <iostream>
#include <string>
#include "ProductoServicio.h"
#include "MetodoPago.h"
#include "Transporte.h"
#include "Fecha.h"
#include "Cliente.h"

class Solicitud {
private:
    ProductoServicio producto;
    MetodoPago metodo;
    Transporte transporte;
    Fecha entrega;
    string status;
    Cliente cliente;
public:
    Solicitud();

    Solicitud(const ProductoServicio &producto, const MetodoPago &metodo, const Transporte &transporte,
              const Fecha &entrega, const string &status, const Cliente &cliente);

    const ProductoServicio &getProducto() const;

    void setProducto(const ProductoServicio &producto);

    const MetodoPago &getMetodo() const;

    void setMetodo(const MetodoPago &metodo);

    const Transporte &getTransporte() const;

    void setTransporte(const Transporte &transporte);

    const Fecha &getEntrega() const;

    void setEntrega(const Fecha &entrega);

    const string &getStatus() const;

    void setStatus(const string &status);

    const Cliente &getCliente() const;

    void setCliente(const Cliente &cliente);

    string verificarStatus();
};


#endif //PROYECTO_SOLICITUD_H
