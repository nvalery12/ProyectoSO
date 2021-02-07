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
    int vaciarStock(Empresa e, string codigo, int cant);
    list<ProductoServicio> agregarProducto(Empresa e, ProductoServicio p);
    list<ProductoServicio> quitarProducto(Empresa e, string c);
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
    nombre="vacio";
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

int Empresa::vaciarStock(Empresa e, string codigo, int cant){
    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it = lista.begin();
    
    // Buscamos el elemento codigo
    while (it != lista.end()){ 
        if(it->getCodigo() == codigo){
            printf("Stock vaciado con exito\n");
            return it->getCantidad() - cant;
        }
        it++;
    }
    return 0;
}

list<ProductoServicio> Empresa::agregarProducto(Empresa e, ProductoServicio p){
    list<ProductoServicio> lista = e.getList();
    lista.push_back(p);
    printf("producto agregado con exito\n");

    list<ProductoServicio>::iterator it = lista.begin();
    //Lista de empresas
    printf("Dentro e la funcion\n");
    while (it != lista.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }

    return lista;
}

list<ProductoServicio> Empresa::quitarProducto(Empresa e, string c){
    list<ProductoServicio> lista = e.getList();
    list<ProductoServicio>::iterator it = lista.begin();
    
    // Buscamos el elemento nombre
    while (it != lista.end()){ 
        if(it->getCodigo() == c){
            lista.erase(it);
            printf("producto quitado con exito\n");
            return lista;
        }
        it++;
    }
    
    printf("producto no fue encontrado en la lista\n");
    return lista;
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
    list<ProductoServicio> verificarStatus(Empresa empresa, string nombrep, bool band);
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

list<ProductoServicio> Solicitud::verificarStatus(Empresa empresa, string nombrep, bool band){
    list<ProductoServicio> lista = empresa.getList();
    if(producto.getCodigo() == "") return lista;
    if(producto.getCantidad()==0){
        if(empresa.getRif() == "") return lista;
        if (empresa.getList().empty() == true) return lista;
        list<ProductoServicio>::iterator it = lista.begin();
        //Eliminar producto
        while (it != lista.end()){ 
            if(it->getNombre() != nombrep){
                lista.erase(it);
            }
            it++;
        }
        return lista;
    }
    if(producto.getCantidad()>=1){
        if(band == true){
            producto.setCantidad(producto.getCantidad()-1);
            if (producto.getCantidad()==0){
                if(empresa.getRif() == "") return lista;
                if (empresa.getList().empty() == true) return lista;
                list<ProductoServicio>::iterator it = lista.begin();
                //Eliminar producto
                while (it != lista.end()){ 
                    if(it->getNombre() != nombrep){
                        lista.erase(it);
                    }
                    it++;
                }
            }
            printf("Verificacion realizada con exito\n");
            return lista;
        }
        return lista;
    }
    return lista;
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
list<Empresa> modEmpresa(Empresa e, list<Empresa> liste, string nombre){
    list<Empresa>::iterator it = liste.begin();
    bool band = false;
        //Lista de empresas
        while (it != liste.end() ){ 
            cout << it->getNombre() << " y " << nombre << endl;
            if(it->getNombre().compare(nombre) == 0){
                band=true;
                printf("Empresa modificada\n");
                *it = e;
            }
            it++;
        }
    if(band == false){
        printf("Empresa NO modificada\n");
    }
    return liste;
}











list<Cliente> modCliente(Cliente c, list<Cliente> listc, string num){
    list<Cliente>::iterator it = listc.begin();
    bool band = false;
        //Lista de clientes
        while (it != listc.end() ){ 
            cout << it->getNombre() << " y " << it->getNumTlf() << endl;
            if(it->getNumTlf().compare(num) == 0){
                band=true;
                printf("Cliente modificado\n");
                *it = c;
            }
            it++;
        }
    if(band == false){
        printf("Empresa NO modificada\n");
    }
    return listc;
}











//Modifica la el los datos de la empresa en el cliente
list<Cliente> modClienteEmpresa(list<Cliente> listc, list<Empresa> liste){
    list<Cliente>::iterator it = listc.begin();
    list<Empresa>::iterator it2 = liste.begin();
    string nombreE = "";
    bool band = false;
        //Lista de clientes
        while (it != listc.end() ){ 
            cout << it->getNombre() << " y " << it->getNumTlf() << endl;
            nombreE = it->getEmpresa().getNombre();
            //Lista de Empresas
            it2 = liste.begin();
            if(liste.empty() == false){
                printf("Entre\n");
                while(it2 != liste.end()){ 
                    if(it2->getNombre().compare(nombreE) == 0){
                        it->setEmpresa(*it2);
                    }
                    it2++;
                }
                it++;
            }
        }
    printf("Lista de Clientes modificada\n");
    return listc;
}









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
list<Empresa> llevarpe(list<Transporte> listT, list<Empresa> liste){
    
    list<ProductoServicio> lista;
    Empresa e;
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
        return liste;            
    }

    

    printf("Nombre de la empresa a llevar el producto\n");
    string nombre = "";
    cin >> nombre;

    list<Empresa>::iterator it = liste.begin();
    //Lista de empresas
    while (it != liste.end() ){ 
        cout << it->getNombre() << endl;
        it++;
    }
    
    it = liste.begin();
    band = false;
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
        printf("Empresa no existe. No se pudo realizar el proceso\n");
        return liste;
    }

    if(band == false){
        printf("La empresa no existe\n");
        return liste;            
    }


    printf("Ingersar codigo del producto a enviar\n");
    string cod = "";
    cin >> cod; 

    ProductoServicio p;         
    list<ProductoServicio>::iterator it2 = lista.begin();
    string nombreP = "";
    int cant = 0;

    while (it2 != lista.end()){ 
        cout << "codigo:" << it2->getCodigo() << endl;
        it2++;
    }

    it2 = lista.begin();
    band = false;
    //Buscar si el producto existe
    // Buscamos el elemento nombre
    if(lista.empty() == false){
        while (it2 != lista.end()){ 
            if(it2->getCodigo().compare(cod) == 0){
                band2 = true;
                nombreP = it2->getNombre();
                p = *it2;
            }
            it2++;
        }
    }else{
        printf("lista vacia\n");
    }

    if(band2 == true){
        printf("El producto ya existe en el inventario de la empresa\n");
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

        p = ProductoServicio(nombreP,des,prec,cod,cant);
        
        e.setListp(e.agregarProducto(e,p));

        //Lista de empresas
        liste = modEmpresa(e,liste,nombre);

        t.llevarProducto(nombre, nombreP);
    
        return liste;

    }else{
        printf("Ingersar la cantidad a enviar\n");
        cin >> cant;
        list<ProductoServicio> listp = e.getList();
        int suma = p.getCantidad() + cant;
        it2 = listp.begin();
        while (it2 != listp.end()){ 
            if(it2->getCodigo().compare(cod) == 0){
                it2->setCantidad(suma);
            }
            it2++;
        }

        e.setListp(listp);
        //Lista de empresas
        liste = modEmpresa(e,liste,nombre);

        t.llevarProducto(nombre, nombreP);
    
        return liste;
    }
    
}

















