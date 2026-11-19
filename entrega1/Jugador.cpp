#include "Jugador.h"
#include <iostream>
#include <stdexcept>

Jugador::Jugador(const std::string& nombre, Raza raza, const LibroHechizos& libro)
    :nombre(nombre),raza(raza),hp(100),mp(100),libro(libro),cuartosConquistados(0){}

std::string Jugador::getNombre() const{
    return this->nombre;
}
Raza Jugador::getRaza() const{
    return this->raza;
}
int Jugador::getHP() const{
    return this->hp;
}
int Jugador::getMP() const{
    return this->mp;
}
const LibroHechizos& Jugador::getLibro() const{
    return this->libro;
}
int Jugador::getCuartosConquistados() const{
    return this->cuartosConquistados;
}
void Jugador::recibirDanio(int danio){
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
void Jugador::curar(int cantidad){
    if(cantidad<0){
        throw std::invalid_argument("No esta permitido ingresar un valor negativo");
    }else{
        hp+=cantidad;
    }
}
bool Jugador::gastarMP(int costo){
    if(mp>=costo){
        mp-=costo;
        return true;
    }
    return false;
}
bool Jugador::estaVivo() const{
    return hp>0;
}
void Jugador::registrarVictoria(const Monstruo& monstruo){
    derrotados.insertarFinal(monstruo);
    cuartosConquistados++;
}
void Jugador::mostrarResumen(const std::string& estado){
    const std::string nombres_raza[] = {"Elf","Human","Dwarf"};
    std::cout<<"Jugador: "<<nombre<<std::endl;
    std::cout<<"Raza: "<<nombres_raza[raza]<<std::endl;
    std::cout<<"Cuartos conquistados: "<<cuartosConquistados<<" de 20"<<std::endl;
    std::cout<<"Estado: "<<estado<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Monstruos derrotados (por nombre):"<<std::endl;
    listaDoble<Monstruo> resumen = derrotados;
    resumen.ordenar();
    for(int i = 0; i < resumen.tamano();i++){
        std::cout<<" "<<i+1<<". "<<resumen.obtener(i).getName()<<std::endl;
    }
}