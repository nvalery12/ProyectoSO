//
// Created by noel on 18/1/21.
//

#include "MetodoPago.h"

MetodoPago::MetodoPago() {}

MetodoPago::MetodoPago(int cantidad) : cantidad(cantidad) {}

int MetodoPago::getCantidad() const {
    return cantidad;
}

void MetodoPago::setCantidad(int cantidad) {
    MetodoPago::cantidad = cantidad;
}