//-------------------------------------------------------------------------------------------------------------------------
//LLEVAR PRODUCTO A LA CASA DE CLIENTE
list<Empresa> llevarpc(list<Transporte> listT, list<Cliente> liste, list<Empresa> listc){
    
    Cliente c = Cliente();
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
        return listc;          
    }



    printf("Nombre del cliente a llevar el producto");
    string nombre = "";
    cin >> nombre;
    
    // Se obtiene un iterador al inicio de la lista  
    list<Cliente>::iterator it = liste.begin();

    //Lista de clientes
    while (it != liste.end() ){ 
        cout << "Nombre: " <<it->getNombre() << " Empresa:" << it->getEmpresa().getNombre() << endl;
        it++;
    }
    
    it = liste.begin();
    //Buscar si el cliente existe
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
        return listc;
    }

    if(c.getEmpresa().getNombre().compare("vacio") == 0){
        printf("el cliente no se encuentra afiliado a una empresa");
        return listc;
    }

    Empresa e = c.getEmpresa();
    list<ProductoServicio> listp = c.getEmpresa().getList();
    list<ProductoServicio>::iterator it2 = listp.begin();

    if(listp.empty() == true){
        printf("Lista vacia. No se puede realizar la operacion\n");
        return listc;
    }

    printf("Ingersar codigo del producto a enviar\n");
    string cod = "";
    cin >> cod;          
    string nombreP = "";
    int cant = 0;
    band2=false;
    ProductoServicio p;

    //Buscar si el producto existe
    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo().compare(cod) == 0){
            band2 = true;
            nombreP = it2->getNombre();
            p = *it2;
        }
        it2++;
    }

    if(band2 == false){
            printf("El producto NO existe en el inventario de la empresa\n");
            return listc;
    }
    
    if(band2 == true){
        printf("Ingersar la cantidad a enviar\n");
        cin >> cant;

        int resta = (p.getCantidad() - cant);
        p.setCantidad(resta);
        if(resta <= 0){
            e.setListp(e.quitarProducto(e,cod));
            listc = modEmpresa(e,listc,nombre);
        }else{
            //Cambiando el valor de la cantidad de 
            listp = e.getList();
            it2 = listp.begin();
            while (it2 != listp.end()){ 
                if(it2->getCodigo().compare(cod) == 0){
                    *it2 = p;
                    cout << "Cantidad: " << it2->getCantidad() << endl;
                }
                it2++;
            }
            e.setListp(listp);
            listc = modEmpresa(e,listc,nombre);
        }
    }
    
    t.llevarProducto(nombre, nombreP);
    
    return listc;
    
}













