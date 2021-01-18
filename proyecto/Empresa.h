//
// Created by noel on 8/1/21.
//

#ifndef PROYECTOSO_EMPRESA_H
#define PROYECTOSO_EMPRESA_H
#include <string.h>

#include <string>

using namespace std;

class Empresa
{
private:
    String nombre;
    String descripcion;
    String rif;
public:
    Empresa(const String &nombre, const String &descripcion, const String &rif);

    const String &getNombre() const;

    void setNombre(const String &nombre);

    const String &getDescripcion() const;

    void setDescripcion(const String &descripcion);

    const String &getRif() const;

    void setRif(const String &rif);
};


#endif //PROYECTOSO_EMPRESA_H
