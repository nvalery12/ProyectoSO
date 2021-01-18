//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_CLIENTE_H
#define PROYECTO_CLIENTE_H
#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombre;
    string numTlf;
    string residencia;
public:
    Cliente();

    Cliente(const string &nombre, const string &numTlf, const string &residencia);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getNumTlf() const;

    void setNumTlf(const string &numTlf);

    const string &getResidencia() const;

    void setResidencia(const string &residencia);

    bool comprar();

    bool afiliarse();
};


#endif //PROYECTO_CLIENTE_H
