#include <string>

using namespace std;

class Empresa
{
private:
    string nombre;
    string descripcion;
    string rif;
public:
    Empresa(string nombr,string des,string riff);
    void setNombre(string name);
    void setDescripcion(string des);
    void setRif(string riff);
    string getNombre();
    string getDescripcion();
    string getRif();
};

Empresa::Empresa(string nombr,string des,string riff)
{
    nombre=nombr;
    descripcion=des;
    rif=riff;
}

void Empresa::setNombre(string name){
    nombre=name;
}
void Empresa::setDescripcion(string des){
    descripcion=des;
}
void Empresa::setRif(string riff){
    rif=riff;
}
string Empresa::getNombre(){
    return nombre;
}
string Empresa::getDescripcion(){
    return descripcion;
}
string Empresa::getRif(){
    return rif;
}