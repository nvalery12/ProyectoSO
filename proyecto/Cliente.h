//
// Created by noel on 8/1/21.
//

#ifndef PROYECTOSO_CLIENTE_H
#define PROYECTOSO_CLIENTE_H
#include <String.h>

using namespace std;
class Cliente
{
private:
    String nombre;
    String numTlf;
    String residencia;
public:
    Cliente(const String &nombre, const String &numTlf, const String &residencia);

    const String &getNombre() const;

    void setNombre(const String &nombre);

    const String &getNumTlf() const;

    void setNumTlf(const String &numTlf);

    const String &getResidencia() const;

    void setResidencia(const String &residencia);
};


#endif //PROYECTOSO_CLIENTE_H
