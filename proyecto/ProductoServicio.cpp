//
// Created by noel on 18/1/21.
//

#include "ProductoServicio.h"

ProductoServicio::ProductoServicio(const string &nombre, const string &descripcion, int precio, const string &codigo,
                                   int cantidad) : nombre(nombre), descripcion(descripcion), precio(precio),
                                                   codigo(codigo), cantidad(cantidad) {}

const string &ProductoServicio::getNombre() const {
    return nombre;
}

void ProductoServicio::setNombre(const string &nombre) {
    ProductoServicio::nombre = nombre;
}

const string &ProductoServicio::getDescripcion() const {
    return descripcion;
}

void ProductoServicio::setDescripcion(const string &descripcion) {
    ProductoServicio::descripcion = descripcion;
}

int ProductoServicio::getPrecio() const {
    return precio;
}

void ProductoServicio::setPrecio(int precio) {
    ProductoServicio::precio = precio;
}

const string &ProductoServicio::getCodigo() const {
    return codigo;
}

void ProductoServicio::setCodigo(const string &codigo) {
    ProductoServicio::codigo = codigo;
}

int ProductoServicio::getCantidad() const {
    return cantidad;
}

void ProductoServicio::setCantidad(int cantidad) {
    ProductoServicio::cantidad = cantidad;
}

ProductoServicio::ProductoServicio() {
    nombre="";
    descripcion="";
    precio=0;
    codigo="";
    cantidad=0;
}
