//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_EMPRESA_H
#define PROYECTO_EMPRESA_H
#include <iostream>
#include <string>
#include <list>
#include "ProductoServicio.h"

using namespace std;

class Empresa {
private:
    string nombre;
    string descripcion;
    string rif;
    list<ProductoServicio> listp;
public:
    Empresa();

    Empresa(const string &nombre, const string &descripcion, const list<ProductoServicio> &listp);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getDescripcion() const;

    void setDescripcion(const string &descripcion);

    const list<ProductoServicio> &getListp() const;

    void setListp(const list<ProductoServicio> &listp);

    void rellenarStock();

    void anadirProducto(ProductoServicio p, int num);

    void quitarProducto(ProductoServicio p,int num);

    const string &getRif() const;

    void setRif(const string &rif);
};


#endif //PROYECTO_EMPRESA_H
