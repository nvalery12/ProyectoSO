//
// Created by noel on 8/1/21.
//

#include "Solicitud.h"

Solicitud::Solicitud(const ProductoServicio &product, const Cliente &client, const Empresa &prov, const Fecha &entrega,
                     const String &status) : product(product), client(client), prov(prov), entrega(entrega),
                                             status(status) {}

const ProductoServicio &Solicitud::getProduct() const {
    return product;
}

void Solicitud::setProduct(const ProductoServicio &product) {
    Solicitud::product = product;
}

const Cliente &Solicitud::getClient() const {
    return client;
}

void Solicitud::setClient(const Cliente &client) {
    Solicitud::client = client;
}

const Empresa &Solicitud::getProv() const {
    return prov;
}

void Solicitud::setProv(const Empresa &prov) {
    Solicitud::prov = prov;
}

const Fecha &Solicitud::getEntrega() const {
    return entrega;
}

void Solicitud::setEntrega(const Fecha &entrega) {
    Solicitud::entrega = entrega;
}

const String &Solicitud::getStatus() const {
    return status;
}

void Solicitud::setStatus(const String &status) {
    Solicitud::status = status;
}
