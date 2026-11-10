#pragma once
#include <stdexcept>
#include "nodo.h"
template <class T>
class listaDoble {
    private:
        Nodo<T> *cabeza;
        Nodo<T> *cola;
        int tamanio;

        // funciones auxiliares para mergeSort
        Nodo<T>* dividir(Nodo<T>*);
        Nodo<T>* mezclar(Nodo<T>* a,Nodo<T>* b);
        Nodo<T>* mergeSort(Nodo<T>*);
    public:
        listaDoble(); // constructor
        listaDoble(const listaDoble<T>& otra); // constructor para copias       
        ~listaDoble(); // desctructor
        listaDoble<T>& operator=(const listaDoble<T>& otra); //sobrecarga del operador
        void insertarInicio(const T&);
        void insertarFinal(const T&);
        void insertarEn(int, const T&);
        void eliminarInicio();
        void eliminarFinal();
        void eliminarEn(int);
        T& obtener(int);
        int buscar(const T&) const;
        int tamano();
        bool estaVacia() const;
        void limpiar();
        void imprimir();
        void imprimirReversa();
        void ordenar(); // merge sort!
};

#include "listaDoble.tpp"