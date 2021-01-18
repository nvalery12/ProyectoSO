//
// Created by noel on 8/1/21.
//

#include "Cliente.h"

Cliente::Cliente(const String &nombre, const String &numTlf, const String &residencia) : nombre(nombre), numTlf(numTlf),
                                                                                         residencia(residencia) {}

const String &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const String &nombre) {
    Cliente::nombre = nombre;
}

const String &Cliente::getNumTlf() const {
    return numTlf;
}

void Cliente::setNumTlf(const String &numTlf) {
    Cliente::numTlf = numTlf;
}

const String &Cliente::getResidencia() const {
    return residencia;
}

void Cliente::setResidencia(const String &residencia) {
    Cliente::residencia = residencia;
}
