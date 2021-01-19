//
// Created by noel on 18/1/21.
//

#include "Cliente.h"

Cliente::Cliente(const string &nombre, const string &numTlf, const string &residencia) : nombre(nombre), numTlf(numTlf),
                                                                                         residencia(residencia) {}

Cliente::Cliente() {
    nombre="";
    numTlf="";
    residencia="";
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getNumTlf() const {
    return numTlf;
}

void Cliente::setNumTlf(const string &numTlf) {
    Cliente::numTlf = numTlf;
}

const string &Cliente::getResidencia() const {
    return residencia;
}

void Cliente::setResidencia(const string &residencia) {
    Cliente::residencia = residencia;
}

bool Cliente::comprar(Solicitud &solicitud) {
    if (solicitud==NULL){
        cout<<"[Error] Solicitud inexistente."<<endl;
        return false;
    }
    if (solicitud.verificarStatus()){
        cout<<"[Aviso] Compra realizada con exito"<<endl;
        return true;
    }else{
        cout<<"[Error] Error en la compra"<<endl;
    }
}
