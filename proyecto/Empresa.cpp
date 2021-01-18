//
// Created by noel on 8/1/21.
//

#include "Empresa.h"

Empresa::Empresa(const string &nombre, const string &descripcion, const string &rif) : nombre(nombre),
                                                                                       descripcion(descripcion),
                                                                                       rif(rif) {}

void Empresa::setNombre(const string &nombre) {
    Empresa::nombre = nombre;
}

void Empresa::setDescripcion(const string &descripcion) {
    Empresa::descripcion = descripcion;
}

void Empresa::setRif(const string &rif) {
    Empresa::rif = rif;
}

String Empresa::getDescripcion() {
    return descripcion;
}

String Empresa::getNombre() {
    return nombre;
}

String Empresa::getRif() {
    return rif;
}

Empresa::Empresa(const String &nombre, const String &descripcion, const String &rif) : nombre(nombre),
                                                                                       descripcion(descripcion),
                                                                                       rif(rif) {}

const String &Empresa::getNombre() const {
    return nombre;
}

void Empresa::setNombre(const String &nombre) {
    Empresa::nombre = nombre;
}

const String &Empresa::getDescripcion() const {
    return descripcion;
}

void Empresa::setDescripcion(const String &descripcion) {
    Empresa::descripcion = descripcion;
}

const String &Empresa::getRif() const {
    return rif;
}

void Empresa::setRif(const String &rif) {
    Empresa::rif = rif;
}
