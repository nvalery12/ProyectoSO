#include <iostream>
#include "Solicitud.h"

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
    //t.setCedula(cip);
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
            lista = it->getListp();
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

int main() {
    list<Cliente> listC;
    list<Empresa> listE;
    list<ProductoServicio> listP;
    list<Transporte> listT;
    Cliente c = Cliente();
    Cliente c1 = Cliente("Cesar","04165881300","Yara Yara");
    ProductoServicio p1 = ProductoServicio("Termo","Envase para bebidas",2000,"02134",4);
    ProductoServicio p2 = ProductoServicio("telefono","Telefono Iphone",9999,"32104",21);
    //Empresa e1 = Empresa("Pollera Cesar","Se vende pollo","J-123456789");
    Transporte t1 = Transporte(4,"Noel","20000000","aveo","2acbd");

    //Cliente
    registrarCliente(c);

    c1.comprar();


    //Transporte

    return 0;
}
