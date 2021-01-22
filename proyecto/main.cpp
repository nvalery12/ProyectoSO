#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;



//-------------------------------------------------------------------------------------------------------------------------
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

















//-------------------------------------------------------------------------------------------------------------------------
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
    Empresa();
    void setNombre(string name);
    void setDescripcion(string des);
    void setRif(string riff);
    void setListp(list<ProductoServicio> listp);
    string getNombre();
    string getDescripcion();
    string getRif();
    list<ProductoServicio> getList();
    void registrar();
    bool rellenarStock(Empresa e, string codigo, int cant);
    bool vaciarStock(Empresa e, string codigo, int cant);
    bool añadirProducto(Empresa e, ProductoServicio p, int num);
    bool quitarProducto(Empresa e, string c);
};

Empresa::Empresa(string nombr,string des,string riff, list<ProductoServicio> l) ////Constructron sin parametros
{
    nombre=nombr;
    descripcion=des;
    rif=riff;
    listp = l;
}

Empresa::Empresa() //Constructron con parametros
{
    nombre="";
    descripcion="";
    rif="";
    listp = listp;
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

bool Empresa::rellenarStock(Empresa e, string codigo, int cant){
    list<ProductoServicio>::iterator it = e.getList().begin();
    
    // Buscamos el elemento codigo
    while (it != e.getList().end()){ 
        if(it->getCodigo() == codigo){
            it->setCantidad(it->getCantidad() + cant);
            printf("Stock rellenado con exito\n");
            return true;
        }
        it++;
    }
    return false;
}

bool Empresa::vaciarStock(Empresa e, string codigo, int cant){
    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it = lista.begin();
    
    // Buscamos el elemento codigo
    while (it != lista.end()){ 
        if(it->getCodigo() == codigo){
            if( (it->getCantidad() - cant) > 0){
                it->setCantidad(it->getCantidad() - cant);
                printf("Stock vaciado con exito\n");
                return true;
            }else{
                lista.erase(it);
                e.setListp(lista);
                printf("Stock vaciado con exito. Producto agotado\n");
                return true;
            }
        }
        it++;
    }
    return false;
}

bool Empresa::añadirProducto(Empresa e, ProductoServicio p, int num){
    e.getList().push_back(p);
    printf("producto añadido con exito\n");
    return true;
}

bool Empresa::quitarProducto(Empresa e, string c){
    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it = lista.begin();
    
    // Buscamos el elemento nombre
    while (it != lista.end()){ 
        if(it->getCodigo() == c){
            lista.erase(it);
            e.setListp(lista);
            return true;
        }
        it++;
    }
    
    printf("producto quitado con exito\n");
    return false;
}
//FIN CLASE EMPRESA












//-------------------------------------------------------------------------------------------------------------------------
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











//-------------------------------------------------------------------------------------------------------------------------
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
    void llevarProducto(string s);
    void llevarProductoCasa(string s, string p);
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

void Transporte::llevarProducto(string s){
    printf("El cliente, ha comprado el producto\n");
}

void Transporte::llevarProductoCasa(string s, string p){
    printf("El cliente se ha afiliado a la empresa\n");
}
//FIN CLASE TRANSPORTE












//-------------------------------------------------------------------------------------------------------------------------
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











//-------------------------------------------------------------------------------------------------------------------------
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









//-------------------------------------------------------------------------------------------------------------------------
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









//-------------------------------------------------------------------------------------------------------------------------
//Funcion de registro de Transporte
list<Transporte> registrarTransporte(list<Transporte> listT){
    char temporal[100];
    string np="";
    string cip="";
    string vehiculo="";
    string placa="";
    int cap=0;
    
    printf("Ingresar nombre del propietario\n");
    scanf("%100s", temporal);
    np = temporal;
    
    printf("Ingresar la Cedula de identidad del propietario\n");
    scanf("%100s", temporal);
    cip = temporal;
    
    printf("Ingresar el vehiculo del propietario\n");
    scanf("%100s", temporal);
    vehiculo = temporal;
    
    printf("Ingresar la placa del vehiculo del propietario\n");
    scanf("%100s", temporal);
    placa = temporal;
    
    printf("Ingresar la capcidad vehiculo\n");
    scanf("%d", &cap);
    
    list<Transporte>::iterator it = listT.begin();
    bool band = true;
    
    // Buscamos el elemento placa
    while (it != listT.end()){ 
        if(it->getPlaca() == placa){
            band = false;
            printf("Transporte ya registrado\n");
            break;
        }
        it++;
    }
    
    if(band == true){
        listT.push_back(Transporte(np,cip,vehiculo,placa,cap));
    }
    
    return listT;
}









//-------------------------------------------------------------------------------------------------------------------------
//Funcion de registro de empresa
list<Empresa> registrarEmpresa(list<Empresa> listE){
    char temporal[100];
    list<ProductoServicio> listp;
    string nombre="";
    string descripcion="";
    string rif="";
    
    printf("Ingresar nombre de la empresa\n");
    scanf("%100s", temporal);
    nombre = temporal;
    
    printf("Ingresar la descripcion de la empresa\n");
    scanf("%100s", temporal);
    descripcion = temporal;
    
    printf("Ingresar el rif de la empresa\n");
    scanf("%100s", temporal);
    rif = temporal;
    
    list<Empresa>::iterator it = listE.begin();
    bool band = true;
    
    // Buscamos el elemento rif
    while (it != listE.end()){ 
        if(it->getRif() == rif){
            band = false;
            printf("Empresa ya registrada\n");
            break;
        }
        it++;
    }
    
    if(band == true){
        listE.push_back(Empresa(nombre,descripcion,rif,listp));
    }
    
    return listE;
}













//-------------------------------------------------------------------------------------------------------------------------
//Funcion de registro de cliente
list<Cliente> registrarCliente(list<Cliente> listC){
    char temporal[100];
    string nombre="";
    string numTlf="";
    string residencia="";
    
    printf("Ingresar nombre del cliente\n");
    scanf("%100s", temporal);
    nombre = temporal;
    
    printf("Ingresar numero de telefono del cliente\n");
    scanf("%100s", temporal);
    numTlf = temporal;
    
    printf("Ingresar residencia del cliente\n");
    scanf("%100s", temporal);
    residencia = temporal;
    
    list<Cliente>::iterator it = listC.begin();
    bool band = true;
    
    // Buscamos el elemento numero de telefono
    while (it != listC.end()){ 
        if(it->getNumTlf() == numTlf){
            band = false;
            printf("Cliente ya registrado\n");
            break;
        }
        it++;
    }
    
    if(band == true){
        listC.push_back(Cliente(nombre,numTlf,residencia));
    }
    
    return listC;
}









//-------------------------------------------------------------------------------------------------------------------------
//LLEVAR PRODUCTO
void llevarpe(Transporte t, list<Empresa> liste){
    
    list<ProductoServicio> lista;
    Empresa e;
    // Se obtiene un iterador al inicio de la lista  
    list<Empresa>::iterator it = liste.begin();
    bool band=false; bool band2= false;
   
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
                e = *it;
                lista = it->getList();
            }
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
    
    printf("Ingersar el producto a enviar\n");
    scanf("%100s", temporal);
    string nombreP = temporal;
   
        
    list<ProductoServicio>::iterator it2 = lista.begin();
        
        
        //Buscar si el producto existe
    while(band2 == false){
        // Buscamos el elemento nombre
        while (it2 != lista.end()){ 
            if(it2->getNombre() != nombreP){
                band2 = true;
            }
            it2++;
        }
        
        if(band2 == false){
            int resp2;
            printf("El objeto existe existe\n");
            printf("Desea continuar??\n presion [1] para si y [0] para no. . .\n");
            scanf("%d",&resp2);
            
            while(resp2!=1 && resp2!=0){
                if(resp2 == 0){
                    printf("Entrega de producto finalizado\n");
                    return;
                } else if(resp2 == 1){
                    printf("Ingersar el producto a enviar");
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
    
    e.añadirProducto(e,p,cant);
    
    t.llevarProductoCasa(nombre, nombreP);
    
}










//-------------------------------------------------------------------------------------------------------------------------
//LLEVAR PRODUCTO A LA CASA DE CLIENTE
void llevarpc(Transporte t, list<Cliente> liste){
    
    list<ProductoServicio> lista;
    // Se obtiene un iterador al inicio de la lista  
    list<Cliente>::iterator it = liste.begin();
    bool band=false;
   
    printf("Nombre del cliente a llevar el producto");
    char temporal[100];
    scanf("%100s", temporal);
    string nombre = temporal;
    
    //Lista de clientes
    while (it != liste.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }
    
    //Buscar si la cliente existe
    while(band == false){
        // Buscamos el elemento nombre
        while (it != liste.end()){ 
            if(it->getNombre() == nombre){
                band = true;
                break;
            }
            it++;
        }
        
        if(band == false){
            int resp;
            printf("Cliente no existe\n");
            printf("Desea continuar??\n presion [1] para si y [0] para no. . .\n");
            scanf("%d",&resp);
            
            while(resp!=1 && resp!=0){
                if(resp == 0){
                    printf("Entrega de producto finalizado\n");
                    return;
                } else if(resp == 1){
                    printf("Nombre del Cliente a llevar el producto");
                    scanf("%100s", temporal);
                    nombre = temporal;
                }else{
                    printf("respuesta invalida\n\n");
                }
            }
            
        }
    }
    
    printf("Ingersar el producto a enviar\n");
    scanf("%100s", temporal);
    string nombreP = temporal;
    
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
    
    
    
    t.llevarProductoCasa(nombre, nombreP);
    
}













//-------------------------------------------------------------------------------------------------------------------------
//Funcion de agregar producto del almacen de la empresa
void agregarP(Empresa e){
    char temporal[100];
    
    printf("Ingersar el producto a enviar\n");
    scanf("%100s", temporal);
    string nombreP = temporal;
    
    printf("Ingersar la descripcion del producto a enviar\n");
    scanf("%100s", temporal);
    string des = temporal;
    
    printf("Ingersar el codigo del producto a enviar\n");
    scanf("%100s", temporal);
    string cod = temporal;
    
    printf("Ingersar el precio del producto a enviar\n");
    int prec;
    scanf("%d", &prec);
    
    printf("Ingersar el cantidad del producto a enviar\n");
    int cant;
    scanf("%d", &cant);
    
    ProductoServicio p = ProductoServicio(nombreP,des,prec,cod,cant);
    
    e.añadirProducto(e,p,1);
    
    return;
}










//-------------------------------------------------------------------------------------------------------------------------
//Funcion de Eliminar producto del almacen
void quitarP(Empresa e){
    char temporal[100];
    bool band = false;
    ProductoServicio p;
    
    printf("Ingersar el codigo del producto a eliminar\n");
    scanf("%100s", temporal);
    string codigo = temporal;
    
    list<ProductoServicio>::iterator it = e.getList().begin();
    // Buscamos el elemento nombre
    while (it != e.getList().end()){ 
        if(it->getCodigo() == codigo){
            p = *it;
            e.quitarProducto(e,codigo);
            band = true;
            break;
        }
        it++;
    }
    
    if(band == true){  
        printf("Producto Servicio a eliminado");
    }else{
        printf("No existe el producto servicio a eliminar");
    }
    return;
}











//Funcion que rellena el stock
bool stock(list<Empresa> liste){
    Empresa e;
    char temporal[100], temporal2[100];
    int cant=0;
    bool band = false, band2=false;
    
    printf("Ingersar el nombre de la empresar\n");
    scanf("%100s", temporal);
    string nombre = temporal;
    
    list<Empresa>::iterator it = liste.begin();
    // Buscamos el elemento nombre
    while (it != liste.end()){ 
        if(it->getNombre() == nombre){
            band = true;
            e = *it;
        }
        it++;
    }
    
    if(band == false){
        return false;
    }

    
    printf("Ingersar el codigo de el producto\n");
    scanf("%100s", temporal2);
    string codigo = temporal2;
    
    list<ProductoServicio>::iterator it2 = e.getList().begin();
    // Buscamos el elemento nombre
    while (it2 != e.getList().end()){ 
        if(it2->getCodigo() == codigo){
            band2 = true;
        }
        it++;
    }
    
    if(band2 == false){
        return false;
    }
    
    printf("Ingersar el codigo de el producto\n");
    scanf("%d", &cant);
    
    e.rellenarStock(e,codigo,cant);
    
    return true;
}










//MAIN

int main()
{
    int resp=0;
    list<Cliente> listClientesGeneral;
    list<Empresa> listE;
    list<ProductoServicio> listP;
    list<Transporte> listT;
    
    
    printf("BIENVENIDO\n¿Que desea hacer?\n[0] SALIR\n[1] AGREGAR EMPRESA\n[2] AGREGAR CLIENTE A EMPRESA\n[3] INGRESAR PRODUCTO O SERVICIO A UNA EMPRESA\n");
    printf("[4] COMPRAR\n");
    scanf("%d",&resp);
    
    return 0;
}
