#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
listaDoble<T>::listaDoble():cabeza(nullptr),cola(nullptr),tamanio(0){}
template<class T>
listaDoble<T>::listaDoble(const listaDoble<T>& otra):cabeza(nullptr),cola(nullptr),tamanio(0){
    Nodo<T>* actual = otra.cabeza;
    while(actual != nullptr){
        insertarFinal(actual->dato);
        actual = actual->next;
    }
}
template <class T>
listaDoble<T>::~listaDoble(){ // desctructor
    limpiar();
}
// sobrecargar mi operador =
template <class T>
listaDoble<T>& listaDoble<T>::operator=(const listaDoble<T>& otra){
    if(this == &otra) return *this;
    limpiar();
    Nodo<T>* actual = otra.cabeza;
    while(actual != nullptr){
        insertarFinal(actual->dato);
        actual = actual->next;
    }
    return *this;
}
// metodos para insertar
template <class T>
void listaDoble<T>::insertarInicio(const T& valor){
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if(estaVacia()){
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    }else{
        nuevoNodo->next = cabeza;
        cabeza->previous = nuevoNodo;
        cabeza=cabeza->previous;
    }
    tamanio++;
}
template <class T>
void listaDoble<T>::insertarEn(int index, const T& valor){
    if(index<0 || index>tamanio){
        throw invalid_argument("index proporcionado no es valido con el tamano de la lista.");
    }else if(index == 0){
        insertarInicio(valor);
    }else if(index == tamanio){
        insertarFinal(valor);
    }else{
        Nodo<T>* actual = cabeza;
        Nodo<T>* previo = actual->previous;

        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        for(int i=0; i<tamanio; i++){
            if(i == index){
                previo->next = nuevoNodo;
                nuevoNodo->previous = previo;
                actual->previous = nuevoNodo;
                nuevoNodo->next =actual;
            }else{
                actual=actual->next;
                previo=actual->previous;
            }
        }
        tamanio++;
    }
}

