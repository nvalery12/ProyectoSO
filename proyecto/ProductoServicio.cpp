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