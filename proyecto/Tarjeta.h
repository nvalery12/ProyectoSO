//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_TARJETA_H
#define PROYECTO_TARJETA_H
#include "MetodoPago.h"

class Tarjeta : public MetodoPago{
private:
    string numTarjeta;
    string banco;
public:
    Tarjeta();

    Tarjeta(int cantidad, const string &numTarjeta, const string &banco);

    const string &getNumTarjeta() const;

    void setNumTarjeta(const string &numTarjeta);

    const string &getBanco() const;

    void setBanco(const string &banco);
};


#endif //PROYECTO_TARJETA_H
