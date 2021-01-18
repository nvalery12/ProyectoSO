class Transporte
{
private:
    int capacidad;
    string nombre;
    string cedulaPropetario;
    string vehiculo;
    string placa;
public:
    Transporte(string name,string cedula,string vehi,string plac,int capa);
    Transporte();
    void setCapacidad(int cap);
    int getCapacidad();
    void setNombre(string name);
    void setCedula(string cedula);
    void setVehiculo(string vehi);
    void setPlaca(string plac);
    string getNombre();
    string getCedula();
    string getVehiculo();
    string getPlaca();
    void registrar();
    void LlevarProducto(Empresa e);
    void LlevarProductoCasa(Cliente c);
};

Transporte::Transporte(string name,string cedula,string vehi,string plac,int capa)
{
    nombre=name;
    cedulaPropetario=cedula;
    vehiculo=vehi;
    placa=plac;
    capacidad=capa;
}

Transporte::Transporte()
{
    nombre="";
    cedulaPropetario="";
    vehiculo="";
    placa="";
    capacidad=0;
}

void Transporte::setCapacidad(int cap){
    capacidad=cap;
}
int Transporte::getCapacidad(){
    return capacidad;
}
void Transporte::setNombre(string name){
    nombre=name;
}
void Transporte::setCedula(string cedula){
    cedulaPropetario=cedula;
}
void Transporte::setVehiculo(string vehi){
    vehiculo=vehi;
}
void Transporte::setPlaca(string plac){
    placa=plac;
}
string Transporte::getNombre(){
    return nombre;
}
string Transporte::getCedula(){
    return cedulaPropetario;
}
string Transporte::getVehiculo(){
    return vehiculo;
}
string Transporte::getPlaca(){
    return placa;
}

//PROCESOS

void Transporte::registrar(){
    printf("Transporte registrado con exito\n");
}

void Transporte::LlevarProducto(Empresa e){
    printf("El cliente, ha comprado el producto\n");
}

void Transporte::LlevarProductoCasa(Cliente c){
    printf("El cliente se ha afiliado a la empresa\n");
}