#pragma once
#include "listaDoble.h"
#include "Cuarto.h"
#include "Codice.h"

class Mapa{
    private:
        listaDoble<Cuarto> cuartos;
    public:
        void generar(Codice& codice, std::mt19937& gen, int numCuartos = 20); // agrego el generador random aqui para que la semilla controle toda la partida.
        Cuarto& obtenerCuarto(int); // combate y modificacion
        const Cuarto& obtenerCuarto(int) const; // lectura
        int getNumCuartos()const;
        void mostrarMapa();
};