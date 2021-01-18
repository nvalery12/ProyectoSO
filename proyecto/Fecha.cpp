//
// Created by noel on 8/1/21.
//

#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

int Fecha::getDia() const {
    return dia;
}

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

int Fecha::getMes() const {
    return mes;
}

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

int Fecha::getAno() const {
    return ano;
}

void Fecha::setAno(int ano) {
    Fecha::ano = ano;
}
