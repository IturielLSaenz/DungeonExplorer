#include "Juego.h"
#include <iostream>
#include <string>
#include "listaDoble.h"
#include "Hechizo.h"

Juego::Juego(unsigned int semilla):gen(semilla){}
int Juego::tirarDado(int caras){
    std::uniform_int_distribution<int> dist(1,caras);
    return dist(gen);
}
bool Juego::intentarHechizo(Jugador& jugador, Monstruo& monstruo, bool& seCuro){
    bool puedeCurarse = !seCuro;
    seCuro = false;
    
    listaDoble<Hechizo> disponibles = jugador.getLibro().filtrarPorCostoMaximo(jugador.getMP());
    if(disponibles.estaVacia()){
        return false;
    }
    // el jugador se cura si baja de 30 de hp
    if(jugador.getHP()<30 && puedeCurarse){
        for(int i = 0; i < disponibles.tamano(); i++){
            const Hechizo& h = disponibles.obtener(i);
            if(h.getEfecto()=="Curacion"){
                jugador.gastarMP(h.getCostoMP());
                int cura = h.tirarEfecto(gen);
                jugador.curar(cura);
                seCuro = true;
                std::cout<<jugador.getNombre()<<" uso "<<h.getNombre()
                <<" +"<<cura<<" HP. HP del jugador: "<<jugador.getNombre()<<": "<<jugador.getHP()
                <<" | Monstruo: "<<monstruo.getName()<<" HP del monstruo: "<<monstruo.getHp()<<std::endl;
                return true;
            }
        }
    }
    int mejor = -1;
    int mejorPromedio = 0;
    for(int i = 0; i < disponibles.tamano();i++){
        const Hechizo& h = disponibles.obtener(i);
        if(h.getEfecto()=="Danio"){
            int promedio = h.getNumDados() * (h.getDado() + 1);
            if(promedio > mejorPromedio){
                mejorPromedio = promedio;
                mejor = i;
            }
        }
    }
    if(mejor == -1){
        return false;
    }
    const Hechizo& h = disponibles.obtener(mejor);
    jugador.gastarMP(h.getCostoMP());
    int danio = h.tirarEfecto(gen);
    monstruo.recibirDanio(danio);
    std::cout<<jugador.getNombre()<<" uso "<<h.getNombre()
    <<" "<<danio<<" HP. HP del jugador: "<<jugador.getNombre()<<": "<<jugador.getHP()
    <<" | Monstruo: "<<monstruo.getName()<<" HP del monstruo: "<<monstruo.getHp()<<std::endl;
    return true;
}
bool Juego::combatir(Jugador& jugador, Cuarto& cuarto){
    Monstruo& monstruo = cuarto.getMonstruo();
    std::cout<<"\n===Cuarto "<<cuarto.getNumero()<<": aparece "<<monstruo.getName()<<" [HP: "<<monstruo.getHp()<<"] ==="<<std::endl;
    
    bool seCuro = false;

    while(jugador.estaVivo() && monstruo.estaVivo()){
        int golpe = tirarDado(10);
        jugador.recibirDanio(golpe);
        // bitacora de partida
        std::cout<<monstruo.getName()<<" ataca con: 1d10 = "<<golpe<<" | HP "<<
        jugador.getNombre()<<": "<<jugador.getHP()<<" | HP "<<monstruo.getName()<<": "<<
        monstruo.getHp()<<std::endl;
        // turno del jugador
        if(jugador.estaVivo()){
            if(!intentarHechizo(jugador,monstruo,seCuro)){
                int ataque = tirarDado(10);
                monstruo.recibirDanio(ataque);
                // bitacora de partida, jugador como atacante
                std::cout<<jugador.getNombre()<<" ataca con: 1d10 = "<<ataque<<" | HP "<<
                monstruo.getName()<<": "<<monstruo.getHp()<<" | HP "<<jugador.getNombre()<<": "<<
                jugador.getHP()<<std::endl;
            }
        }
    }
    if(jugador.estaVivo()){
        jugador.registrarVictoria(monstruo);
        cuarto.conquistar();
        int curacion = (tirarDado(20) + tirarDado(20));
        jugador.curar(curacion);
        std::cout<<jugador.getNombre()<<" ha derrotado a: "<<monstruo.getName()
        <<" y recupera 2d20 en puntos de vida: "<<curacion<<" HP | HP: "<<jugador.getHP()<<std::endl;
        return true;
    }
    std::cout<<"El jugador: "<<jugador.getNombre()<<" ha muerto. GG."<<std::endl;
    return false;
}
void Juego::ejecutar(){
    int numMonstruos =  codice.cargarDesdeArchivo("data/monsters.csv");
    int numHechizos = libro.cargarDesdeArchivo("data/spells.csv");
    if(numMonstruos == 0 || numHechizos == 0){
        std::cerr<<"No se encontraron/pudieron cargar los datos. Revisa que esten los csv en /data/"<<std::endl;
        return;
    }
    // llenando datos del jugador
    // nombre
    std::string nombre;
    std::cout<<"Ingresa tu nombre de jugador: ";
    std::getline(std::cin,nombre);
    // raza
    int opcion = 0;
    std::cout<<"Raza (1 = Elf, 2 = Human, 3 = Dwarf): ";
    // validacion de raza!
    while(!(std::cin>>opcion) || opcion < 1 || opcion > 3){
        std::cin.clear();
        std::cin.ignore(10000000000000000,'\n'); // ignora los datos invalidos para permitir volver a escribirlos, investigado en internet
        std::cout<<"Seleccion invalida, ingresa 1, 2 o 3: ";
    }
    Raza raza = static_cast<Raza>(opcion-1); // static_cast convierte el numero en enum, facilita el uso
    Jugador jugador(nombre,raza,libro);
    mapa.generar(codice,gen);
    std::string estado = "Victorioso: ha conquistado todos los cuartos";
    for(int i = 1; i <= mapa.getNumCuartos();i++){
        Cuarto& cuarto = mapa.obtenerCuarto(i);
        Monstruo& monstruo = cuarto.getMonstruo();
        if(monstruo.estaVivo() && combatir(jugador,cuarto)==false){
            estado="Derrotado en el cuarto "+std::to_string(i)+" ("+cuarto.getMonstruo().getName()+")";
            break;
        }
    }
    //RESUMEN
    std::cout<<"===== FIN DEL JUEGO ====="<<std::endl;
    jugador.mostrarResumen(estado);
}