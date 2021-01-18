//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_TRANSFERENCIA_H
#define PROYECTO_TRANSFERENCIA_H
#include "MetodoPago.h"

class Transferencia : public MetodoPago
{
private:
    string banco;
    string rif;
    string codigo;
    string correo;
public:
    Transferencia();

    Transferencia(int cantidad, const string &banco, const string &rif, const string &codigo, const string &correo);

    const string &getBanco() const;

    void setBanco(const string &banco);

    const string &getRif() const;

    void setRif(const string &rif);

    const string &getCodigo() const;

    void setCodigo(const string &codigo);

    const string &getCorreo() const;

    void setCorreo(const string &correo);
};


#endif //PROYECTO_TRANSFERENCIA_H
