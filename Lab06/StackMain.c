#include "Stack.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>

int main()
{
    // test all Stack functions
    // including assert violations
    // (guarded by #if 0 / #endif)
    Stack *stack = new Stack();
    
    printf("Empty: %s\n", (stack->empty()) ? "true" : "false");
    #if 0
        printf("Top: %d", (stack->top()));
        assert(0);
    #endif

    printf("Case 1: push(5)\n");
    stack->push(5);
    printf("Empty: %s\n", (stack->empty()) ? "true" : "false");
    printf("Top: %d\n", (stack->top()));
    
    printf("Case 2: push(6)\n");
    stack->push(6);
    printf("Empty: %s\n", (stack->empty()) ? "true" : "false");
    printf("Top: %d\n", (stack->top()));
    
    printf("Case 3: push(7)\n");
    stack->push(7);
    printf("Empty: %s\n", (stack->empty()) ? "true" : "false");
    printf("Top: %d\n", (stack->top()));
    
    printf("Case 4: pop()\n");
    stack->pop();
    printf("Empty: %s\n", (stack->empty()) ? "true" : "false");
    printf("Top: %d\n", (stack->top()));
    
    printf("Case 5: push(1)\n");
    stack->push(1);
    printf("Empty: %s\n", (stack->empty()) ? "true" : "false");
    printf("Top: %d\n", (stack->top()));

    free(stack);
    return 0;
}
