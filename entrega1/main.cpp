#include <iostream>
#include <random>
#include <string>
#include "Juego.h"

int main(int argc, char* argv[]){ // argc argument count y argv argument vector, para no olvidarlo
    unsigned int semilla;
    if(argc > 1){
        try{
            semilla=std::stoul(argv[1]);
        }catch(const std::exception&){
            std::cerr<<"Semilla invalida: "<<argv[1]<<" el sistema generara una aleatoria"<<std::endl;
            std::random_device rd;
            semilla=rd();
        }
    }else{
        // si no hay semilla, que el sistema genere una aleatoria
        std::random_device rd;
        semilla=rd();
    }
    std::cout<<"Semilla (reutilizar si se quiere repetir la partida): "<<semilla<<std::endl;
    Juego juego(semilla);
    juego.ejecutar();
    return 0;
}