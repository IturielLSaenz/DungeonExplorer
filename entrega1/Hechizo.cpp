#include "Hechizo.h"
#include <string>

Hechizo::Hechizo()
    :nombre("Desconocido"),tipo("Desconocido"),nivel(0),escuela("Desconocido"),costoMP(0),efecto("Desconocido"),dado(0),numDados(0),descripcion("Desconocido"){}
Hechizo::Hechizo(const std::string& nombre,const std::string& tipo, int nivel,const std::string& escuela,int costoMP,const std::string& efecto, int dado, int numDados,const std::string& descripcion)
    :nombre(nombre),tipo(tipo),nivel(nivel),escuela(escuela),costoMP(costoMP),efecto(efecto),dado(dado),numDados(numDados),descripcion(descripcion){}
std::string Hechizo::getNombre() const{
    return this->nombre;
}
std::string Hechizo::getTipo() const{
    return this->tipo;
}
int Hechizo::getNivel() const{
    return this->nivel;
}
std::string Hechizo::getEscuela()const{
    return this->escuela;
}
int Hechizo::getCostoMP() const{
    return this->costoMP;
}
std::string Hechizo::getEfecto() const{
    return this->efecto;
}
int Hechizo::getDado() const{
    return this->dado;
}
int Hechizo::getNumDados() const{
    return this->numDados;
}
std::string Hechizo::getDescripcion() const{
    return this->descripcion;
}
int Hechizo::tirarEfecto(std::mt19937& gen) const{
    std::uniform_int_distribution<int> dist(1, dado);
    int total = 0;
    for(int i = 0; i < numDados; i++){
        total += dist(gen);
    }
    return total;
}
bool Hechizo::operator<(const Hechizo& otro) const{
    return this->nombre < otro.nombre;
}
bool Hechizo::operator==(const Hechizo& otro) const{
    return this->nombre == otro.nombre;
}
std::ostream& operator<<(std::ostream& os, const Hechizo& h){
    os<<h.getNombre()<<" TIPO: "<<h.getTipo()<<" NIVEL: "<<h.getNivel()<<" ESCUELA: "<<h.getEscuela()<<" COSTO MP: "<<h.getCostoMP()<<" EFECTO: "<<h.getEfecto()<<" DADO: "<<h.getDado()<<" NUM DADOS: "<<h.getNumDados()<<" DESCRIPCION: "<<h.getDescripcion();
    return os;
}