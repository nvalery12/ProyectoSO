//
// Created by noel on 8/1/21.
//

#include "ProductoServicio.h"

ProductoServicio::ProductoServicio(const String &nombre, const String &descripcion, int precio, const String &codigo,
                                   int cantidad) : nombre(nombre), descripcion(descripcion), precio(precio),
                                                   codigo(codigo), cantidad(cantidad) {}

const String &ProductoServicio::getNombre() const {
    return nombre;
}

void ProductoServicio::setNombre(const String &nombre) {
    ProductoServicio::nombre = nombre;
}

const String &ProductoServicio::getDescripcion() const {
    return descripcion;
}

void ProductoServicio::setDescripcion(const String &descripcion) {
    ProductoServicio::descripcion = descripcion;
}

int ProductoServicio::getPrecio() const {
    return precio;
}

void ProductoServicio::setPrecio(int precio) {
    ProductoServicio::precio = precio;
}

const String &ProductoServicio::getCodigo() const {
    return codigo;
}

void ProductoServicio::setCodigo(const String &codigo) {
    ProductoServicio::codigo = codigo;
}

int ProductoServicio::getCantidad() const {
    return cantidad;
}

void ProductoServicio::setCantidad(int cantidad) {
    ProductoServicio::cantidad = cantidad;
}
