//
// Created by noel on 8/1/21.
//

#include "Transporte.h"

Transporte::Transporte(int capacidad, const String &nombre, const String &cedulaPropetario, const String &vehiculo,
                       const String &placa) : capacidad(capacidad), nombre(nombre), cedulaPropetario(cedulaPropetario),
                                              vehiculo(vehiculo), placa(placa) {}

int Transporte::getCapacidad() const {
    return capacidad;
}

void Transporte::setCapacidad(int capacidad) {
    Transporte::capacidad = capacidad;
}

const String &Transporte::getNombre() const {
    return nombre;
}

void Transporte::setNombre(const String &nombre) {
    Transporte::nombre = nombre;
}

const String &Transporte::getCedulaPropetario() const {
    return cedulaPropetario;
}

void Transporte::setCedulaPropetario(const String &cedulaPropetario) {
    Transporte::cedulaPropetario = cedulaPropetario;
}

const String &Transporte::getVehiculo() const {
    return vehiculo;
}

void Transporte::setVehiculo(const String &vehiculo) {
    Transporte::vehiculo = vehiculo;
}

const String &Transporte::getPlaca() const {
    return placa;
}

void Transporte::setPlaca(const String &placa) {
    Transporte::placa = placa;
}
