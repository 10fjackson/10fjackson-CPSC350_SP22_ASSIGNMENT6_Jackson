#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
template <typename T>
class GenStack{
  public:
    GenStack(); // default
    ~GenStack(); //destructor

    //core functions
    void push(T data);
    T pop();
    void removeBack();
    T peek(); //aka top()

    //aux functions
    bool isEmpty();
    bool isFull();
    int getSize();

  private:
    DoublyLinkedList<T> *myArray;
    ListNode<T> *top;
    //int size();

};

template <typename T>
GenStack<T>::GenStack(){
  top = NULL;
  myArray = new DoublyLinkedList<T>();
} // default

//No overloaded constructor needed, no max size

template <typename T>
GenStack<T>::~GenStack(){
  delete[] myArray;

} //destructor


//core functions
template <typename T>
void GenStack<T>::push(T data){
  //check if stack is is full
  myArray->insertFront(data);
  top = myArray->getFront();
}

template <typename T>
T GenStack<T>::pop(){
  //make sure stack is not empty before proceeding
  T pastFront = myArray->getFront()->data;
  myArray->removeFront();
  top = myArray->getFront();
  return pastFront;
}

template <typename T>
void GenStack<T>::removeBack(){
    myArray->removeBack();
}

template <typename T>
T GenStack<T>::peek(){
  //doubly linked list makes sure stack is not empty before proceeding
    return myArray->getFront()->data;
} //aka top()

//aux functions
template <typename T>
bool GenStack<T>::isEmpty(){
  return (top == NULL);
}

//No isFull function needed

template <typename T>
int GenStack<T>::getSize(){
  return myArray->getSize();
}

#endif
