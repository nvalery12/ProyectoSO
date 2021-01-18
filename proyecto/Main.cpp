#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

//CLASE PRODUCTOSERVICIO
class ProductoServicio
{
private:
    string nombre;
    string descripcion;
    int precio;
    string codigo;
    int cantidad;
public:
    ProductoServicio(string name,string des,int prec,string cod,int cant);
    ProductoServicio();
    void setNombre(string name);
    void setDescripcion(string des);
    void setCodigo(string cod);
    string getNombre();
    string getDescripcion();
    string getCodigo();
    void setPrecio(int prec);
    void setCantidad(int cant);
    int getPrecio();
    int getCantidad();
};

ProductoServicio::ProductoServicio(string name,string des,int prec,string cod,int cant) //Constructor con parametros
{
    nombre=name;
    descripcion=des;
    precio=prec;
    codigo=cod;
    cantidad=cant;
}

ProductoServicio::ProductoServicio(){ //Constructor sin parametros
    nombre="";
    descripcion="";
    precio=0;
    codigo="";
    cantidad=0;
}

void ProductoServicio::setNombre(string name){
    nombre=name;
}
void ProductoServicio::setDescripcion(string des){
    descripcion=des;
}
void ProductoServicio::setCodigo(string Codigof){
    codigo=Codigof;
}
string ProductoServicio::getNombre(){
    return nombre;
}
string ProductoServicio::getDescripcion(){
    return descripcion;
}
string ProductoServicio::getCodigo(){
    return codigo;
}
void ProductoServicio::setPrecio(int prec){
    precio=prec;
}
void ProductoServicio::setCantidad(int cant){
    cantidad=cant;
}
int ProductoServicio::getPrecio(){
    return precio;
}
int ProductoServicio::getCantidad(){
    return cantidad;
}

//FIN DE LA CLASE PRODUCTOSERVICIO

















//CLASE EMPRESA
class Empresa
{
private:
    string nombre;
    string descripcion;
    string rif;
    list<ProductoServicio> listp;
public:
    Empresa(string nombr,string des,string riff, list<ProductoServicio> l);
    //Empresa();
    void setNombre(string name);
    void setDescripcion(string des);
    void setRif(string riff);
    void setListp(list<ProductoServicio> listp);
    string getNombre();
    string getDescripcion();
    string getRif();
    list<ProductoServicio> getList();
    void registrar();
    void rellenarStock();
    void añadirProducto(ProductoServicio p, int num);
    void quitarProducto(ProductoServicio p, int num);
};

Empresa::Empresa(string nombr,string des,string riff, list<ProductoServicio> l) ////Constructron sin parametros
{
    nombre=nombr;
    descripcion=des;
    rif=riff;
    listp = l;
}

/*Empresa::Empresa() //Constructron con parametros
{
    nombre="";
    descripcion="";
    rif="";
    listp = NULL;
}*/

