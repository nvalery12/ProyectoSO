#include <iostream>
#include <stdlib.h>
#include <list>
#include <thread>

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
    bool rellenarStock(Empresa e, string codigo, int cant);
    bool vaciarStock(Empresa e, string codigo, int cant);
    bool agregarProducto(Empresa e, ProductoServicio p);
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

bool Empresa::rellenarStock(Empresa e, string codigo, int cant){
    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it = lista.begin();
    
    // Buscamos el elemento codigo
    while (it != lista.end()){ 
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

bool Empresa::agregarProducto(Empresa e, ProductoServicio p){
    e.getList().push_back(p);
    printf("producto agregado con exito\n");
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
            printf("producto quitado con exito\n");
            return true;
        }
        it++;
    }
    
    printf("producto quitado con exito\n");
    return false;
}
//FIN CLASE EMPRESA






















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
    void llevarProducto(string s, string p);
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

void Transporte::llevarProducto(string s, string p){
    printf("Producto enviado a la empresa\n");
}

void Transporte::llevarProductoCasa(string s, string p){
    printf("El cliente se ha afiliado a la empresa\n");
}
//FIN CLASE TRANSPORTE












//-------------------------------------------------------------------------------------------------------------------------
//CLASE METODO PAGO

class MetodoPago {
protected:
    int cantidad;
    int abono;
public:
    MetodoPago();

    MetodoPago(int cantidad, int abono);

    int getCantidad() const;

    void setCantidad(int cantidad);

    int getAbono() const;

    void setAbono(int abono);

    bool verificar(int a, int c);
};

MetodoPago::MetodoPago() {
    cantidad = 0;
    abono = 0;
}

MetodoPago::MetodoPago(int cant, int a){
    cantidad = cant;
    abono = a;
}

int MetodoPago::getCantidad() const {
    return cantidad;
}

void MetodoPago::setCantidad(int cantidad) {
    MetodoPago::cantidad = cantidad;
}

int MetodoPago::getAbono() const {
    return abono;
}

void MetodoPago::setAbono(int abono) {
    MetodoPago::abono = abono;
}

bool MetodoPago::verificar(int a, int c) {
    if(a>=c){
        return true;
    }
    return false;
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
public:
    Solicitud(ProductoServicio p, MetodoPago pago, Transporte t, string estado);
    Solicitud();
    void setProducto(ProductoServicio p);
    ProductoServicio getProducto();
    void setPago(MetodoPago pago);
    void setTransporte(Transporte t);
    void setStatus(string estado);
    MetodoPago getPago();
    Transporte getTransporte();
    string getStatus();
    bool verificarStatus(Empresa empresa, string nombrep, bool band);
};

Solicitud::Solicitud(ProductoServicio p, MetodoPago pago, Transporte t, string estado)
{
    producto=p;
    metodopago=pago;
    transporte=t;
    status=estado;
}

