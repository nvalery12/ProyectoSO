#include <string>
#include "Fecha.h"

using namespace std;

class MetodoPago
{
protected:
    int cantidad;
public:
    MetodoPago(int cant);
    void setCantidad(int cantidad);
    int getCantidad();
};

MetodoPago::MetodoPago(int cant)
{
    this->cantidad=cant;
}

void MetodoPago::setCantidad(int cantidad){
    this->cantidad=cantidad;
}

int MetodoPago::getCantidad(){
    return cantidad;
}

class Tarjeta : public MetodoPago
{
private:
    string numTarjeta;
    string banco;
    Fecha fechaVencimiento;
public:
    Tarjeta(int cantidad,string numTarjeta,string banco,Fecha fecha);
    void setNumTarjeta(string numTarjeta);
    void setBanco(string banco);
    string getNumTarjeta();
    string getBanco();
};

Tarjeta::Tarjeta(int cantidad, string numTarjeta,string banco,Fecha fecha): MetodoPago(cantidad)
{
    this->numTarjeta=numTarjeta;
    this->banco=banco;
    fechaVencimiento(fecha.getDia,fecha.getMes,fecha.getAno);
}

void Tarjeta::setNumTarjeta(string numTarjeta){
    this->numTarjeta=numTarjeta;
}
void Tarjeta::setBanco(string banco){
    this->banco=banco;
}
string Tarjeta::getNumTarjeta(){
    return numTarjeta;
}
string Tarjeta::getBanco(){
    return banco;
}

class Transferencia : public MetodoPago
{
private:
    string banco;
    string rif;
    string codigo;
    string correo;
public:
    Transferencia(int cantidad,string banco,string rif,string codigo,string correo);
    void setBanco(string name);
    void setCodigo(string des);
    void setRif(string riff);
    string getBanco();
    string getCodigo();
    string getRif();
    void setCorreo(string correo);
    string getCorreo();
};

Transferencia::Transferencia(int cantidad,string banco,string rif,string codigo,string correo): MetodoPago(cantidad)
{
    this->banco=banco;
    this->rif=rif;
    this->codigo=codigo;
    this->correo=correo;
}

void Transferencia::setBanco(string name){
    banco=name;
}
void Transferencia::setCodigo(string des){
    codigo=des;
}
void Transferencia::setRif(string riff){
    rif=riff;
}
string Transferencia::getBanco(){
    return banco;
}
string Transferencia::getCodigo(){
    return codigo;
}
string Transferencia::getRif(){
    return rif;
}
void Transferencia::setCorreo(string correo){
    this->correo=correo;
}
string Transferencia::getCorreo(){
    return correo;
}

class Efectivo : public MetodoPago
{
public:
    Efectivo(int cantidad);
};

Efectivo::Efectivo(int cantidad): MetodoPago(cantidad)
{
}