//-------------------------------------------------------------------------------------------------------------------------
//Funcion de agregar producto del almacen de la empresa
list<Empresa> agregarP(list<Empresa> liste){
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
        return liste;
    }

    if(band == false){
        printf("No existe la empresa a buscar\n");
        return liste;
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
    
    e.setListp(e.agregarProducto(e,p));

    liste = modEmpresa(e,liste,nombre);
    
    return liste;
}










//-------------------------------------------------------------------------------------------------------------------------
//Funcion de Eliminar producto del almacen
list<Empresa> quitarP(list<Empresa> liste){
    Empresa e = Empresa();
    bool band = false;

    printf("Ingersar el nopmbre de la empresa\n");
    string nombre = "";
    cin >> nombre;

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
        return liste;
    }

    if(band == false){
        printf("La empresa no existe en la lista\n");
        return liste;
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
            e.setListp(e.quitarProducto(e,codigo));
            band = true;
            break;
        }
        it2++;
    }

    if(band == false){
        printf("No se encontro el producto a eliminar\n");
        return liste;
    }
    
    liste = modEmpresa(e,liste,nombre);

    printf("Producto Servicio a eliminado");
    return liste;
}











//Funcion que rellena el stock
list<Empresa> addstock(list<Empresa> liste){
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
        printf("La empresa no existe\n");
        return liste;
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
    ProductoServicio p;
    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo().compare(codigo) == 0){
            band = true;
            p = *it2;
        }
        it2++;
    }
    
    if(band == false){
        printf("No existe el objeto a rellenar el stock\n");
        return liste;
    }
    
    printf("Ingersar la cantidad del producto\n");
    cin >> cant;
    
    //Cambiando el valor de la cantidad de 
    int suma = p.getCantidad() + cant;
    p.setCantidad(suma);
    it2 = listp.begin();
    while (it2 != listp.end()){ 
        if(it2->getCodigo().compare(codigo) == 0){
            *it2=p;
        }
        it2++;
    }

    e.setListp(listp);

    liste = modEmpresa(e,liste,nombre);
    
    return liste;
}




















//Funcion que rellena el stock
list<Empresa> deletestock(list<Empresa> liste){
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
        return liste;
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
    ProductoServicio p = ProductoServicio();
    // Buscamos el elemento nombre
    while (it2 != listp.end()){ 
        if(it2->getCodigo().compare(codigo) == 0){
            band = true;
            p = *it2;
        }
        it2++;
    }
    
    if(band == false){
        return liste;
    }
    
    printf("Ingersar la cantidad del producto\n");
    cin >> cant;

    int resta = (p.getCantidad() - cant);
    p.setCantidad(resta);

    if(resta <= 0){
        e.setListp(e.quitarProducto(e,codigo));
    }else{
        //Cambiando el valor de la cantidad de 
        it2 = listp.begin();
        while (it2 != listp.end()){ 
            if(it2->getCodigo().compare(codigo) == 0){
                *it2 = p;
            }
            it2++;
        }

        e.setListp(listp);
    }
    
    liste = modEmpresa(e,liste,nombre);
    return liste;
}











