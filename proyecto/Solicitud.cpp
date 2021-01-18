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