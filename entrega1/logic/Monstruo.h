#pragma once
#include <string>
#include <ostream> 

class Monstruo{
    private:
        std::string name; // nombre de la criatura.
        double cr; // challenge rating.
        std::string type; // tipo de criatura.
        std::string size; // tamano.
        int ac; // armor class.
        int hp; // hit points. 
        std::string align; // alineamiento.       
    public:
        Monstruo();
        Monstruo(const std::string& name,double cr,const std::string& type,const std::string& size,int ac,int hp,const std::string& align);
        // getters
        std::string getName() const;
        double getCr() const;
        std::string getType() const;
        std::string getSize() const;
        int getAc() const;
        int getHp() const;
        std::string getAlign() const;
        // para combate
        void recibirDanio(int);
        bool estaVivo() const; 
        //sobrecargando operadores:
        bool operator<(const Monstruo& otro) const;
        bool operator==(const Monstruo& otro) const;
};
std::ostream& operator<<(std::ostream& os, const Monstruo& m);