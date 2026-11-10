#include <iostream>
#include "listaDoble.h"
#include "Monstruo.h"

// main temporal para las sesiones de debugging
int main(){
    Monstruo goblin("Goblin",2.50,"Goblin","Pequeno",0,50,"Frontal");
    Monstruo gigante("Gigante",10,"","Colosal",10,300,"Trasera");
    Monstruo stalfo("Stalfo",6,"No-muerto","Grande",3,100,"Medio");
    Monstruo orco("Orco",5,"Orco","Grande",5,80,"Frontal");
    Monstruo bandido("Bandido",6,"Humano","Grande",3,70,"Medio");

    listaDoble<Monstruo> listaMonstruos;
    listaMonstruos.insertarInicio(goblin);
    listaMonstruos.insertarFinal(gigante);
    listaMonstruos.insertarFinal(stalfo);
    listaMonstruos.insertarFinal(orco);
    listaMonstruos.insertarFinal(bandido);
    listaMonstruos.imprimir();
    listaMonstruos.obtener(0).recibirDanio(10);
    cout<<"Vida duende: "<<goblin.getHp()<<endl;
    cout<<goblin.estaVivo()<<endl;
    cout<<"Ordenado: "<<endl;  
    listaMonstruos.ordenar();
    listaMonstruos.imprimir();
    return 0;
}
