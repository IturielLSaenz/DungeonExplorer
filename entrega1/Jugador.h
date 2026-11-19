#pragma once
#include "listaDoble.h"
#include "Monstruo.h"
#include "LibroHechizos.h"
#include <string>

enum Raza { ELF, HUMAN, DWARF};

class Jugador{
    private:
        std::string nombre;
        Raza raza;
        int hp;
        int mp;
        LibroHechizos libro;
        listaDoble<Monstruo> derrotados;
        int cuartosConquistados;
    public:
        Jugador(const std::string& nombre, Raza raza, const LibroHechizos& libro);
        void recibirDanio(int);
        void curar(int);
        bool gastarMP(int);
        bool estaVivo() const;
        void registrarVictoria(const Monstruo&);
        void mostrarResumen(const std::string& estado);
        // getters
        std::string getNombre() const;
        Raza getRaza() const;
        int getHP() const;
        int getMP() const;
        const LibroHechizos& getLibro() const;
        int getCuartosConquistados() const;        
};