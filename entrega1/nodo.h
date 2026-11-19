#pragma once
template <class T>
class Nodo {
    public: 
        T dato;
        Nodo<T> *next;
        Nodo<T> *previous;
        Nodo(T nDato);
};

#include "nodo.tpp"