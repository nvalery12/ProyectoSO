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