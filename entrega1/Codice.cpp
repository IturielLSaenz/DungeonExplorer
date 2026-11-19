#include "Codice.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

// funciones auxiliares
// para CR (porque puede ser una fraccion)
static double convertirCR(const std::string& texto){
    size_t diagonal = texto.find('/');
    if(diagonal == std::string::npos){
        return std::stod(texto);
    }
    double numerador = std::stod(texto.substr(0, diagonal));
    double denominador = std::stod(texto.substr(diagonal + 1));
    return numerador / denominador;
}

int Codice::cargarDesdeArchivo(const std::string& ruta){
    std::ifstream archivo(ruta);
    if(!archivo){
        std::cerr<<"No se encontro: "<<ruta<<std::endl;
        return 0;
    }
    std::string linea;
    std::getline(archivo, linea);
    int cargados = 0;
    while(std::getline(archivo,linea)){
        if(!linea.empty() && linea.back() == '\r'){
            linea.pop_back();
        }
        if(linea.empty()){
            continue;
        }
        std::stringstream ss(linea);
        std::string nombre, cr, tipo, tamano, ac, hp, algin;
        std::getline(ss, nombre, ',');
        std::getline(ss, cr, ',');
        std::getline(ss, tipo, ',');
        std::getline(ss, tamano, ',');
        std::getline(ss, ac, ',');
        std::getline(ss, hp, ',');
        std::getline(ss, algin, ',');

        monstruos.insertarFinal(Monstruo(nombre, convertirCR(cr), tipo,tamano,std::stoi(ac),std::stoi(hp),algin));
        cargados++;
    }
    return cargados;
}
Monstruo Codice::monstruoAleatorio(std::mt19937& gen){
    if(monstruos.estaVacia()){
        throw std::logic_error("El codice esta vacio.");
    }
    std::uniform_int_distribution<int> dis(0, monstruos.tamano() - 1);
    int indice = dis(gen);
    return monstruos.obtener(indice);
}
Monstruo Codice::buscarPorNombre(const std::string& nombre) const{
    Monstruo buscado(nombre,0.0,"","",0,0,"");
    int indice = monstruos.buscar(buscado);
    if(indice == -1){
        throw std::invalid_argument("No existe el monstruo: "+nombre);
    }
    return monstruos.obtener(indice);
}
void Codice::mostrarTodos(){
    std::cout<<"Codice completo: "<<monstruos.tamano()<<std::endl;
    monstruos.imprimir();
}