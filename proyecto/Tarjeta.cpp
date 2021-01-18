//
// Created by noel on 18/1/21.
//

#include "Tarjeta.h"

Tarjeta::Tarjeta() {
    MetodoPago();
    numTarjeta="";
    banco="";
}

Tarjeta::Tarjeta(int cantidad, const string &numTarjeta, const string &banco) : MetodoPago(cantidad),
                                                                                numTarjeta(numTarjeta), banco(banco) {}

const string &Tarjeta::getNumTarjeta() const {
    return numTarjeta;
}

void Tarjeta::setNumTarjeta(const string &numTarjeta) {
    Tarjeta::numTarjeta = numTarjeta;
}

const string &Tarjeta::getBanco() const {
    return banco;
}

void Tarjeta::setBanco(const string &banco) {
    Tarjeta::banco = banco;
}
