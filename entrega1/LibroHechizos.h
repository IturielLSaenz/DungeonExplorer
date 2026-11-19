#pragma once
#include "listaDoble.h"
#include "Hechizo.h"
#include <string>

class LibroHechizos{
    private:
        listaDoble<Hechizo> listaHechizos;
    public:
        int cargarDesdeArchivo(const std::string& ruta);
        void agregar(const Hechizo&);
        void eliminar(const std::string& nombre);
        Hechizo buscarPorNombre(const std::string& nombre);
        listaDoble<Hechizo> filtrarPorNivel(int nivel) const;
        listaDoble<Hechizo> filtrarPorEscuela(const std::string& escuela) const;
        listaDoble<Hechizo> filtrarPorCostoMaximo(int mp) const;
        void mostrar();
};