Solicitud::Solicitud()
{
    producto=ProductoServicio();
    metodopago=MetodoPago();
    transporte=Transporte();
    status="";
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
MetodoPago Solicitud::getPago(){
    return metodopago;
}
Transporte Solicitud::getTransporte(){
    return transporte;
}
string Solicitud::getStatus(){
    return status;
}

//PROCESOS

bool Solicitud::verificarStatus(Empresa empresa, string nombrep, bool band){
    if(producto.getCodigo() == "") return false;
    if(producto.getCantidad()==0){
        if(empresa.getRif() == "") return false;
        if (empresa.getList().empty() == true) return false;
        list<ProductoServicio> lista = empresa.getList();
        list<ProductoServicio>::iterator it = lista.begin();
        //Eliminar producto
        while (it != lista.end()){ 
            if(it->getNombre() != nombrep){
                lista.erase(it);
            }
            it++;
        }
        empresa.setListp(lista);
        return false;
    }
    if(producto.getCantidad()>=1){
        if(band == true){
            producto.setCantidad(producto.getCantidad()-1);
            if (producto.getCantidad()==0){
                if(empresa.getRif() == "") return false;
                if (empresa.getList().empty() == true) return false;
                list<ProductoServicio> lista = empresa.getList();
                list<ProductoServicio>::iterator it = lista.begin();
                //Eliminar producto
                while (it != lista.end()){ 
                    if(it->getNombre() != nombrep){
                        lista.erase(it);
                    }
                    it++;
                }
                empresa.setListp(lista);
            }
            printf("Verificacion realizada con exito\n");
            return true;
        }
        return false;
    }
    return false;
}

//FIN CLASE SOLICITUD







//-------------------------------------------------------------------------------------------------------------------------
//CLASE CLIENTE
class Cliente
{
private:
    string nombre;
    string numTlf;
    string residencia;
    Empresa empresa;
public:
    Cliente(string name,string tlf,string resi,Empresa e);
    Cliente();
    void setNombre(string name);
    void setNumTlf(string des);
    void setResidencia(string riff);
    void setEmpresa(Empresa e);
    string getNombre();
    string getNumTlf();
    string getResidencia();
    Empresa getEmpresa();
    bool comprar(bool band);
    bool afiliarse(Cliente c, Empresa e);
};

Cliente::Cliente(string name,string tlf,string resi,Empresa e)
{
    nombre=name;
    numTlf=tlf;
    residencia=resi;
    empresa = e;
}

Cliente::Cliente()
{
    nombre="";
    numTlf="";
    residencia="";
    empresa = Empresa();
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
void Cliente::setEmpresa(Empresa e){
    empresa = e;
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
Empresa Cliente::getEmpresa(){
    return empresa;
}

//Procesos

bool Cliente::comprar(bool band) {
    if (band == false){
        cout<<"[Error] Error en la compra"<<endl;
        return false;
    }
    if (band == true){
        cout<<"[Aviso] Compra realizada con exito"<<endl;
        return true;
    }
}

bool Cliente::afiliarse(Cliente c, Empresa e){
    c.setEmpresa(e);
    printf("El cliente se ha afiliado a la empresa\n");
    return true;
}

//FIN DE CLASE CLIENTE



//-------------------------------------------------------------------------------------------------------------------------
//Funcion de registro de Transporte
list<Transporte> registrarTransporte(list<Transporte> listT){
    char temporal[100];
    char temporal2[100];
    char temporal3[100];
    char temporal4[100];
    string np="";
    string cip="";
    string vehiculo="";
    string placa="";
    int cap=0;
    
    printf("Ingresar nombre del propietario\n");
    scanf("%100s", temporal);
    np = temporal;
    
    printf("Ingresar la Cedula de identidad del propietario\n");
    scanf("%100s", temporal2);
    cip = temporal2;
    
    printf("Ingresar el vehiculo del propietario\n");
    scanf("%100s", temporal3);
    vehiculo = temporal3;
    
    printf("Ingresar la placa del vehiculo del propietario\n");
    scanf("%100s", temporal4);
    placa = temporal4;
    
    printf("Ingresar la capcidad vehiculo\n");
    scanf("%d", &cap);
    
    list<Transporte>::iterator it = listT.begin();
    bool band = true;
    
    if(listT.empty() == false){
        // Buscamos el elemento placa
        while (it != listT.end()){ 
            if(it->getPlaca() == placa){
                band = false;
                printf("Transporte ya registrado\n");
                break;
            }
            it++;
        }
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
    char temporal2[100];
    list<ProductoServicio> listp;
    string nombre="";
    string descripcion="";
    int codigo=0;
    
    printf("Ingresar nombre de la empresa\n");
    scanf("%100s", temporal);
    nombre = temporal;
    
    printf("Ingresar la descripcion de la empresa\n");
    scanf("%100s", temporal2);
    descripcion = temporal2;
    
    printf("Ingresar el rif de la empresa\n");
    scanf("%d", codigo);
    string rifC(std::to_string(codigo));
    string rif = "J-" + rifC;
    
    list<Empresa>::iterator it = listE.begin();
    bool band = true;
    
    if(listE.empty() == false){
        // Buscamos el elemento rif
        while (it != listE.end()){ 
            if(it->getRif() == rif){
                band = false;
                printf("Empresa ya registrada\n");
                break;
            }
            it++;
        }
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
    char temporal2[100];
    char temporal3[100];
    Empresa e = Empresa();
    string nombre="";
    string numTlf="";
    string residencia="";
    
    printf("Ingresar nombre del cliente\n");
    scanf("%100s", temporal);
    nombre = temporal;
    
    printf("Ingresar numero de telefono del cliente\n");
    scanf("%100s", temporal2);
    numTlf = temporal2;
    
    printf("Ingresar residencia del cliente\n");
    scanf("%100s", temporal3);
    residencia = temporal3;
    
    list<Cliente>::iterator it = listC.begin();
    bool band = true;
    
    if(listC.empty() == false){
        // Buscamos el elemento numero de telefono
        while (it != listC.end()){ 
            if(it->getNumTlf() == numTlf){
                band = false;
                printf("Cliente ya registrado\n");
                break;
            }
            it++;
        }
    }
    
    if(band == true){
        listC.push_back(Cliente(nombre,numTlf,residencia,e));
    }
    
    return listC;
}









//-------------------------------------------------------------------------------------------------------------------------
//LLEVAR PRODUCTO
bool llevarpe(list<Transporte> listT, list<Empresa> liste){
    
    list<ProductoServicio> lista;
    Empresa e = Empresa();
    Transporte t = Transporte();
    // Se obtiene un iterador al inicio de la lista  
    bool band=false; bool band2= false;
    char temporal[100];
    char temporal2[100];
    char temporal3[100];
    char temporal4[100];

    printf("ingresar la placa del transporte");
    char p[100];
    scanf("%100s", p);
    string placa = p;

    list<Transporte>::iterator it3 = listT.begin();

    //Lista de Transportes
    while (it3 != listT.end() ){ 
        cout << it3->getPlaca() << endl;
        it3++;
    }
    
    //Buscar si la empresa existe
    if(listT.empty() == false){
        while (it3 != listT.end()){ 
            if(it3->getPlaca() == placa){
                t = *it3;
                band = true;
            }
            it3++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la operacion");
    }

    if(band == false){
        printf("Transporte no existe. No se pudo realizar el proceso");
        return false;            
    }

    

    printf("Nombre de la empresa a llevar el producto");
    temporal[100];
    scanf("%100s", temporal);
    string nombre = temporal;

    list<Empresa>::iterator it = liste.begin();
    //Lista de empresas
    while (it != liste.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }
    
    //Buscar si la empresa existe
    if(liste.empty() == false){
        while (it != liste.end()){ 
            if(it->getNombre() == nombre){
                band = true;
                e = *it;
                lista = it->getList();
            }
            it++;
        }
    }else{
        printf("Empresa no existe. No se pudo realizar el proceso");
    }

    if(band == false){
        printf("La empresa no existe");
        return false;            
    }


    printf("Ingersar codigo del producto a enviar\n");
    scanf("%100s", temporal2);
    string cod = temporal2;          
    list<ProductoServicio>::iterator it2 = lista.begin();
    string nombreP = "";
    int cant = 0;

    //Buscar si el producto existe
    while(band2 == false){
        // Buscamos el elemento nombre
        while (it2 != lista.end()){ 
            if(it2->getCodigo() != cod){
                band2 = true;
                nombreP = it2->getNombre();
            }
            it2++;
        }
        
        if(band2 == false){
            printf("El producto ya existe en el inventario de la empresa\n");
        }
    }
    
    if(band2 == false){
        printf("Ingersar la descripcion del producto a enviar\n");
        scanf("%100s", temporal3);
        string des = temporal3;
        
        printf("Ingersar el nombre del producto a enviar\n");
        scanf("%100s", temporal4);
        nombreP = temporal4;
        
        printf("Ingersar el precio producto a enviar\n");
        int prec;
        scanf("%d", &prec);
        
        printf("Ingersar la cantidad\n");
        scanf("%d", &cant);
        
        ProductoServicio p = ProductoServicio(nombreP,des,prec,cod,cant);
        
        e.agregarProducto(e,p);
    }else{
        printf("Ingersar la cantidad a enviar\n");
        scanf("%d", &cant);
        e.rellenarStock(e,cod,cant);
    }
    
    t.llevarProducto(nombre, nombreP);
    
    return true;
}

















//-------------------------------------------------------------------------------------------------------------------------
//LLEVAR PRODUCTO A LA CASA DE CLIENTE
bool llevarpc(list<Transporte> listT, list<Cliente> liste){
    
    Cliente c = Cliente();
    list<ProductoServicio> lista;
    // Se obtiene un iterador al inicio de la lista  
    list<Cliente>::iterator it = liste.begin();
    bool band=false, band2 = false;
   
    printf("ingresar la placa del transporte");
    char p[100];
    scanf("%100s", p);
    string placa = p;

    Transporte t = Transporte();
    list<Transporte>::iterator it3 = listT.begin();

    //Lista de Transportes
    while (it3 != listT.end() ){ 
        cout << it3->getPlaca() << endl;
        it3++;
    }
    
    //Buscar si el transporte existe
    if(listT.empty() == false){
        while (it3 != listT.end()){ 
            if(it3->getPlaca() == placa){
                t = *it3;
                band = true;
            }
            it3++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la operacion");
    }

    if(band == false){
        printf("Transporte no existe. No se pudo realizar el proceso");
        return false;            
    }



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
                c = *it;
                band = true;
                break;
            }
            it++;
        }
        
        if(band == false){
            printf("Cliente no existe\n");
            return false;
        }
    }
    
    if(c.getEmpresa().getNombre() == ""){
        printf("el cliente no se encuentra afiliado a una empresa");
        return false;
    }

    Empresa e = c.getEmpresa();
    list<ProductoServicio> lisp = c.getEmpresa().getList();
    list<ProductoServicio>::iterator it2 = lisp.begin();

    printf("Ingersar codigo del producto a enviar\n");
    char temporal2[100];
    scanf("%100s", temporal2);
    string cod = temporal2;          
    string nombreP = "";
    int cant = 0;

    //Buscar si el producto existe
    while(band2 == false){
        // Buscamos el elemento nombre
        while (it2 != lista.end()){ 
            if(it2->getCodigo() != cod){
                band2 = true;
                nombreP = it2->getNombre();
            }
            it2++;
        }
        
        if(band2 == false){
            printf("El producto ya existe en el inventario de la empresa\n");
            return false;
        }
    }
    
    if(band2 == false){
        printf("Ingersar la cantidad a enviar\n");
        scanf("%d", &cant);
        e.vaciarStock(e,cod,cant);
    }
    
    t.llevarProducto(nombre, nombreP);
    
    return true;
    
}













//-------------------------------------------------------------------------------------------------------------------------
//Funcion de agregar producto del almacen de la empresa
bool agregarP(list<Empresa> liste){
    Empresa e = Empresa();
    bool band = false;
    char nom[50];
    char temporal[100];
    char temporal2[100];
    char temporal3[100];
    list<Empresa>::iterator it = liste.begin();
    
    printf("Ingresar el nombre de la empresa a agregar el producto\n");
    scanf("%100s", nom);
    string nombre = nom;

    if(liste.empty() == false){
        if(liste.empty() == false){
            // Buscamos el elemento nombre
            while (it != liste.end()){ 
                if(it->getNombre() == nombre){
                    e = *it;
                    band = true;
                    break;
                }
                it++;
            }
            if(band == false){
                printf("No esta la empresa a buscar\n");
                return false;
            }
        }
    }else{
        printf("Lista vacia. no se puede agrgar objeto");
        return false;
    }
    
    printf("Ingersar el producto a enviar\n");
    scanf("%100s", temporal);
    string nombreP = temporal;
    
    printf("Ingersar la descripcion del producto a enviar\n");
    scanf("%100s", temporal2);
    string des = temporal2;
    
    printf("Ingersar el codigo del producto a enviar\n");
    scanf("%100s", temporal3);
    string cod = temporal3;
    
    printf("Ingersar el precio del producto a enviar\n");
    int prec;
    scanf("%d", &prec);
    
    printf("Ingersar el cantidad del producto a enviar\n");
    int cant;
    scanf("%d", &cant);
    
    ProductoServicio p = ProductoServicio(nombreP,des,prec,cod,cant);
    
    e.agregarProducto(e,p);
    
    return true;
}










//-------------------------------------------------------------------------------------------------------------------------
//Funcion de Eliminar producto del almacen
bool quitarP(list<Empresa> liste){
    Empresa e = Empresa();
    char temporal[100];
    char temporal2[100];
    bool band = false;

    printf("Ingersar el nopmbre de la empresa\n");
    scanf("%100s", temporal);
    string nombre = temporal;

    list<Empresa>::iterator it = liste.begin();
    // Buscamos el elemento nombre
    if(liste.empty() == false){
        while (it != liste.end()){ 
            if(it->getNombre() == nombre){
                e = *it;
                break;
            }
            it++;
        }
    }else{
        printf("Lista vacia. Producto no enviado\n");
        return false;
    }

    printf("Ingersar el codigo del producto a eliminar\n");
    scanf("%100s", temporal2);
    string codigo = temporal2;
    
    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it2 = lista.begin();
    // Buscamos el elemento nombre

    while (it2 != lista.end()){ 
        if(it2->getCodigo() == codigo){
            e.quitarProducto(e,codigo);
            band = true;
            break;
        }
        it2++;
    }

    if(band == false){
        printf("No se encontro el producto a eliminar\n");
        return false;
    }
    
    printf("Producto Servicio a eliminado");
    return true;
}











//Funcion que rellena el stock
bool addstock(list<Empresa> liste){
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

    list<ProductoServicio> listp = e.getList();   
    list<ProductoServicio>::iterator it2 = listp.begin();

    //Lista de productos y servicios de la empresa
    while (it2 != listp.end()){ 
        printf("Nombre: %s. Codigo: %s",it2->getNombre(), it2->getCodigo());
        it2++;
    }

    printf("Ingersar el codigo de el producto\n");
    scanf("%100s", temporal2);
    string codigo = temporal2;

    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo() == codigo){
            band2 = true;
        }
        it2++;
    }
    
    if(band2 == false){
        return false;
    }
    
    printf("Ingersar el codigo de el producto\n");
    scanf("%d", &cant);
    
    e.rellenarStock(e,codigo,cant);
    
    return true;
}




















//Funcion que rellena el stock
bool deletestock(list<Empresa> liste){
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

    list<ProductoServicio> listp = e.getList();   
    list<ProductoServicio>::iterator it2 = listp.begin();

    //Lista de productos y servicios de la empresa
    while (it2 != listp.end()){ 
        printf("Nombre: %s. Codigo: %s",it2->getNombre(), it2->getCodigo());
        it2++;
    }

    printf("Ingersar el codigo de el producto\n");
    scanf("%100s", temporal2);
    string codigo = temporal2;

    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo() == codigo){
            band2 = true;
        }
        it2++;
    }
    
    if(band2 == false){
        return false;
    }
    
    printf("Ingersar el codigo de el producto\n");
    scanf("%d", &cant);
    
    e.vaciarStock(e,codigo,cant);
    
    return true;
}











