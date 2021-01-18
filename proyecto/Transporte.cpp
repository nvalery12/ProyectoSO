//
// Created by noel on 18/1/21.
//

#include "Transporte.h"

Transporte::Transporte() {
    nombre="";
    cedulaPropetario="";
    vehiculo="";
    placa="";
    capacidad=0;
}

Transporte::Transporte(int capacidad, const string &nombre, const string &cedulaPropetario, const string &vehiculo,
                       const string &placa) : capacidad(capacidad), nombre(nombre), cedulaPropetario(cedulaPropetario),
                                              vehiculo(vehiculo), placa(placa) {}

int Transporte::getCapacidad() const {
    return capacidad;
}

void Transporte::setCapacidad(int capacidad) {
    Transporte::capacidad = capacidad;
}

const string &Transporte::getNombre() const {
    return nombre;
}

void Transporte::setNombre(const string &nombre) {
    Transporte::nombre = nombre;
}

const string &Transporte::getCedulaPropetario() const {
    return cedulaPropetario;
}

void Transporte::setCedulaPropetario(const string &cedulaPropetario) {
    Transporte::cedulaPropetario = cedulaPropetario;
}

const string &Transporte::getVehiculo() const {
    return vehiculo;
}

void Transporte::setVehiculo(const string &vehiculo) {
    Transporte::vehiculo = vehiculo;
}

const string &Transporte::getPlaca() const {
    return placa;
}

void Transporte::setPlaca(const string &placa) {
    Transporte::placa = placa;
}

void Transporte::registrar(){
    printf("Transporte registrado con exito\n")
}

void Transporte::LlevarProducto(Empresa e){
    printf("El cliente, ha comprado el producto\n");
}

void Transporte::LlevarProductoCasa(Cliente c){
    printf("El cliente se ha afiliado a la empresa\n");
}