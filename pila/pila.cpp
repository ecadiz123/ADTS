#include "pila.hpp"
#include <cstdlib>
//archivo implementacion piladinamica.cpp
 
 
 class nodo
 {  
    public:

    int dato;
    nodo *siguiente=NULL;/*puntero que debe de apuntar al siguiente elemento, hay que inicializarlo en NULL, tambien se puede hacer con constructor*/

 };
class pila: ListStack{
    private:   
    int size=0;
    nodo *tope=NULL; //un puntero que apunta a una estructura nodo
    
    public:
    void pila::push(int elemento){
        
        //n es puntero auxiliar que apunta a memoria a usar
        nodo *n=(nodo*)malloc(sizeof(nodo));//n se usa para tener algo que apunte a la memoria con la que se va a trabajar
       
        (*n).dato=elemento;
        if(!empty)
        (*n).siguiente=tope;//cambia puntero al elemento anterior
        size++;


    }
    int pop(){
        //auxiliares
        nodo *n;
        int retorna;

        //Guardar direccion del valor a eliminar
        n=tope;
        //cambiar puntero de tope a el puntero del valor a eliminar
        tope=(*tope).siguiente;//tope ahora es el nodo que esta apuntando, la variable siguiente
        //liberar memoria que no se va a usar.
        free(n);
        retorna=(*n).dato;
        //bajar tamaño
        size--;
        return retorna;


    }

};