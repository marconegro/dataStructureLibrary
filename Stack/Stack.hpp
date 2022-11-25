//
//  Stack.hpp
//  Stack
//
//  Created by Marco Negro on 25/11/22.
//

#ifndef Stack_
#define Stack_

struct stack;
struct elem;

stack* initializeStack();
elem* initializeElem(stack* stack, void* content);

void push(stack* stack, void* elem);
void* pop(stack* stack);

int countElements(stack* stack);

#endif