template <class T>
void listaDoble<T>::insertarFinal(const T& valor){
    if(estaVacia()){
        insertarInicio(valor);
    }else{
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        cola->next = nuevoNodo;
        nuevoNodo->previous = cola;
        cola = nuevoNodo;
        tamanio++;
    }
}
template <class T>
void listaDoble<T>::eliminarInicio(){
    if(estaVacia()){
        throw logic_error("No se puede limpiar una lista vacia.");
    }else{
        Nodo<T>* nodoSelecto = cabeza;
        if(nodoSelecto->next==nullptr){
            delete nodoSelecto;
            cabeza=nullptr;
            cola=nullptr;
            tamanio--;
        }else{
            cabeza = cabeza->next;
            delete nodoSelecto;
            cabeza->previous=nullptr;
            tamanio--;
        }
    }
}
template <class T>
void listaDoble<T>::eliminarFinal(){
    if(estaVacia()){
        throw logic_error("No se puede limpiar una lista vacia.");
    }else{
        Nodo<T>* nodoSelecto = cola;
        if(nodoSelecto->previous==nullptr){
            delete nodoSelecto;
            cabeza=nullptr;
            cola=nullptr;
            tamanio--;
        }else{
            cola = cola->previous;
            delete nodoSelecto;
            cola->next=nullptr;
            tamanio--;
        }
    }
}
template <class T>
void listaDoble<T>::eliminarEn(int index){
    if(index<0 || index>=tamanio){
        throw invalid_argument("index proporcionado no es valido con el tamano de la lista.");
    }else if(index == 0){
        eliminarInicio();
    }else if(index == tamanio-1){
        eliminarFinal();
    }else{
        Nodo<T>* temp = cabeza;
        for(int i = 0; i<index;i++){
            temp=temp->next;
        }
        Nodo<T>* previo = temp->previous;
        Nodo<T>* sig = temp->next;
        previo->next = sig;
        sig->previous = previo;
        delete temp;
        tamanio--;
    }
}
template <class T>
T& listaDoble<T>::obtener(int index){
    Nodo<T>* actual = cabeza;
    if(estaVacia()){
        throw invalid_argument("No existe ese index en una lista vacia.");
    }else if(index<0 || index >=tamanio){
        throw invalid_argument("Index no valido para esta lista.");
    }else{
        for(int i = 0; i<index; i++){
            actual=actual->next;
        }
        return actual->dato;
    }
}
template <class T>
int listaDoble<T>::buscar(const T& valorDelNodo) const{
    Nodo<T>* actual = cabeza;
    for(int i = 0; i < tamanio; i++){
        if(actual->dato == valorDelNodo){ //sobrecargar operador para monstruos operator=
            return i;
        }else{
            actual=actual->next;
        }
    }
    return -1;
}
template <class T>
int listaDoble<T>::tamano(){
    return tamanio;
}
// checar si esta vacia (esto es fundamental para el resto de funciones):
template <class T>
bool listaDoble<T>::estaVacia() const{
    return cabeza == nullptr;
}
template <class T>
void listaDoble<T>::limpiar(){
    Nodo<T>* actual = cabeza;
    while(actual!=nullptr){
        Nodo<T>* siguiente = actual->next;
        delete actual;
        tamanio--;
        actual=siguiente;
    }
    cabeza = nullptr;
    cola = nullptr;
}
//imprimir
template <class T>
void listaDoble<T>::imprimir(){
    Nodo<T>* actual = cabeza;
    while(actual!=nullptr){
        cout<<actual->dato<<endl;
        actual=actual->next;
    }
}
template <class T>
void listaDoble<T>::imprimirReversa(){
    Nodo<T>* actual = cola;
    while(actual!=nullptr){
        cout<<actual->dato<<endl;
        actual=actual->previous;
    }
}
template <class T>
Nodo<T>* listaDoble<T>::dividir(Nodo<T>* inicio){
    Nodo<T>* lento = inicio;
    Nodo<T>* rapido = inicio;
    while(rapido->next!=nullptr && rapido->next->next!=nullptr){
        lento=lento->next;
        rapido=rapido->next->next;
    }
    Nodo<T>* segundaMitad = lento->next;
    segundaMitad->previous=nullptr;
    lento->next=nullptr;
    return segundaMitad;
}
template <class T>
Nodo<T>* listaDoble<T>::mezclar(Nodo<T>* a, Nodo<T>* b){
    if(a==nullptr){
        return b;
    }else if(b == nullptr){
        return a;
    }
    Nodo<T>* inicio = nullptr;
    Nodo<T>* ultimo = nullptr;
    if(b->dato < a->dato){
        inicio = b;
        b=b->next;
    }else{
        inicio = a;
        a=a->next;
    }
    ultimo = inicio;
    while(a!=nullptr && b!=nullptr){
        if(b->dato < a->dato){
            ultimo->next = b;
            b=b->next;
        }else{
            ultimo->next = a;
            a=a->next;
        }
        ultimo = ultimo->next;
    }
    if(a!=nullptr){
        ultimo->next = a;
    }else{
        ultimo->next = b;
    }
    return inicio;
}
template <class T>
Nodo<T>* listaDoble<T>::mergeSort(Nodo<T>* inicio){
    if(inicio==nullptr || inicio->next==nullptr){
        return inicio; // el caso base.
    }
    Nodo<T>* mitad = dividir(inicio);
    Nodo<T>* ord1 = mergeSort(inicio);
    Nodo<T>* ord2 = mergeSort(mitad);
    return mezclar(ord1,ord2);
}
template <class T>
void listaDoble<T>::ordenar(){
    cabeza = mergeSort(cabeza);
    Nodo<T>* anterior = nullptr;
    Nodo<T>* actual = cabeza;
    while(actual!=nullptr){
        actual->previous = anterior;
        anterior = actual;
        actual = actual->next;
    }
    cola=anterior;
}