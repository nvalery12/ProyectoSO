//
// Created by noel on 18/1/21.
//

#include "Transferencia.h"

Transferencia::Transferencia() {}

Transferencia::Transferencia(int cantidad, const string &banco, const string &rif, const string &codigo,
                             const string &correo) : MetodoPago(cantidad), banco(banco), rif(rif), codigo(codigo),
                                                     correo(correo) {}

const string &Transferencia::getBanco() const {
    return banco;
}

void Transferencia::setBanco(const string &banco) {
    Transferencia::banco = banco;
}

const string &Transferencia::getRif() const {
    return rif;
}

void Transferencia::setRif(const string &rif) {
    Transferencia::rif = rif;
}

const string &Transferencia::getCodigo() const {
    return codigo;
}

void Transferencia::setCodigo(const string &codigo) {
    Transferencia::codigo = codigo;
}

const string &Transferencia::getCorreo() const {
    return correo;
}

void Transferencia::setCorreo(const string &correo) {
    Transferencia::correo = correo;
}
