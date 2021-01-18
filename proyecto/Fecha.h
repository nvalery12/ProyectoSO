//
// Created by noel on 8/1/21.
//

#ifndef PROYECTOSO_FECHA_H
#define PROYECTOSO_FECHA_H


class Fecha
{
public:
    Fecha(int dia, int mes, int ano);

    int getDia() const;

    void setDia(int dia);

    int getMes() const;

    void setMes(int mes);

    int getAno() const;

    void setAno(int ano);

private:
    int dia;
    int mes;
    int ano;
};


#endif //PROYECTOSO_FECHA_H
