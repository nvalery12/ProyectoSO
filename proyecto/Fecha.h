//
// Created by noel on 18/1/21.
//

#ifndef PROYECTO_FECHA_H
#define PROYECTO_FECHA_H
#include <iostream>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int ano;
public:
    Fecha(int dia, int mes, int ano);

    Fecha();

    int getDia() const;

    void setDia(int dia);

    int getMes() const;

    void setMes(int mes);

    int getAno() const;

    void setAno(int ano);
};


#endif //PROYECTO_FECHA_H