void Empresa::setNombre(string name){
    nombre=name;
}
void Empresa::setDescripcion(string des){
    descripcion=des;
}
void Empresa::setRif(string riff){
    rif=riff;
}
void Empresa::setListp(list<ProductoServicio> l){
    listp = l;
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
list<ProductoServicio> Empresa::getList(){
    return listp;
}

//Procesos

void Empresa::registrar(){
    printf("Empresa registrada con exito\n");
}

void Empresa::rellenarStock(){
    printf("Stock rellenado con exito\n");
}

void Empresa::añadirProducto(ProductoServicio p, int num){
    printf("producto añadido con exito\n");
}

void Empresa::quitarProducto(ProductoServicio p, int num){
    printf("producto quitado con exito\n");
}
//FIN CLASE EMPRESA










//CLASE CLIENTE
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

//FIN DE CLASE CLIENTE









//CLASE TRANSPORTE

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
//FIN CLASE TRANSPORTE










//CLASE METODO PAGO

class MetodoPago
{
protected:
    int cantidad;
public:
    MetodoPago(int cant);
    MetodoPago();
    void setCantidad(int cantidad);
    int getCantidad();
};

MetodoPago::MetodoPago(int cant)
{
    cantidad=cant;
}

MetodoPago::MetodoPago()
{
    cantidad=0;
}

void MetodoPago::setCantidad(int cant){
    cantidad=cant;
}

int MetodoPago::getCantidad(){
    return cantidad;
}

class Tarjeta : public MetodoPago
{
private:
    string numTarjeta;
    string banco;
public:
    Tarjeta(int cantidad,string numTarjeta,string banco);
    void setNumTarjeta(string numTarjeta);
    void setBanco(string banco);
    string getNumTarjeta();
    string getBanco();
};

Tarjeta::Tarjeta(int cantidad, string numTarjeta,string banco)
{
    this->numTarjeta=numTarjeta;
    this->banco=banco;
    this->cantidad=cantidad;
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

class Transferencia
{
private:
    string banco;
    string rif;
    string codigo;
    string correo;
public:
    Transferencia(string banco,string rif,string codigo,string correo);
    void setBanco(string name);
    void setCodigo(string des);
    void setRif(string riff);
    string getBanco();
    string getCodigo();
    string getRif();
    void setCorreo(string correo);
    string getCorreo();
};

Transferencia::Transferencia(string banco,string rif,string codigo,string correo)
{
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

Efectivo::Efectivo(int cantidad)
{
    this->cantidad=cantidad;
}

//FIN CLASE METODOPAGO










//CLASE FECHA

class Fecha
{
private:
    int dia;
    int mes;
    int ano;
public:
    Fecha(int d,int m,int a);
    Fecha();
    void setDia(int d);
    void setMes(int m);
    void setAno(int a);
    int getDia();
    int getMes();
    int getAno();
};

Fecha::Fecha(int d,int m,int a)
{
    dia=d;
    mes=m;
    ano=a;
}

Fecha::Fecha()
{
    dia=0;
    mes=0;
    ano=0;
}

void Fecha::setDia(int d){
    dia=d;
}
void Fecha::setMes(int m){
    mes=m;
}
void Fecha::setAno(int a){
    ano=a;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAno(){
    return ano;
}

//FIN CLASE FECHA









//CLASE SOLICITUD

class Solicitud
{
private:
    ProductoServicio producto;
    MetodoPago metodopago;
    Transporte transporte;
    Fecha fechaentrega;
    string status;
    Cliente cliente;
public:
    Solicitud(ProductoServicio p, MetodoPago pago, Transporte t, string estado, Cliente c);
    Solicitud();
    void setProducto(ProductoServicio p);
    ProductoServicio getProducto();
    void setPago(MetodoPago pago);
    void setTransporte(Transporte t);
    void setStatus(string estado);
    void setCliente(Cliente c);
    MetodoPago getPago();
    Transporte getTransporte();
    string getStatus();
    Cliente getCliente();
    string verificarStatus();
};

Solicitud::Solicitud(ProductoServicio p, MetodoPago pago, Transporte t, string estado, Cliente c)
{
    producto=p;
    metodopago=pago;
    transporte=t;
    status=estado;
    cliente=c;
}

Solicitud::Solicitud()
{
    producto=ProductoServicio();
    metodopago=MetodoPago();
    transporte=Transporte();
    status="";
    cliente=Cliente();
}

void Solicitud::setProducto(ProductoServicio p){
    producto=p;
}
ProductoServicio Solicitud::getProducto(){
    return producto;
}
void Solicitud::setPago(MetodoPago pago){
    metodopago=pago;
}
void Solicitud::setTransporte(Transporte t){
    transporte=t;
}
void Solicitud::setStatus(string estado){
    status=estado;
}
void Solicitud::setCliente(Cliente c){
    cliente=c;
}
MetodoPago Solicitud::getPago(){
    return metodopago;
}
Transporte Solicitud::getTransporte(){
    return transporte;
}
string Solicitud::getStatus(){
    return status;
}
Cliente Solicitud::getCliente(){
    return cliente;
}

//PROCESOS

string Solicitud::verificarStatus(){
    printf("Verificacion realizada con exito\n");
    return "SIIIIIUUUU";
}

//FIN CLASE SOLICITUD
//Funcion de registro de Transporte
void registrarEmpresa(Transporte t){
    string np="";
    string cip="";
    string vehiculo="";
    string placa="";
    int cap=0;
    printf("Ingresar nombre del propietario\n");
    cin >> np;
    printf("Ingresar la Cedula de identidad del propietario\n");
    cin >> cip;
    printf("Ingresar el vehiculo del propietario\n");
    cin >> vehiculo;
    printf("Ingresar la placa del vehiculo del propietario\n");
    cin >> placa;
    printf("Ingresar la capcidad vehiculo\n");
    cin >> cap;
    t.setNombre(np);
    t.setCedula(cip);
    t.setVehiculo(vehiculo);
    t.setPlaca(placa);
    t.setCapacidad(cap);
}

//Funcion de registro de empresa
void registrarEmpresa(Empresa e){
    string nombre="";
    string descripcion="";
    string rif="";
    printf("Ingresar nombre de la empresa\n");
    cin >> nombre;
    printf("Ingresar la descripcion de la empresa\n");
    cin >> descripcion;
    printf("Ingresar el rif de la empresa\n");
    cin >> rif;
    e.setNombre(nombre);
    e.setDescripcion(descripcion);
    e.setRif(rif);
}

//Funcion de registro de cliente
void registrarCliente(Cliente c){
    string nombre="";
    string numTlf="";
    string residencia="";
    printf("Ingresar nombre del cliente\n");
    cin >> nombre;
    printf("Ingresar numero de telefono del cliente\n");
    cin >> numTlf;
    printf("Ingresar residencia del cliente\n");
    cin >> residencia;
    c.setNombre(nombre);
    c.setNumTlf(numTlf);
    c.setResidencia(residencia);
}





//-------------------------------------------------------------------------------------------------------------------------
//LLEVAR PRODUCTO
void llevarpe(Transporte t, list<Empresa> liste){
    
    list<ProductoServicio> lista;
    // Se obtiene un iterador al inicio de la lista  
    list<Empresa>::iterator it = liste.begin();
    bool band=false; bool band2= false;
    int i, i2; //indice de la empresa, el almacen tien el mismo indice
    int indice1, indice2;
   
    printf("Nombre de la empresa a llevar el producto");
    char temporal[100];
    scanf("%100s", temporal);
    string nombre = temporal;
    
    //Lista de empresas
    while (it != liste.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }
    
    //Buscar si la empresa existe
    while(band == false){
        // Buscamos el elemento nombre
        while (it != liste.end()){ 
            if(it->getNombre() == nombre){
                band = true;
                indice1=i;
            }
            i++;
            it++;
        }
        
        if(band == false){
            int resp;
            printf("la empresa no existe\n");
            printf("Desea continuar??\n presion [1] para si y [0] para no. . .\n");
            scanf("%d",&resp);
            
            while(resp!=1 && resp!=0){
                if(resp == 0){
                    printf("Entrega de producto finalizado\n");
                    return;
                } else if(resp == 1){
                    printf("Nombre de la empresa a llevar el producto");
                    scanf("%100s", temporal);
                    nombre = temporal;
                }else{
                    printf("respuesta invalida\n\n");
                }
            }
            
        }
    }
        
        //printf("Empresa seleccionada: %s\n", nombre);
        
        //Buscar la la lista de productos y servicios de la empresa
        int c=indice1;
        i=0;
        while (it != liste.end() ){ 
            if(i==indice1){
                lista = it->getList();
            }
            i++;
            it++;
        }
    
        printf("Ingersar el producto a enviar\n");
        scanf("%100s", temporal);
        string nombreP = temporal;
   
        
    list<ProductoServicio>::iterator it2 = lista.begin();
        
        
        //Buscar si el producto existe
    while(band2 == false){
        // Buscamos el elemento nombre
        while (it2 != lista.end()){ 
            if(it2->getNombre() == nombreP){
                band2 = true;
                indice2=i2;
            }
            i2++;
            it2++;
        }
        
        if(band2 == false){
            int resp2;
            printf("la empresa no existe\n");
            printf("Desea continuar??\n presion [1] para si y [0] para no. . .\n");
            scanf("%d",&resp2);
            
            while(resp2!=1 && resp2!=0){
                if(resp2 == 0){
                    printf("Entrega de producto finalizado\n");
                    return;
                } else if(resp2 == 1){
                    printf("Nombre de la empresa a llevar el producto");
                    scanf("%100s", temporal);
                    nombreP = temporal;
                }else{
                    printf("respuesta invalida\n\n");
                }
            }
            
        }
    }
    
    printf("Ingersar el producto a enviar\n");
    scanf("%100s", temporal);
    string des = temporal;
    
    printf("Ingersar el producto a enviar\n");
    scanf("%100s", temporal);
    string cod = temporal;
    
    printf("Ingersar el producto a enviar\n");
    int prec;
    scanf("%d", &prec);
    
    printf("Ingersar el producto a enviar\n");
    int cant;
    scanf("%d", &cant);
    
    ProductoServicio p = ProductoServicio(nombreP,des,prec,cod,cant);
}











//MAIN

int main()
{
    list<Cliente> listC;
    list<Empresa> listE;
    list<ProductoServicio> listP;
    list<Transporte> listT;
    Cliente c = Cliente();
    Cliente c1 = Cliente("Cesar","04165881300","Yara Yara");
    ProductoServicio p1 = ProductoServicio("Termo","Envase para bebidas",2000,"02134",4);
    ProductoServicio p2 = ProductoServicio("telefono","Telefono Iphone",9999,"32104",21);
    //Empresa e1 = Empresa("Pollera Cesar","Se vende pollo","J-123456789");
    Transporte t1 = Transporte("Noel","200000","aveo","2a3b",4);
    
    //Cliente
    registrarCliente(c);
    c1.registrar();
    
    c1.comprar(c1,p1);
    
    
    //Transporte
    
    return 0;
}
