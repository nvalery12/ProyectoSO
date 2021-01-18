//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_TRANSPORTE_H
#define PROYECTO_TRANSPORTE_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Empresa.h"

using namespace std;

class Transporte {
private:
    int capacidad;
    string nombre;
    string cedulaPropetario;
    string vehiculo;
    string placa;
public:
    Transporte();

    Transporte(int capacidad, const string &nombre, const string &cedulaPropetario, const string &vehiculo,
               const string &placa);

    int getCapacidad() const;

    void setCapacidad(int capacidad);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getCedulaPropetario() const;

    void setCedulaPropetario(const string &cedulaPropetario);

    const string &getVehiculo() const;

    void setVehiculo(const string &vehiculo);

    const string &getPlaca() const;

    void setPlaca(const string &placa);

    void registrar();

    void LlevarProducto(Empresa e);

    void LlevarProductoCasa(Cliente c);
};


#endif //PROYECTO_TRANSPORTE_H
