#include "Mapa.h"
void Mapa::generar(Codice& codice, std::mt19937& gen, int numCuartos){
    cuartos.limpiar();
    for(int i = 1; i <= numCuartos; i++){
        Cuarto cuarto(i,codice.monstruoAleatorio(gen));
        cuartos.insertarFinal(cuarto);
    }
}
Cuarto& Mapa::obtenerCuarto(int numero){
    return cuartos.obtener(numero-1);
}
const Cuarto& Mapa::obtenerCuarto(int numero) const{
    return cuartos.obtener(numero-1);
}
int Mapa::getNumCuartos() const{
    return cuartos.tamano();
}
void Mapa::mostrarMapa(){
    cuartos.imprimir();
}