//Funcion para afiliar el cliente
list<Cliente> clienteafiliar(list<Cliente> listc, list<Empresa> liste){
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
        return listc;
    }
    
    if(band == false){
        printf("El cliente no existe\n");
        return listc;
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
        return listc;
    }
    
    c.afiliarse(c,e);
    c.setEmpresa(e);

    listc = modCliente(c,listc,num);

    it = listc.begin();
    while (it != listc.end() ){ 
        cout << it->getNombre() << ",  " << it->getEmpresa().getNombre() << endl;
        it++;
    }
    cout << "Fin de la funcion" << endl;
    return listc;
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
    e.setListp(s.verificarStatus(e,p.getNombre(),band));

    return c.comprar(bandera);
}

//MAIN

int main(){
    int resp=9;
    int resp2=9;
    bool band = false;
    list<Cliente> aux;
    list<Empresa> aux2;
    list<Cliente> listClientesGeneral;

    string nombre2 = "noel";
    string num2 = "04125881300";
    string resi2 = "Bolivar";
    Empresa e2 = Empresa();
    listClientesGeneral.push_back(Cliente(nombre2,num2,resi2,e2));

    list<Empresa> listEmpresas;

    string nombre3 = "Pollo";
    string des3 = "Vende pollo";
    string rif2 = "J-1234";
    list<ProductoServicio> listPyS1;
    listEmpresas.push_back(Empresa(nombre3,des3,rif2, listPyS1));

    string nombre4 = "Mascotas";
    string des4 = "Vende mascotas";
    string rif4 = "J-9874";
    list<ProductoServicio> listPyS2;
    listEmpresas.push_back(Empresa(nombre4,des4,rif4, listPyS2));

    string nombre1 = "cesar";
    string num1 = "04165881300";
    string resi1 = "Unare";
    Empresa e1 = Empresa();
    listClientesGeneral.push_back(Cliente(nombre1,num1,resi1,Empresa(nombre4,des4,rif4, listPyS2)));


    list<Transporte> listTransportes;

    nombre4 = "Mario";
    string cedula = "24567890";
    string vehiculo = "Aveo";
    string placa = "j1234";
    int capa = 4;
    listTransportes.push_back(Transporte(nombre4,cedula,vehiculo,placa,capa));

    list<ProductoServicio> listPyS;
    list<Empresa>::iterator it = listEmpresas.begin();
    list<ProductoServicio>:: iterator it2;


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
                            aux2 = addstock(listEmpresas);
                            listEmpresas = aux2;
                            aux = modClienteEmpresa(listClientesGeneral,listEmpresas);
                            listClientesGeneral = aux;
                            break;
                        
                        case 3:
                            aux2 = deletestock(listEmpresas);
                            listEmpresas = aux2;
                            aux = modClienteEmpresa(listClientesGeneral,listEmpresas);
                            listClientesGeneral = aux;
                            break;
                        
                        case 4:
                            aux2 = agregarP(listEmpresas);
                            listEmpresas = aux2;
                            aux = modClienteEmpresa(listClientesGeneral,listEmpresas);
                            listClientesGeneral = aux;
                            break;
                        
                        case 5:
                            aux2 = quitarP(listEmpresas);
                            listEmpresas = aux2;
                            aux = modClienteEmpresa(listClientesGeneral,listEmpresas);
                            listClientesGeneral = aux;
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
                            aux = clienteafiliar(listClientesGeneral, listEmpresas);
                            listClientesGeneral = aux;
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
                            aux2 = llevarpe(listTransportes, listEmpresas);
                            listEmpresas = aux2;
                            aux = modClienteEmpresa(listClientesGeneral,listEmpresas);
                            listClientesGeneral = aux;
                            
                            it = listEmpresas.begin();
                            it2;

                            while (it != listEmpresas.end()){ 
                                cout << "Nombre: " << it->getNombre() << endl;
                                if(it->getNombre().compare("Mascotas") == 0){
                                    listPyS2 = it->getList();
                                    it2 = listPyS2.begin();

                                    while(it2 != listPyS2.end()){
                                        cout << "Nombre: " << it2->getNombre() << " Codigo: " << it2->getCodigo() << " Cantidad: " << it2->getCantidad() << endl;
                                        it2++;
                                    }
                                }
                                it++;
                            }
                            break;
                        
                        case 3:
                            aux2 = llevarpc(listTransportes, listClientesGeneral, listEmpresas);
                            listEmpresas = aux2;
                            aux = modClienteEmpresa(listClientesGeneral,listEmpresas);
                            listClientesGeneral = aux;
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
