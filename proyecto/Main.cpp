#include <iostream>
#include <stdlib.h>
#include <string>
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
    nombre="vacio";
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
    
    list<Transporte>::iterator it = listT.begin();
    bool band = true;
    
    if(listT.empty() == false){
        // Buscamos el elemento placa
        while (it != listT.end()){ 
            if(it->getPlaca().compare(placa) == 0){
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
    list<ProductoServicio> listp;
    string nombre="";
    string descripcion="";
    int codigo=0;
    
    printf("Ingresar nombre de la empresa\n");
        cin >> nombre;
    
    printf("Ingresar la descripcion de la empresa\n");
    cin >> descripcion;
    
    printf("Ingresar el rif de la empresa\n");
        cin >> codigo;
    string rifC(std::to_string(codigo));
    string rif = "J-" + rifC;
    
    list<Empresa>::iterator it = listE.begin();
    bool band = true;
    
    if(listE.empty() == false){
        // Buscamos el elemento rif
        while (it != listE.end()){ 
            if(it->getRif().compare(rif) == 0){
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
    Empresa e = Empresa();
    string nombre="";
    string numTlf="";
    string residencia="";
    
    printf("Ingresar nombre del cliente\n");
    cin >> nombre;
    
    printf("Ingresar numero de telefono del cliente\n");
    cin >> numTlf;
    
    printf("Ingresar residencia del cliente\n");
    cin >> residencia;
    
    list<Cliente>::iterator it = listC.begin();
    bool band = true;
    
    if(listC.empty() == false){
        // Buscamos el elemento numero de telefono
        while (it != listC.end()){ 
            if(it->getNumTlf().compare(numTlf) == 0){
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

    printf("ingresar la placa del transporte\n");
    string placa;
    cin >> placa;

    list<Transporte>::iterator it3 = listT.begin();

    //Lista de Transportes
    if(listT.empty() == false){
        while (it3 != listT.end() ){ 
            cout << it3->getPlaca() << endl;
            it3++;
        }
    }
    
    it3 = listT.begin();

    //Buscar si la empresa existe
    if(listT.empty() == false){
        while (it3 != listT.end()){ 
            if(it3->getPlaca().compare(placa) == 0){
                t = *it3;
                band = true;
            }
            it3++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la operacion\n");
    }

    if(band == false){
        printf("Transporte no existe. No se pudo realizar el proceso");
        return false;            
    }

    

    printf("Nombre de la empresa a llevar el producto");
    string nombre = "";
    cin >> nombre;

    list<Empresa>::iterator it = liste.begin();
    //Lista de empresas
    while (it != liste.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }
    
    it = liste.begin();

    //Buscar si la empresa existe
    if(liste.empty() == false){
        while (it != liste.end()){ 
            if(it->getNombre().compare(nombre) == 0){
                band = true;
                e = *it;
                lista = it->getList();
            }
            it++;
        }
    }else{
        printf("Empresa no existe. No se pudo realizar el proceso");
        return false;
    }

    if(band == false){
        printf("La empresa no existe");
        return false;            
    }


    printf("Ingersar codigo del producto a enviar\n");
    string cod = "";
    cin >> cod;          
    list<ProductoServicio>::iterator it2 = lista.begin();
    string nombreP = "";
    int cant = 0;

    //Buscar si el producto existe
    while(band2 == false){
        // Buscamos el elemento nombre
        while (it2 != lista.end()){ 
            if(it2->getCodigo().compare(cod) != 0){
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
        string des = "";
        cin >> des;
        
        printf("Ingersar el nombre del producto a enviar\n");
        nombreP = "";
        cin >> nombreP;
        
        printf("Ingersar el precio producto a enviar\n");
        int prec;
        cin >> prec;
        
        printf("Ingersar la cantidad\n");
        cin >> cant;
        
        ProductoServicio p = ProductoServicio(nombreP,des,prec,cod,cant);
        
        e.agregarProducto(e,p);
    }else{
        printf("Ingersar la cantidad a enviar\n");
        cin >> cant;
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
    bool band=false, band2 = false;
   
    printf("ingresar la placa del transporte");
    string placa = "";
    cin >> placa;

    Transporte t = Transporte();
    list<Transporte>::iterator it3 = listT.begin();

    //Lista de Transportes
    while (it3 != listT.end() ){ 
        cout << it3->getPlaca() << endl;
        it3++;
    }
    
    it3 = listT.begin();

    //Buscar si el transporte existe
    if(listT.empty() == false){
        while (it3 != listT.end()){ 
            if(it3->getPlaca().compare(placa) == 0){
                t = *it3;
                band = true;
            }
            it3++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la operacion\n");
    }

    if(band == false){
        printf("Transporte no existe. No se pudo realizar el proceso\n");
        return false;            
    }



    printf("Nombre del cliente a llevar el producto");
    string nombre = "";
    cin >> nombre;
    
    // Se obtiene un iterador al inicio de la lista  
    list<Cliente>::iterator it = liste.begin();

    //Lista de clientes
    while (it != liste.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }
    
    it = liste.begin();

    //Buscar si la cliente existe
    while(band == false){
        // Buscamos el elemento nombre
        while (it != liste.end()){ 
            if(it->getNombre().compare(nombre) == 0){
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
    
    if(c.getEmpresa().getNombre().compare("vacio")){
        printf("el cliente no se encuentra afiliado a una empresa");
        return false;
    }

    Empresa e = c.getEmpresa();
    list<ProductoServicio> lisp = c.getEmpresa().getList();
    list<ProductoServicio>::iterator it2 = lisp.begin();

    printf("Ingersar codigo del producto a enviar\n");
    string cod = "";
    cin >> cod;          
    string nombreP = "";
    int cant = 0;

    //Buscar si el producto existe
    while(band2 == false){
        // Buscamos el elemento nombre
        while (it2 != lista.end()){ 
            if(it2->getCodigo().compare(cod) != 0){
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
        cin >> cant;
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
    list<Empresa>::iterator it = liste.begin();
    
    printf("Ingresar el nombre de la empresa a agregar el producto\n");
    string nombre = "";
    cin >> nombre;

    if(liste.empty() == false){
        if(liste.empty() == false){
            // Buscamos el elemento nombre
            while (it != liste.end()){ 
                if(it->getNombre().compare(nombre) == 0){
                    e = *it;
                    band = true;
                    break;
                }
                it++;
            }
        }
    }else{
        printf("Lista vacia. no se puede agregar objeto");
        return false;
    }

    if(band == false){
        printf("No existe la empresa a buscar\n");
        return false;
    }
    
    printf("Ingersar el producto a enviar\n");
    string nombreP = "";
    cin >> nombreP;
    
    printf("Ingersar la descripcion del producto a enviar\n");
    string des = "";
    cin >> des;
    
    printf("Ingersar el codigo del producto a enviar\n");
    string cod = "";
    cin >> cod;
    
    printf("Ingersar el precio del producto a enviar\n");
    int prec;
    cin >> prec;
    
    printf("Ingersar el cantidad del producto a enviar\n");
    int cant;
    cin >> cant;
    
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
                band = true;
                e = *it;
                break;
            }
            it++;
        }
    }else{
        printf("Lista vacia. Producto no eliminado\n");
        return false;
    }

    if(band == false){
        printf("La empresa no existe en la lista\n");
        return false;
    }

    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it2 = lista.begin();
    while (it2 != lista.end()){ 
        cout << "Nombre: " << it2->getNombre() << ". Codigo: " << it2->getCodigo() << endl;
        it2++;
    }

    printf("\nIngersar el codigo del producto a eliminar\n");
    string codigo = "";
    cin >> codigo;
    
    it2 = lista.begin();
    band = false;
    // Buscamos el elemento nombre
    while (it2 != lista.end()){ 
        if(it2->getCodigo().compare(codigo) == 0){
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
    int cant=0;
    bool band = false;
    
    printf("Ingersar el nombre de la empresar\n");
    string nombre = "";
    cin >> nombre;
    
    list<Empresa>::iterator it = liste.begin();
    // Buscamos el elemento nombre
    while (it != liste.end()){ 
        if(it->getNombre().compare(nombre) == 0){
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
    string codigo = "";
    cin >> codigo;

    it2 = listp.begin();
    band = false;
    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo().compare(codigo) == 0){
            band = true;
        }
        it2++;
    }
    
    if(band == false){
        printf("No existe el objeto a rellenar el stock\n");
        return false;
    }
    
    printf("Ingersar la cantidad del producto\n");
    cin >> cant;
    
    e.rellenarStock(e,codigo,cant);
    
    return true;
}




















//Funcion que rellena el stock
bool deletestock(list<Empresa> liste){
    Empresa e;
    char temporal[100], temporal2[100];
    int cant=0;
    bool band = false;
    
    printf("Ingersar el nombre de la empresar\n");
    string nombre = "";
    cin >> nombre;
    
    list<Empresa>::iterator it = liste.begin();
    // Buscamos el elemento nombre
    while (it != liste.end()){ 
        if(it->getNombre().compare(nombre) == 0){
            band = true;
            e = *it;
        }
        it++;
    }
    
    if(band == false){
        printf("Produscto no existe. Operacion no realizada\n");
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
    string codigo = "";
    cin >> codigo;

    it2 = listp.begin();
    band = false;
    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo().compare(codigo) == 0){
            band = true;
        }
        it2++;
    }
    
    if(band == false){
        return false;
    }
    
    printf("Ingersar la cantidad del producto\n");
    cin >> cant;
    
    e.vaciarStock(e,codigo,cant);
    
    return true;
}











//Funcion para afiliar el cliente
bool clienteafiliar(list<Cliente> listc, list<Empresa> liste){
    bool band = false;

    printf("Ingersar el numero de telefono del cliente\n");
    string num = "";
    cin >> num;
    Cliente c = Cliente();
    
    list<Cliente>::iterator it = listc.begin();
    // Buscamos el elemento nombre del cliente
    if(listc.empty() == false){
        while (it != listc.end()){ 
            if(it->getNumTlf().compare(num) == 0){
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
    string nombre = "";
    cin >> nombre;
    Empresa e = Empresa();
    
    list<Empresa>::iterator it2 = liste.begin();
    // Buscamos el elemento nombre
    if(liste.empty() == false){ 
        while (it2 != liste.end()){ 
            if(it2->getNombre().compare(nombre) == 0){
                band = true;
                e = *it2;
            }
            it2++;
        }
    }else{
        printf("Lista vacia. No se puede realizar la afiliacion\n");
    }

    if(band == false){
        printf("La empresa no existe\n");
        return false;
    }
    
    c.afiliarse(c,e);
    return true;
}










//Funcion de compra del cliente
bool clientecomprar(list<Cliente> listc){
    bool band = false;

    printf("Ingersar el nombre del cliente\n");
    string nombre = "";
    cin >> nombre;
    Cliente c = Cliente();
    
    list<Cliente>::iterator it = listc.begin();
    // Buscamos el elemento nombre del cliente
    if(listc.empty() == false){
        while (it != listc.end()){ 
            if(it->getNombre().compare(nombre) == 0){
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
    if(e.getNombre() == "vacio"){ 
        printf("El cliente no esta registrado a ninguna empresa");
        return c.comprar(band);
    }

    //Verificamos si en la empresa existe el objeto a comprar
    printf("Ingersar el producto a comprar por el cliente\n");
    string producto = "";
    cin >> producto;

    list<ProductoServicio> listp = e.getList();
    list<ProductoServicio>::iterator it2 = listp.begin();
    ProductoServicio p = ProductoServicio();
    band = false;
    // Buscamos el elemento producto de la empresa
    if(listc.empty() == false){
        while (it2 != listp.end()){ 
            if(it2->getNombre().compare(producto) == 0){
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
    cin >> abono;
    cant = cant - abono;

    band = metodo.verificar(abono,cant);
    while(band == false){
        printf("Ingresar la cantidad de dinero a abonar\n");
        cin >> abono;
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

//MAIN

int main(){
    int resp=9;
    int resp2=9;
    bool band = false;
    list<Cliente> listClientesGeneral;
    list<Empresa> listEmpresas;
    list<Transporte> listTransportes;
    list<ProductoServicio> listPyS;

    printf("BIENVENIDO\n");

    while( resp > 0 ){

        printf("Que desea hacer?\n[0] SALIR\n[1] OPERACION DE EMPRESA\n[2] OPERACION DE CLIENTE\n[3] OPERACION DE TRANSPORTE\n");
        cin >> resp;
        cout << resp << endl;

        switch ( resp ) {

                case 0:
                    printf("Fin del programa");
                    break;

                //OPERACION DE EMPRESAS
                case 1:
                    printf("\n\nOPERACION DE EMPRESAS\nQue desea hacer?\n[1] REGISTRAR EMPRESA\n[2] RELLENAR STOCK\n[3] VACIAR STOCK\n");
                    printf("[4] AGREGAR PRODUCTO\n[5] ELIMINAR PRODUCTO\n");
                    cin >> resp2;

                    switch (resp2)
                    {
                        case 1:
                            listEmpresas = registrarEmpresa(listEmpresas);
                            break;
                        
                        case 2:
                            band = addstock(listEmpresas);
                            break;
                        
                        case 3:
                            band = deletestock(listEmpresas);
                            break;
                        
                        case 4:
                            band = agregarP(listEmpresas);
                            break;
                        
                        case 5:
                            band = quitarP(listEmpresas);
                            break;

                        default:
                            break;
                    }

                        
                //OPERACION DE CLIENTES
                case 2:
                    printf("\n\nOPERACION DE CLIENTE\nQue desea hacer?\n[1] REGISTRAR CLIENTE\n[2] AFILIARSE A EMPRESA\n[3] COMPRAR PRODUCTO\n");
                    cin >> resp2;

                    switch (resp2)
                    {
                        case 1:
                            listClientesGeneral = registrarCliente(listClientesGeneral);
                            break;
                        
                        case 2:
                            band = clienteafiliar(listClientesGeneral, listEmpresas);
                            break;
                        
                        case 3:
                            band = clientecomprar(listClientesGeneral);                            
                            break;

                        default:
                            break;
                    }
                    
    
                //OPERACION DE TRANSPORTES
                case 3:
                    printf("\n\nOPERACION DE TRANSPORTE\nQue desea hacer?\n[1] REGISTRAR TRANSPORTE\n[2] ENVIAR PRODUCTO A EMPRESA\n[3] ENVIAR PRODUCTO A CASA DE UN CLIENTE\n");
                    cin >> resp2;

                    switch (resp2)
                    {
                        case 1:
                            listTransportes = registrarTransporte(listTransportes);
                            break;
                        
                        case 2:
                            band = llevarpe(listTransportes, listEmpresas);
                            break;
                        
                        case 3:
                            band = llevarpc(listTransportes, listClientesGeneral);
                            break;

                        default:
                            break;
                    }

                    
    
                default:
                break;    
        }

    } 
 
    return 0;
}
