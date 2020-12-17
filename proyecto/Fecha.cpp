class Fecha
{
private:
    int dia;
    int mes;
    int ano;
public:
    Fecha(int dia,int mes,int ano);
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    int getDia();
    int getMes();
    int getAno();
};

Fecha::Fecha(int dia,int mes,int ano)
{
    this->dia=dia;
    this->mes=mes;
    this->ano=ano;
}

void Fecha::setDia(int dia){
    this->dia=dia;
}
void Fecha::setMes(int mes){
    this->mes=mes;
}
void Fecha::setAno(int ano){
    this->ano=ano;
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