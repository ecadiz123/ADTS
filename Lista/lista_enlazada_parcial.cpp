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

    //Agrega elemento en posición index
    void add(int numero, int index){
		//Auxiliares (Si se requiere, es posible no usarlos)
		Nodo* right = head;
		Nodo* left = NULL;
		
		int contador = 1;
		//Se crea el nodo
        Nodo* n = (Nodo*) malloc(sizeof(Nodo));
        
        //Se asignan los valores iniciales del nodo
        (*n).valor = numero;
        (*n).next = NULL;
        (*n).back = NULL;

		//Se recorre la lista hasta el index
		while(right != NULL && contador < index){
			left = right;
			right = (*right).next;
            contador++;
        }

		/* Se conecta el "nodo izquierdo": si la lista
		está vacia, se agrega como primer elemento */
		if (left != NULL){
			(*n).back = left;
			(*left).next = n;
		}
		else{
			head = n;
			tail = n;
		}
		
		//Se conecta el "nodo derecho"
		if(right != NULL){
			(*n).next = right;
			(*right).back = n;
		}
		
        tamanio = tamanio + 1;
	};

	//Busca la primera ocurrencia de un elemento
	bool contains(int numero){
		Nodo* x = head;
       
        while(x != NULL){
			if((*x).valor == numero){
				return true;
			}
            x = (*x).next;
        }

        return false;
	}

	//Entrega el valor del elemento en la posicion index
	int get(int index){
		Nodo* x = head;
		int contador = 1;
		int retornador = -1;
		
        while(x != NULL && contador <= index){
			retornador = (*x).valor;
            x = (*x).next;
            contador ++;
        }

		/* Si la lista está vacia se retorna -1, si la lista tiene
		menos elementos que index, se retorna el último */
        return retornador;
	}

	//Elimina la primera ocurrencia de un número
	void remove(int numero){
		Nodo* x = head;
		Nodo* auxiliar;
		
		while(x != NULL){
			if((*x).valor == numero){

				//Se enlaza el "nodo izquierdo"
				auxiliar = (*x).back;
				(*auxiliar).next = (*x).next;

				//Se enlaza el "nodo derecho"
				if( (*x).next !=NULL){
					auxiliar = (*x).next;
					(*auxiliar).back = (*x).back;
				}

				free(x);
				tamanio = tamanio - 1;
				//Se rompe el ciclo
				break;
			}
            x = (*x).next;
        }

	}
};



int main(){
    Lista l;

    std::cout <<"La lista contiene "<<l.size() <<" elementos (empty: "<< l.empty()<<")\n";
    std::cout <<"Se remueve el numero 30\n";
    l.remove(30);
    l.print();
    
    std::cout <<"Se agregan 5 numeros \n";
	l.add(5,2);
    l.push(10);
    l.push(20);
    l.push(30);
    l.push(40);
    l.print();

    std::cout <<"Se agregan 2 numeros en posicion 3 y 28\n";
	l.add(25, 3);
	l.add(100, 28);
	l.print();

	std::cout <<"Se remueve el 20 \n";
	l.remove(20);
	l.print();

	std::cout <<"Se remueve el 100 \n";
	l.remove(100);
	l.print();
	
    std::cout <<"La lista contiene "<<l.size() <<" elementos (empty: "<< l.empty()<<")\n";

    return 0;
}


