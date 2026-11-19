#include "Cuarto.h"

Cuarto::Cuarto()
    :numero(0),monstruo("Desconocido",0.0,"Desconocido","Desconocido",0,0,"Desconocido"),conquistado(false){}
Cuarto::Cuarto(int numero, const Monstruo& monstruo)
    :numero(numero),monstruo(monstruo),conquistado(false){}

int Cuarto::getNumero() const{
    return this->numero;
}
bool Cuarto::estaConquistado() const{
    return this->conquistado;
}
void Cuarto::conquistar(){
    conquistado = true;
}
Monstruo& Cuarto::getMonstruo(){
    return monstruo;
}
const Monstruo& Cuarto::getMonstruo() const{
    return monstruo;
}
std::ostream& operator<<(std::ostream& os, const Cuarto& c){
    os<<"Cuarto "<<c.getNumero()<<" Monstruo: "<<c.getMonstruo().getName()<<" HP: "<<c.getMonstruo().getHp()<<" Conquistado: "<<(c.estaConquistado() ? "[CONQUISTADO]":"[PENDIENTE]"); // operador ternario para ahorrarme un if
    return os;
}
