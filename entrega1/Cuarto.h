#pragma once
#include "Monstruo.h"
#include <ostream>

class Cuarto{
    private:
        int numero;
        Monstruo monstruo;
        bool conquistado;
    public:
        Cuarto();
        Cuarto(int numero, const Monstruo& monstruo);
        // getters
        int getNumero() const;
        bool estaConquistado() const;
        void conquistar();
        Monstruo& getMonstruo(); // combate
        const Monstruo& getMonstruo() const; // lectura
};
std::ostream& operator<<(std::ostream& os, const Cuarto& c);