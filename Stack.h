#ifndef __STACK_H__
#define __STACK_H__

const int STACK_CAPACITY = 4096;

struct Stack
{
	int Top;
	char values[STACK_CAPACITY];
};

Stack Create();
bool Push(Stack& stack, char value);
char Pop(Stack& stack);
char Top(const Stack& stack);
int Size(const Stack& stack);
int Count(const Stack& stack);
bool IsEmpty(const Stack& stack);
void Clear(Stack& stack);

#endif
