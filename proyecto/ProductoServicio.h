//
// Created by noel on 8/1/21.
//

#ifndef PROYECTOSO_PRODUCTOSERVICIO_H
#define PROYECTOSO_PRODUCTOSERVICIO_H

#include <String.h>

using namespace std;
class ProductoServicio {
private:
    String nombre;
    String descripcion;
    int precio;
    String codigo;
    int cantidad;
public:
    ProductoServicio(const String &nombre, const String &descripcion, int precio, const String &codigo, int cantidad);

    const String &getNombre() const;

    void setNombre(const String &nombre);

    const String &getDescripcion() const;

    void setDescripcion(const String &descripcion);

    int getPrecio() const;

    void setPrecio(int precio);

    const String &getCodigo() const;

    void setCodigo(const String &codigo);

    int getCantidad() const;

    void setCantidad(int cantidad);
};


#endif //PROYECTOSO_PRODUCTOSERVICIO_H
