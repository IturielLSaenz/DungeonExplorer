#include "Monstruo.h"
#include <stdexcept>

// constructor vacio
Monstruo::Monstruo()
    :name("Desconocido"),cr(0.0),type("Desconocido"),size("Desconocido"),ac(0),hp(0),align("Desconocido"){}
// constructor con argumentos
Monstruo::Monstruo(const std::string& name, double cr, const std::string& type, const std::string& size, int ac, int hp, const std::string& align)
    :name(name),cr(cr),type(type),size(size),ac(ac),hp(hp),align(align){}
// getters
std::string Monstruo::getName() const{
    return this->name;
}
double Monstruo::getCr() const{
    return this->cr;
}
std::string Monstruo::getType() const{
    return this->type;
}
std::string Monstruo::getSize() const{
    return this->size;
}
int Monstruo::getAc() const{
    return this->ac;
}
int Monstruo::getHp() const{
    return this->hp;
}
std::string Monstruo::getAlign() const{
    return this->align;
}
// funciones relacionadas al combate
void Monstruo::recibirDanio(int danio){
    /*
    Documentacion del metodo:
    - Danio no puede ser negativo
    - si hp - danio da igual o menor a cero, settear hp a 0 para evitar
    hp negativa.
    - si no se cumple cualquiera, hp = hp - danio.
    */
    if(danio<0){
        throw std::invalid_argument("No se puede ingresar un valor de danno negativo.");
    }else if((hp-danio)<=0){
        hp = 0;
    }else{
        hp-=danio;
    }
}
bool Monstruo::estaVivo() const{
    return hp>0;
}
// sobrecarga de operadores
bool Monstruo::operator<(const Monstruo& otro) const{
    return this->name < otro.name;
}
bool Monstruo::operator==(const Monstruo& otro) const{
    return this->name == otro.name;
}
std::ostream& operator<<(std::ostream& os, const Monstruo& m){
    os<<m.getName()<<" CR: "<<m.getCr()<<" TYPE: "<<m.getType()<<" SIZE: "<<m.getSize()<<" AC: "<<m.getAc()<<" HP: "<<m.getHp()<<" ALIGN: "<<m.getAlign();
    return os;
}