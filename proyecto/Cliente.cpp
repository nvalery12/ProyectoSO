#include <string>

using namespace std;

class Cliente
{
private:
    string nombre;
    string numTlf;
    string residencia;
public:
    Cliente(string name,string tlf,string resi);
    void setNombre(string name);
    void setNumTlf(string des);
    void setResidencia(string riff);
    string getNombre();
    string getNumTlf();
    string getResidencia();
};

Cliente::Cliente(string name,string tlf,string resi)
{
    nombre=name;
    numTlf=tlf;
    residencia=resi;
}

void Cliente::setNombre(string name){
    nombre=name;
}
void Cliente::setNumTlf(string des){
    numTlf=des;
}
void Cliente::setResidencia(string resi){
    residencia=resi;
}
string Cliente::getNombre(){
    return nombre;
}
string Cliente::getResidencia(){
    return residencia;
}
string Cliente::getNumTlf(){
    return numTlf;
}