//
// Created by noel on 18/1/21.
//

#include "Solicitud.h"

Solicitud::Solicitud() {
    producto=ProductoServicio();
    metodo=MetodoPago();
    transporte=Transporte();
    cliente=Cliente();
    status="";
    empresa=Empresa();
}

Solicitud::Solicitud(const ProductoServicio &producto, const MetodoPago &metodo, const Transporte &transporte,
                     const Fecha &entrega, const string &status, const Cliente &cliente,const Empresa &empresa) : producto(producto),
                                                                                           metodo(metodo),
                                                                                           transporte(transporte),
                                                                                           entrega(entrega),
                                                                                           status(status),
                                                                                           cliente(cliente),
                                                                                           empresa(empresa){}

const ProductoServicio &Solicitud::getProducto() const {
    return producto;
}

void Solicitud::setProducto(const ProductoServicio &producto) {
    Solicitud::producto = producto;
}

const MetodoPago &Solicitud::getMetodo() const {
    return metodo;
}

void Solicitud::setMetodo(const MetodoPago &metodo) {
    Solicitud::metodo = metodo;
}

const Transporte &Solicitud::getTransporte() const {
    return transporte;
}

void Solicitud::setTransporte(const Transporte &transporte) {
    Solicitud::transporte = transporte;
}

const Fecha &Solicitud::getEntrega() const {
    return entrega;
}

void Solicitud::setEntrega(const Fecha &entrega) {
    Solicitud::entrega = entrega;
}

const string &Solicitud::getStatus() const {
    return status;
}

void Solicitud::setStatus(const string &status) {
    Solicitud::status = status;
}

const Cliente &Solicitud::getCliente() const {
    return cliente;
}

void Solicitud::setCliente(const Cliente &cliente) {
    Solicitud::cliente = cliente;
}

const Cliente &Solicitud::getEmpresa() const {
    return empresa;
}

void Solicitud::setEmpresa(const Cliente &empresa) {
    Solicitud::empresa = empresa;
}

bool Solicitud::verificarStatus(){
    if(producto==NULL) return false;
    if(producto.getCantidad()==0){
        if(empresa==NULL) return false;
        if (empresa.getListp()==NULL) return NULL;
        list<ProductoServicio> lista= empresa.getListp();
        lista.remove(producto);
        return false;
    }
    if(producto.getCantidad()=>1){
        if(metodo.verificar()){
            producto.setCantidad(producto.getCantidad()-1);
            if (producto.getCantidad()==0){
                if(empresa==NULL) return false;
                if (empresa.getListp()==NULL) return NULL;
                list<ProductoServicio> lista= empresa.getListp();
                lista.remove(producto);
            }
            printf("Verificacion realizada con exito\n");
            return true;
        }
        return false;
    }
    return false;
}