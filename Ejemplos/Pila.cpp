#ifndef PILA_CPP
#define PILA_CPP

template<class T>
class Pila{
    private:
        NodoLista<T>* tope;
    public:
        Pila(){
            tope = NULL;
        }
        void push(T el){
            tope = new NodoLista<T>(el, tope);
        }
        T pop(){
            assert(!esVacia());
            T toReturn = tope->el;
            tope = tope->sig;
            return toReturn;
        }
        bool esVacia(){
            return tope == NULL; 
        }
}

#endif