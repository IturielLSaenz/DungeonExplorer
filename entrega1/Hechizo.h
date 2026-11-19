#pragma once
#include <string>
#include <ostream>
#include <random>
class Hechizo{
    private:
        std::string nombre; // nombre del hechizo/habilidad
        std::string tipo; // hechizo/habilidad
        int nivel; // 0 (cantrip) a 9
        std::string escuela; // Evocation, Abjuration, etc.
        int costoMP; // MP que gasta al usarse (0 para habilidades)
        std::string efecto; // danio o curacion
        int dado; // caras del dado que se tira (por ejemplo 6 para un d6)
        int numDados; // cuantos dados se tiran (por ejemplo 2 para 2d6)
        std::string descripcion; // una linea que explique el hechizo
    public:
        Hechizo();
        Hechizo(const std::string& nombre, const std::string& tipo, int nivel, const std::string& escuela,int costoMP,const std::string& efecto, int dado, int numDados, const std::string& descripcion);
        //getters
        std::string getNombre() const;
        std::string getTipo() const;
        int getNivel() const;
        std::string getEscuela() const;
        int getCostoMP() const;
        std::string getEfecto() const;
        int getDado() const;
        int getNumDados() const;
        std::string getDescripcion() const;
        //metodos
        int tirarEfecto(std::mt19937& gen) const;
        bool operator<(const Hechizo& otro) const;
        bool operator==(const Hechizo& otro) const;
};
std::ostream& operator<<(std::ostream& os, const Hechizo& h);