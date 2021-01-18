//
// Created by noel on 18/1/21.
//

#include "Solicitud.h"

Solicitud::Solicitud() {
    producto=ProductoServicio();
    metodo=MetodoPago();
    transporte=Transporte();
    cliente=Cliente();
    status="";
}

Solicitud::Solicitud(const ProductoServicio &producto, const MetodoPago &metodo, const Transporte &transporte,
                     const Fecha &entrega, const string &status, const Cliente &cliente) : producto(producto),
                                                                                           metodo(metodo),
                                                                                           transporte(transporte),
                                                                                           entrega(entrega),
                                                                                           status(status),
                                                                                           cliente(cliente) {}

const ProductoServicio &Solicitud::getProducto() const {
    return producto;
}

void Solicitud::setProducto(const ProductoServicio &producto) {
    Solicitud::producto = producto;
}

const MetodoPago &Solicitud::getMetodo() const {
    return metodo;
}

void Solicitud::setMetodo(const MetodoPago &metodo) {
    Solicitud::metodo = metodo;
}

const Transporte &Solicitud::getTransporte() const {
    return transporte;
}

void Solicitud::setTransporte(const Transporte &transporte) {
    Solicitud::transporte = transporte;
}

const Fecha &Solicitud::getEntrega() const {
    return entrega;
}

void Solicitud::setEntrega(const Fecha &entrega) {
    Solicitud::entrega = entrega;
}

const string &Solicitud::getStatus() const {
    return status;
}

void Solicitud::setStatus(const string &status) {
    Solicitud::status = status;
}

const Cliente &Solicitud::getCliente() const {
    return cliente;
}

void Solicitud::setCliente(const Cliente &cliente) {
    Solicitud::cliente = cliente;
}

string Solicitud::verificarStatus(){
    printf("Verificacion realizada con exito\n");
    return "SIIIIIUUUU";
}