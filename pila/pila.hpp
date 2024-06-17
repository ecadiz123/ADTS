//archivo implementacion piladinamica.hpp

#include "StackADT.hpp"

class nodo;

class ListStack : public StackADT{
 private:
  nodo *_top;
  int tamaño;
 public:
  ListStack();
  ~ListStack();
  bool empty();
  int size();
  element_t top();
  void push(element_t);
  int pop();//generalmente el pop al tratar en memoria dinamica usa un retorno del tipo del elemento en este caso int
};

