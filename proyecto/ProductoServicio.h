//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_PRODUCTOSERVICIO_H
#define PROYECTO_PRODUCTOSERVICIO_H
#include <iostream>
#include <string>

using namespace std;
class ProductoServicio {
private:
    string nombre;
    string descripcion;
    int precio;
    string codigo;
    int cantidad;
public:
    ProductoServicio(const string &nombre, const string &descripcion, int precio, const string &codigo, int cantidad);

    ProductoServicio();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getDescripcion() const;

    void setDescripcion(const string &descripcion);

    int getPrecio() const;

    void setPrecio(int precio);

    const string &getCodigo() const;

    void setCodigo(const string &codigo);

    int getCantidad() const;

    void setCantidad(int cantidad);
};


#endif //PROYECTO_PRODUCTOSERVICIO_H
