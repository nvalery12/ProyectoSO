class Cliente
{
private:
    string nombre;
    string numTlf;
    string residencia;
public:
    Cliente(string name,string tlf,string resi);
    Cliente();
    void setNombre(string name);
    void setNumTlf(string des);
    void setResidencia(string riff);
    string getNombre();
    string getNumTlf();
    string getResidencia();
    void registrar();
    void comprar(Cliente c, ProductoServicio p);
    void afiliarse(Cliente c, Empresa e);
};

Cliente::Cliente(string name,string tlf,string resi)
{
    nombre=name;
    numTlf=tlf;
    residencia=resi;
}

Cliente::Cliente()
{
    nombre="";
    numTlf="";
    residencia="";
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

//Procesos
void Cliente::registrar(){
    printf("Cliente registrado con exito\n");
}

void Cliente::comprar(Cliente c, ProductoServicio p){
    printf("El cliente, ha comprado el producto\n");
}

void Cliente::afiliarse(Cliente c, Empresa e){
    printf("El cliente se ha afiliado a la empresa\n");
}
