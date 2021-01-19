//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_METODOPAGO_H
#define PROYECTO_METODOPAGO_H
#include <iostream>
#include <string>

using namespace std;
class MetodoPago {
protected:
    int cantidad;
    int abono;
public:
    MetodoPago();

    MetodoPago(int cantidad);

    int getCantidad() const;

    void setCantidad(int cantidad);

    int getAbono() const;

    void setAbono(int abono);

    bool verificar();
};


#endif //PROYECTO_METODOPAGO_H
