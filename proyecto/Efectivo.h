//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_EFECTIVO_H
#define PROYECTO_EFECTIVO_H
#include "MetodoPago.h"

class Efectivo : public MetodoPago{
public:
    Efectivo();

    Efectivo(int cantidad);
};


#endif //PROYECTO_EFECTIVO_H
