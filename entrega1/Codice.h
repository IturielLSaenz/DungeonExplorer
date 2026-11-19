#pragma once
#include <string>
#include "listaDoble.h"
#include "Monstruo.h"
#include <random>

class Codice{
    private:
        listaDoble<Monstruo> monstruos;
    public:
        int cargarDesdeArchivo(const std::string& ruta);
        Monstruo monstruoAleatorio(std::mt19937& gen);
        Monstruo buscarPorNombre(const std::string& nombre) const;
        void mostrarTodos();
};