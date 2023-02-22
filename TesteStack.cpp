#include <iostream>
#include <stack>
#include "Stackteste1.h"

struct Stack
{
    char arr[4096];
    int top;
};
Stack Create(4096){
    Stack stack={{}.0};
    return stack;
}
