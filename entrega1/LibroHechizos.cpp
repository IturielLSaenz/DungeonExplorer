#include "LibroHechizos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int LibroHechizos::cargarDesdeArchivo(const std::string& ruta){
    std::ifstream archivo(ruta);
    if(!archivo){
        std::cerr<<"No se encontro: "<<ruta<<std::endl;
        return 0;
    }
    std::string linea;
    std::getline(archivo,linea);

    int cargados = 0;
    while(std::getline(archivo,linea)){
        if(!linea.empty() && linea.back() == '\r'){
            linea.pop_back();
        }
        if(linea.empty()){
            continue;
        }
        std::stringstream ss(linea);
        std::string nombre,tipo,nivel,escuela,costoMP,efecto,dado,numDados,descripcion;
        std::getline(ss,nombre,',');
        std::getline(ss,tipo,',');
        std::getline(ss,nivel,',');
        std::getline(ss,escuela,',');
        std::getline(ss,costoMP,',');
        std::getline(ss,efecto,',');
        std::getline(ss,dado,',');
        std::getline(ss,numDados,',');
        std::getline(ss,descripcion,',');

        listaHechizos.insertarFinal(Hechizo(nombre,tipo,std::stoi(nivel),escuela,std::stoi(costoMP),efecto,std::stoi(dado),std::stoi(numDados),descripcion));
        cargados++;
    }
    return cargados;
}
void LibroHechizos::agregar(const Hechizo& hechizo){
    listaHechizos.insertarFinal(hechizo);
}
void LibroHechizos::eliminar(const std::string& nombre){
    Hechizo temp(nombre,"",0,"",0,"",0,0,"");
    int index = listaHechizos.buscar(temp);
    if(index!=-1){
        listaHechizos.eliminarEn(index);
    }else{
        throw std::invalid_argument("No existe ese hechizo en la lista de hechizos");
    }
}
Hechizo LibroHechizos::buscarPorNombre(const std::string& nombre){
    Hechizo temp(nombre,"",0,"",0,"",0,0,"");
    int index = listaHechizos.buscar(temp);
    if(index!=-1){
        return listaHechizos.obtener(index);
    }else{
        throw std::invalid_argument("No existe ese hechizo en la lista de hechizos");
    }
}
listaDoble<Hechizo> LibroHechizos::filtrarPorNivel(int nivel) const{
    listaDoble<Hechizo> resultado;
    for(int i = 0; i < listaHechizos.tamano(); i++){
        const Hechizo& h = listaHechizos.obtener(i);
        if(h.getNivel() == nivel){
            resultado.insertarFinal(h);
        }
    }
    return resultado;
}
listaDoble<Hechizo> LibroHechizos::filtrarPorEscuela(const std::string& escuela) const{
    listaDoble<Hechizo> resultado;
    for(int i = 0; i < listaHechizos.tamano(); i++){
        const Hechizo& h = listaHechizos.obtener(i);
        if(h.getEscuela() == escuela){
            resultado.insertarFinal(h);
        }
    }
    return resultado;
}
listaDoble<Hechizo> LibroHechizos::filtrarPorCostoMaximo(int mp) const{
    listaDoble<Hechizo> resultado;
    for(int i = 0; i  < listaHechizos.tamano(); i++){
        const Hechizo& h = listaHechizos.obtener(i);
        if(h.getCostoMP() <= mp){
            resultado.insertarFinal(h);
        }
    }
    return resultado;
}
void LibroHechizos::mostrar(){
    listaDoble<Hechizo> resultado = listaHechizos;
    resultado.ordenar();
    resultado.imprimir();
}