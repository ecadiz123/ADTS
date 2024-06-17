#include "lista.hpp"
typedef int elemento;
struct nodo
{
    int elemento=0;
    nodo *anterior=NULL, *siguiente=NULL;

};
class lista : lista1
{
private:
    int size;
    nodo *frente, *atras;

public:
    // Constructor
    lista()
    {

        size= 0;
        frente = NULL;
        atras = NULL;
    }
    int getsize()
    {
        return size;
    }
    bool vacio()
    {

        if (size == 0)
            return true;
        else
            return false;
    }

    void anadeatras(elemento el)
    {

        nodo *nuevo;
        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->elemento = el;

        // En el caso de que la lista no tenga elementos
        if (size == 0)
        {
            frente = nuevo;
            atras = nuevo;
            // Ambos apuntan a nuevo nodo
        }
        else
        {
            nuevo->anterior = atras;
            atras->siguiente = nuevo;
            atras = nuevo;
        }
        size++;
    }

    void anadeadelante(elemento el)
    {

        nodo *nuevo;
        nuevo = (nodo *)malloc(sizeof(nodo));
        nuevo->elemento = el;

        // En el caso de que la lista no tenga elementos
        if (size == 0)
        {
            frente = nuevo;
            atras = nuevo;
            // Ambos apuntan a nuevo nodo
        }
        else
        {
            nuevo->siguiente = frente; // nuevo siguiente apunta a frente
            frente->anterior = nuevo;  // frente anterior apunta a nuevo
            frente = nuevo;            // nuevo es frente
            size++;
        }
    }
    elemento print(){

        nodo *impresora=frente;
        while (impresora!=NULL)
        {
            std::cout <<impresora->elemento<<std::endl;
            impresora=impresora->siguiente;
               
        }
        




    }
};