class Empresa
{
private:
    string nombre;
    string descripcion;
    string rif;
public:
    Empresa(string nombr,string des,string riff);
    Empresa();
    void setNombre(string name);
    void setDescripcion(string des);
    void setRif(string riff);
    string getNombre();
    string getDescripcion();
    string getRif();
    void registrar();
    void rellenarStock();
};

Empresa::Empresa(string nombr,string des,string riff) ////Constructron sin parametros
{
    nombre=nombr;
    descripcion=des;
    rif=riff;
}

Empresa::Empresa() //Constructron con parametros
{
    nombre="";
    descripcion="";
    rif="";
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

//Procesos

void Empresa::registrar(){
    printf("Empresa registrada con exito\n");
}

void Empresa::rellenarStock(){
    printf("Stock rellenado con exito\n");
}