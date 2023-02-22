#include "Stack.h"

Stack Create()
{
	Stack stack = { 0, { } };
	return stack;
}

bool Push(Stack& stack, char value)
{
	if (stack.count == STACK_CAPACITY)
		return false;

	stack.values[stack.count] = value;
	++stack.count;

	return true;
}

char Pop(Stack& stack)
{
	if (IsEmpty(stack))
		return '\0';

	--stack.count;
	char top = stack.values[stack.count];
	stack.values[stack.count] = '\0';

	return top;
}

char Top(const Stack& stack)
{
	return IsEmpty(stack) ? '\0' : stack.values[stack.count - 1];
}

int Size(const Stack& stack)
{
	return sizeof(stack.values) / sizeof(stack.values[0]);
}

int Count(const Stack& stack)
{
	return stack.count;
}

bool IsEmpty(const Stack& stack)
{
	return stack.count == 0;
}

void Clear(Stack& stack)
{
	while (!IsEmpty(stack))
	{
		Pop(stack);
	}
}