//Funcion para afiliar el cliente
bool clienteafiliar(list<Cliente> listc, list<Empresa> liste){
    
    char temporal[100];
    char temporal2[100];
    bool band = false, band2 = false;

    printf("Ingersar el numero de telefono del cliente\n");
    scanf("%100s", temporal);
    string num = temporal;
    Cliente c = Cliente();
    
    list<Cliente>::iterator it = listc.begin();
    // Buscamos el elemento nombre del cliente
    if(listc.empty() == false){
        while (it != listc.end()){ 
            if(it->getNumTlf() == num){
                band = true;
                c = *it;
            }
            it++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la afiliacion\n");
        return false;
    }
    
    if(band == false){
        printf("El cliente no existe\n");
        return false;
    }


    printf("Ingersar el nombre de la empresa a afiliarse\n");
    scanf("%100s", temporal2);
    string nombre = temporal2;
    Empresa e = Empresa();
    
    list<Empresa>::iterator it2 = liste.begin();
    // Buscamos el elemento nombre
    if(liste.empty() == false){ 
        while (it2 != liste.end()){ 
            if(it2->getNombre() == nombre){
                band2 = true;
                e = *it2;
            }
            it2++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la afiliacion\n");
    }

    if(band2 == false){
        printf("La empresa no existe\n");
        return false;
    }
    
    c.afiliarse(c,e);
    return true;
}










//Funcion de compra del cliente
bool clientecomprar(list<Cliente> listc){
    char temporal[100];
    char temporal2[100];
    bool band = false;

    printf("Ingersar el nombre del cliente\n");
    scanf("%100s", temporal);
    string nombre = temporal;
    Cliente c = Cliente();
    
    list<Cliente>::iterator it = listc.begin();
    // Buscamos el elemento nombre del cliente
    if(listc.empty() == false){
        while (it != listc.end()){ 
            if(it->getNombre() == nombre){
                band = true;
                c = *it;
            }
            it++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la afiliacion\n");
        return c.comprar(band);
    }
    
    if(band == false){
        printf("El cliente no existe\n");
        return c.comprar(band);
    }

    //Verificamos si el cliente esta registrado a una empresa
    Empresa e = c.getEmpresa();
    if(e.getRif() == ""){ 
        printf("El cliente no esta registrado a ninguna empresa");
        return c.comprar(band);
    }

    //Verificamos si en la empresa existe el objeto a comprar
    printf("Ingersar el producto a comprar por el cliente\n");
    scanf("%100s", temporal2);
    string producto = temporal2;

    list<ProductoServicio> listp = e.getList();
    list<ProductoServicio>::iterator it2 = listp.begin();
    ProductoServicio p = ProductoServicio();
    band = false;
    // Buscamos el elemento producto de la empresa
    if(listc.empty() == false){
        while (it2 != listp.end()){ 
            if(it2->getNombre() == producto){
                band = true;
                p = *it2;
            }
            it2++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la operacion\n");
        return c.comprar(band);
    }
    
    if(band == false){
        printf("El producto no existe en la empresa\n");
        return c.comprar(band);
    }


    //Realizacion de la compra
    MetodoPago metodo = MetodoPago();
    metodo.setCantidad(p.getPrecio());
    int cant = metodo.getCantidad();

    printf("Ingresar la cantidad de dinero a abonar\n");
    int abono=0;
    scanf("%d", &abono);
    cant = cant - abono;

    band = metodo.verificar(abono,cant);
    while(band == false){
        printf("Ingresar la cantidad de dinero a abonar\n");
        scanf("%d", &abono);
        cant = cant - abono;
        band = metodo.verificar(abono,cant);
        if(band == true){
            int vuelto = 0;
            vuelto = cant * (-1);
            printf("El cliente tiene un vuelto de %d", vuelto);
        }
    }   
    printf("Compra realizada con exito");

    //Verificar la Solicitud
    Solicitud s = Solicitud();
    bool bandera = false;
    bandera = s.verificarStatus(e,p.getNombre(),band);
    if(bandera == false){
        printf("Solicitud rechazada");
        return c.comprar(bandera);
    }

    return c.comprar(bandera);
}













void mensaje(){
    printf("¿Como estas?\n");
    return;
}

void* reception(void *arg){
    printf("\n\nOPERACION DE EMPRESAS\nQue desea hacer?\n[1] REGISTRAR EMPRESA\n[2] RELLENAR STOCK\n[3] VACIAR STOCK\n");
    printf("[4] AGREGAR PRODUCTO\n[5] ELIMINAR PRODUCTO\n");
    int resp2;
    scanf("%d", &resp2);

    switch (resp2)
    {
        case 1:
            printf("Hola\n");
            mensaje();
            //listEmpresas = registrarEmpresa(listEmpresas);
            break;
        
        case 2:
            printf("Hola\n");
            break;
        
        case 3:
            printf("Hola\n");
            //band = deletestock(listEmpresas);
            break;
        
        case 4:
            printf("Hola\n");
            //band = agregarP(listEmpresas);
            break;
        
        case 5:
            printf("Hola\n");
            //band = quitarP(listEmpresas);
            break;

        default:
            break;
    }
    return NULL;
}

void* review(void *arg){
    printf("\n\nOPERACION DE CLIENTE\nQue desea hacer?\n[1] REGISTRAR CLIENTE\n[2] AFILIARSE A EMPRESA\n[3] HACER SOLICITUD\n");
    printf("[4] COMPRAR PRODUCTO\n");
    int resp3;
    scanf("%d", &resp3);

    switch (resp3)
    {
        case 1:
            printf("hola\n");
            mensaje();
            //listClientesGeneral = registrarCliente(listClientesGeneral);
            break;
        
        case 2:
            printf("hola");
            //band = clienteafiliar(listClientesGeneral, listEmpresas);
            break;
        
        case 3:
            printf("hola");
            //Hacer solicitud
            break;
        
        case 4:
            printf("hola");
            //Comprar producto
            break;
        
        case 5:
            printf("hola");
            //band = quitarP(listEmpresas);
            break;

        default:
            break;
    }
    return NULL;
}

void* qualityCheck(void *arg){
    printf("\n\nOPERACION DE TRANSPORTE\nQue desea hacer?\n[1] REGISTRAR TRANSPORTE\n[2] ENVIAR PRODUCTO A EMPRESA\n[3] ENVIAR PRODUCTO A CASA DE UN CLIENTE\n");
    int resp3;
    scanf("%d", &resp3);

    switch (resp3)
    {
        case 1:
            printf("hola\n");
            mensaje();
            //listTransportes = registrarTransporte(listTransportes);
            break;
        
        case 2:
            printf("hola");
            //band = llevarpe(listTransportes, listEmpresas);
            break;
        
        case 3:
            printf("hola");
            //band = llevarpc(listTransportes, listClientesGeneral);
            break;

        default:
            break;
    }
    return NULL;
}

int main(){
    
    int counter;
    int i = 0;
    int err;
    
    thread_create(&(tid[0]), NULL, &reception, NULL);
    thread_create(&(tid[1]), NULL, &review, NULL);
    thread_create(&(tid[2]), NULL, &qualityCheck, NULL);
    
    thread_join(tid[0], NULL);
    thread_join(tid[1], NULL);
    thread_join(tid[2], NULL);
    

    return 0;
}