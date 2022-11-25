//
//  Stack.cpp
//  Stack
//
//  Created by Marco Negro on 25/11/22.
//

#include <iostream>
#include "Stack.hpp"

struct stack{
  elem* lastElem = 0x0;
};

struct elem{
  int index = -1;
  void* content = 0x0;
  elem* downerElem = 0x0;
};

stack* initializeStack(){
  return new stack;
}

elem* initializeElem(stack* stack, void* content){
  elem* element = new elem;
  element->index = countElements(stack);
  element->content = content;
  element->downerElem = stack->lastElem;
  return element;
}

void push(stack* stack, void* elem){
  stack->lastElem = initializeElem(stack, elem);
}

void* pop(stack* stack){
  if(stack->lastElem == 0x0) return 0;
  else {
    //pop elem
    elem* upper = stack-> lastElem;
    stack -> lastElem = upper->downerElem;
    return upper->content;
  }
}

int countElements(stack* stack){
  if(stack->lastElem == 0x0) return 0;
  else return ((stack->lastElem)->index) + 1;
}
