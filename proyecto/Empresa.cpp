//
// Created by noel on 18/1/21.
//

#include "Empresa.h"

Empresa::Empresa() {}

Empresa::Empresa(const string &nombre, const string &descripcion, const list<ProductoServicio> &listp) : nombre(nombre),
                                                                                                         descripcion(
                                                                                                                 descripcion),
                                                                                                         listp(listp) {}

const string &Empresa::getNombre() const {
    return nombre;
}

void Empresa::setNombre(const string &nombre) {
    Empresa::nombre = nombre;
}

const string &Empresa::getDescripcion() const {
    return descripcion;
}

void Empresa::setDescripcion(const string &descripcion) {
    Empresa::descripcion = descripcion;
}

const list<ProductoServicio> &Empresa::getListp() const {
    return listp;
}

void Empresa::setListp(const list<ProductoServicio> &listp) {
    Empresa::listp = listp;
}

void Empresa::rellenarStock(){
    printf("Stock rellenado con exito\n");
}

void Empresa::anadirProducto(ProductoServicio p, int num){
printf("producto a�adido con exito\n");
}

void Empresa::quitarProducto(ProductoServicio p, int num){
    printf("producto quitado con exito\n");
}

const string &Empresa::getRif() const {
    return rif;
}

void Empresa::setRif(const string &rif) {
    Empresa::rif = rif;
}
