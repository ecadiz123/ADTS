#include <iostream>

class Nodo{
public:
    int valor;
    Nodo* next = NULL;
    Nodo* back = NULL;
};

class Lista{
    int tamanio = 0;
    Nodo* head = NULL;
    Nodo* tail = NULL;

public:
    int size(){
        return tamanio;
    };
    bool empty(){
        if(head != NULL){
            return false;
        }
        else{
            return true;
        }
    };

    //Agrega elemento en tail
    void push(int numero){
        //Se crea el nodo
        Nodo* n = (Nodo*) malloc(sizeof(Nodo));

        //Se asignan los valores iniciales del nodo
        (*n).valor = numero;
        (*n).next = NULL;
        (*n).back = NULL;

		//Si es una lista sin valores previos
        if(tamanio == 0){
            head = n;
            tail = n;
        }
        //Si la lista tiene elementos
        else{
            (*tail).next = n;
            (*n).back = tail;
            tail = n;
        }
        //Se aumenta el tamaño del nodo
        tamanio = tamanio + 1;
    };

    //Imprime la lista
    void print(){
        Nodo* x = head;
        std::cout <<"[ ";
        while(x != NULL){
            std::cout << (*x).valor <<" ";
            x = (*x).next;
        }
        std::cout <<"]\n";
    };


    bool contains(int el){
        
      Nodo *revisa;
      revisa=head;//puntero parte de la cabeza
        while(revisa!=NULL)//revisar hasta el final
        {
            if ((*revisa).valor==el)//si pilla el elemento, para y devuelve true
            {
                return true;
            }
            revisa=(*revisa).next;

        }
        //si no lo pilló, llega hasta el NULL y devuelve false
       return false;




    }
    void addindex(int el, int indice)//añadir elemento pero en el lugar especifico del indice
    {
        //Hacer el metodo usando dos punteros a nodos auxiliares y colocar entre medio el nuevo nodo
        //Pensar en los casos donde queda en las posiciones extremas




    }
    int get(int indice)
    {
        //pensar en los casos extremos, profe retornador lo hace partir en -1, asi si se hace indice=-99999999 en vez de entrar a recorrer, devuelve el -1
        //Algo mas especifico se puede hacer pero en el curso no es necesario


    }

    void removeelemento(int elementoaborrar){

        //se usa dos punteros a nodo, uno que se va a usar para apuntar a elemento a borrar, el otro para que apunte
        //a nodos que se van a enlazar entre si, primero apunta al (*borrar).back enlaza lo que apunta a a borrar->next
        //y despues lo mismo pero al revez una vez listo hace free a borrar
        








    }

};

int main(){
    Lista l;

    std::cout <<"La lista contiene "<<l.size() <<" elementos (empty: "<< l.empty()<<")\n";

    l.push(10);
    l.push(20);
    l.push(30);
    l.push(40);

    std::cout <<"La lista contiene "<<l.size() <<" elementos (empty: "<< l.empty()<<")\n";
    l.print();
    return 0;
}

