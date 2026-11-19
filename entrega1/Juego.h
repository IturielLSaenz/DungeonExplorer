#pragma once
#include "Codice.h"
#include "LibroHechizos.h"
#include "Mapa.h"
#include "Jugador.h"
#include <random> // para poder usar mt19937 gen y semillas

class Juego{
    private:
        Codice codice;
        LibroHechizos libro;
        Mapa mapa;
        std::mt19937 gen; // para semillas y random de toda la partida.

        // metodos privados, accesibles solo en esta clase
        int tirarDado(int caras);
        bool combatir(Jugador& jugador, Cuarto& cuarto);
        bool intentarHechizo(Jugador& jugador, Monstruo& monstruo, bool& seCuro); // seCuro es para saber si se curo el turno anterior
    public:
        Juego(unsigned int semilla);
        void ejecutar();
};