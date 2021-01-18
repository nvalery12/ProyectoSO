class AlmacenPropio
{
private:
    ProductoServicio producto;
    int num_producto;
public:
    AlmacenPropio(ProductoServicio p,int num);
    AlmacenPropio();
    void setProducto(ProductoServicio p);
    void setNum_producto(int num);
    ProductoServicio getProducto();
    int getNum_producto();
    void añadirProducto(ProductoServicio p, int num);
    void quitarProducto(ProductoServicio p, int num);
};

AlmacenPropio::AlmacenPropio(ProductoServicio p,int num) ////Constructron sin parametros
{
    producto=p;
    num_producto=num;
}

AlmacenPropio::AlmacenPropio() //Constructron con parametros
{
    producto=ProductoServicio();
    num_producto=0;
}

void AlmacenPropio::setProducto(ProductoServicio p){
    producto=p;
}
void AlmacenPropio::setNum_producto(int num){
    num_producto=num;
}

ProductoServicio AlmacenPropio::getProducto(){
    return producto;
}
int AlmacenPropio::getNum_producto(){
    return num_producto;
}

//Procesos

void AlmacenPropio::añadirProducto(ProductoServicio p, int num){
    printf("producto añadido con exito\n");
}

void AlmacenPropio::quitarProducto(ProductoServicio p, int num){
    printf("producto quitado con exito\n");
}