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
public:
    MetodoPago();

    MetodoPago(int cantidad);

    int getCantidad() const;

    void setCantidad(int cantidad);
};


#endif //PROYECTO_METODOPAGO_H
